from django.core.exceptions import ValidationError
from django.views.decorators.csrf import csrf_protect
from django.views.decorators.http import require_POST
from django.shortcuts import redirect
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status
from .models import GameStats
from urllib.parse import urlencode
from dotenv import load_dotenv
from web3 import Web3
import requests
import os
import re

load_dotenv()

@csrf_protect
@require_POST
@api_view(['POST'])
def auth(request):
    code = request.data.get('code')
    token_url = "https://api.intra.42.fr/oauth/token"
    token_data = {
        'grant_type': 'authorization_code',
        'client_id': os.environ.get('CLIENT_ID'),
        'client_secret': os.environ.get('CLIENT_SECRET'),
        'code': code,
        'redirect_uri': os.environ.get('REDIRECT_UNSLASH')
    }

    # URL encode the data
    encoded_data = urlencode(token_data)

    headers = {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Accept': 'application/json',
        'User-Agent': 'PONG-SPA'
    }

    # Récupération du token
    token_response = requests.post(
        token_url,
        data=encoded_data,
        headers=headers
    )

    if token_response.status_code != 200:
        return Response(
            {'error': 'Échec de récupération du token'},
            status=status.HTTP_400_BAD_REQUEST
        )

    token_data = token_response.json()
    access_token = token_data.get('access_token')

    if not access_token:
        return Response(
            {'error': 'Token d\'accès manquant dans la réponse'},
            status=status.HTTP_400_BAD_REQUEST
        )

    # Récupération des informations utilisateur
    user_info_url = "https://api.intra.42.fr/v2/me"
    user_headers = {
        'Authorization': f'Bearer {access_token}',
        'Accept': 'application/json',
        'User-Agent': 'PONG-SPA'
    }

    user_response = requests.get(user_info_url, headers=user_headers)

    if user_response.status_code != 200:
        return Response(
            {'error': 'Impossible de récupérer les informations utilisateur'},
            status=status.HTTP_400_BAD_REQUEST
        )

    user_data = user_response.json()

    # Extraire les informations pertinentes de l'utilisateur
    user_info = {
        'id': user_data.get('id'),
        'login': user_data.get('login'),
        'email': user_data.get('email'),
        'image_url': user_data.get('image', {}).get('link'),
        'first_name': user_data.get('first_name'),
        'last_name': user_data.get('last_name')
    }

    response = Response(user_info)

    # Définir un cookie HTTP-Only sécurisé:
    response.set_cookie(
        'access_token',
        access_token,
        httponly=True,        # JavaScript ne peut pas y accéder
        secure=True,          # Uniquement sur HTTPS
        samesite='Lax',       # Protection CSRF
        max_age=3600,         # Durée de vie en secondes
        path='/'              # Accessible sur tout le site
    )

    return response

@csrf_protect
@require_POST
@api_view(['POST'])
def dash(request):
    try:
        stats = request.data.get('stats')
        if not stats:
            return Response(
                {'error': 'No stats data provided'},
                status=status.HTTP_400_BAD_REQUEST
            )

        # Validate required fields
        required_fields = ['user', 'score', 'user2', 'score2', 'user3', 'score3', 'mode', 'options']
        missing_fields = [field for field in required_fields if field not in stats]

        if missing_fields:
            return Response(
                {'error': f'Missing required fields: {", ".join(missing_fields)}'},
                status=status.HTTP_400_BAD_REQUEST
            )

        # Create the GameStats object
        game_stats = GameStats.objects.create(
            user=stats['user'],
            score=stats['score'],
            user2=stats['user2'],
            score2=stats['score2'],
            user3=stats['user3'],
            score3=stats['score3'],
            mode=stats['mode'],
            options=stats['options']
        )

        # Return the created object data
        return Response({
            'message': 'Game stats saved successfully',
            'id': game_stats.id,
            'created_at': game_stats.created_at
        }, status=status.HTTP_201_CREATED)

    except ValidationError as e:
        return Response(
            {'error': str(e)},
            status=status.HTTP_400_BAD_REQUEST
        )
    except Exception as e:
        return Response(
            {'error': 'An error occurred while saving game stats'},
            status=status.HTTP_500_INTERNAL_SERVER_ERROR
        )

@csrf_protect
@require_POST
@api_view(['POST'])
def logout(request):
    response = Response({'status': 'logged out'})
    response.delete_cookie('access_token')
    return response


@csrf_protect
@require_POST
@api_view(['POST'])
def validate(request):
    try:
        data = request.data
        errors = []
        validated_data = {}

        if data.get('mode') not in ['bot', 'human', 'tourn']:
            errors.append("Mode de jeu invalide")
        else:
            validated_data['mode'] = data.get('mode')

        player_fields = []
        if data.get('mode') == 'human':
            player_fields = ['p1', 'p2']
        elif data.get('mode') == 'tourn':
            player_fields = ['p1', 'p2', 'p3']

        for field in player_fields:
            if field in data and data[field]:
                sanitized_name = re.sub(r'[^\w\s-]', '', data[field])[:10]
                if not sanitized_name:
                    errors.append(f"Nom du joueur {field} invalide")
                else:
                    validated_data[field] = sanitized_name
            else:
                errors.append(f"Nom du joueur {field} requis")

        player_names = [validated_data[field] for field in player_fields if field in validated_data]
        if len(player_names) != len(set(player_names)):
            errors.append("Les noms des joueurs doivent être uniques")

        game_params = ['bspeed', 'bsize', 'pheight', 'pspeed']
        for param in game_params:
            if param in data:
                try:
                    value = int(data[param])
                    if value not in [0, 25, 50, 75, 100]:
                        errors.append(f"Valeur invalide pour {param}")
                    else:
                        validated_data[param] = value
                except (ValueError, TypeError):
                    errors.append(f"Valeur invalide pour {param}")
            else:
                validated_data[param] = 50  # Valeur par défaut

        validated_data['spacewars'] = bool(data.get('spacewars'))

        if errors:
            return Response({'valid': False, 'errors': errors}, status=status.HTTP_400_BAD_REQUEST)
        else:
            return Response({'valid': True, 'validated_data': validated_data}, status=status.HTTP_200_OK)

    except Exception as e:
        return Response({'valid': False, 'errors': [str(e)]}, status=status.HTTP_400_BAD_REQUEST)