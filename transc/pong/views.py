from django.shortcuts import render
from django.shortcuts import redirect
from dotenv import load_dotenv
from .models import GameStats
import urllib.parse
import os
load_dotenv()

# Create your views here.
def home(request):
	client_id = os.environ.get('CLIENT_ID')
	redirect_uri = os.environ.get('REDIRECT_UNSLASH')

	# Fix: Encode the redirect_uri properly
	encoded_redirect = urllib.parse.quote(str(redirect_uri).encode('utf-8'))

	auth_url = (
		f"https://api.intra.42.fr/oauth/authorize?"
		f"client_id={client_id}&"
		f"redirect_uri={encoded_redirect}&"
		f"response_type=code"
	)

	context = {
		'auth_url': auth_url
	}
	return render(request, 'home.html', context)

def calculate_radar_values(user_games):
    radar_data = {
        'Speed': 0,        # Average ball speed
        'Attack': 0,       # Average winning margin
        'Defense': 0,      # Average closeness when losing
        'War': 0,          # SpaceWars usage percentage
        'Accuracy': 0,     # Inverse paddle height average
        'Madness': 0       # Extreme options usage
    }

    # Counters for averages
    total_games = len(user_games)
    if total_games == 0:
        return radar_data

    # Counters for specific stats
    speed_sum = 0
    speed_count = 0

    attack_sum = 0
    attack_count = 0

    defense_sum = 0
    defense_count = 0

    spacewars_count = 0
    spacewars_total = 0

    accuracy_sum = 0
    accuracy_count = 0

    madness_sum = 0
    madness_options_total = 0

    # Define extreme options for madness calculation
    extreme_options = {
        'pheight': ['0', '100'],   # Crazy, Why?
        'pspeed': ['0', '100'],    # Painful, Flash
        'bspeed': ['0', '100'],    # Boring, Lightning
        'bsize': ['0', '100']      # Quantic, Cosmic
    }

    # Collect data from each game
    for game in user_games:
        # SPEED - Calculate average ball speed
        if game.options and 'bspeed' in game.options:
            speed_sum += int(game.options['bspeed'])
            speed_count += 1

        # ATTACK - Calculate attack rating based on winning margin
        if game.mode in ['bot', 'human']:
            if game.score > game.score2:  # Won the game
                # Calculate winning margin percentage (5-0 is 100%, 5-4 is 20%)
                margin = game.score - game.score2
                max_possible_margin = 5  # Assuming max score is 5
                attack_rating = (margin / max_possible_margin) * 100
                attack_sum += attack_rating
                attack_count += 1
        elif game.mode == 'tourn':
            if game.score > 0:  # Scored points in tournament
                # In tournament, having 2 points is 100%, 1 point is 50%
                attack_rating = (game.score / 2) * 100
                attack_sum += attack_rating
                attack_count += 1

        # DEFENSE - Calculate defense rating based on losing margin
        if game.mode in ['bot', 'human'] and game.score < game.score2:
            # Calculate how close the loss was (4-5 is 100%, 0-5 is 0%)
            max_possible_deficit = 5  # Assuming max score is 5
            actual_deficit = game.score2 - game.score
            if actual_deficit > 0:
                # Invert the scale: smaller deficit = better defense
                defense_rating = ((max_possible_deficit - actual_deficit) / max_possible_deficit) * 100
                defense_sum += defense_rating
                defense_count += 1

        # WAR - Calculate SpaceWars usage
        # Count every game
        spacewars_total += 1

        # Check if spacewars exists in options
        if game.options and 'spacewars' in game.options:
            if game.options['spacewars'] == True or game.options['spacewars'] == 'on':
                spacewars_count += 1

        # ACCURACY - Calculate paddle height usage (inverse scale)
        if game.options and 'pheight' in game.options:
            pheight_value = int(game.options['pheight'])
            # Invert the scale: 0 = 100%, 100 = 0%
            accuracy_rating = 100 - pheight_value
            accuracy_sum += accuracy_rating
            accuracy_count += 1

        # MADNESS - Calculate extreme options usage
        if game.options:
            options_in_game = 0
            extreme_options_in_game = 0

            for option_key, extreme_values in extreme_options.items():
                if option_key in game.options:
                    options_in_game += 1
                    if game.options[option_key] in extreme_values:
                        extreme_options_in_game += 1

            if options_in_game > 0:
                madness_options_total += options_in_game
                madness_sum += extreme_options_in_game

    # Calculate final averages
    if speed_count > 0:
        radar_data['Speed'] = speed_sum / speed_count

    if attack_count > 0:
        radar_data['Attack'] = attack_sum / attack_count

    if defense_count > 0:
        radar_data['Defense'] = defense_sum / defense_count

    if spacewars_total > 0:
        radar_data['War'] = (spacewars_count / spacewars_total) * 100

    if accuracy_count > 0:
        radar_data['Accuracy'] = accuracy_sum / accuracy_count

    if madness_options_total > 0:
        radar_data['Madness'] = (madness_sum / madness_options_total) * 100

    return radar_data

def dashboard(request):
    if not request.COOKIES.get('access_token'):
        return redirect('/')
    option_labels = {
        'pspeed': {
            '0': 'Painful',
            '25': 'Slow',
            '50': 'Normal',
            '75': 'Quick',
            '100': 'Flash'
        },
        'pheight': {
            '0': 'Crazy',
            '25': 'Small',
            '50': 'Normal',
            '75': 'Big',
            '100': 'Why?'
        },
        'bspeed': {
            '0': 'Boring',
            '25': 'Slow',
            '50': 'Normal',
            '75': 'Quick',
            '100': 'Lightning'
        },
        'bsize': {
            '0': 'Quantic',
            '25': 'Small',
            '50': 'Normal',
            '75': 'Big',
            '100': 'Cosmic'
        },
        'spacewars': {
            'on': 'Enabled',
            'off': 'Disabled'
        }
    }

    # Function to get human-readable option text
    def get_readable_option(key, value):
        if key in option_labels and value in option_labels[key]:
            return f"{key}:{option_labels[key][value]}"
        return f"{key}:{value}"
    user = request.GET.get('user')
    game_stats = GameStats.objects.all()

    # Handle filtering games for the current user
    if user:
        user_games = game_stats.filter(user=user)
    else:
        # If no user specified, include all games
        user_games = game_stats

    botCount = game_stats.filter(mode='bot').count()
    humanCount = game_stats.filter(mode='human').count()
    tournCount = game_stats.filter(mode='tourn').count()

    # Initialize counters for wins, losses, draws
    wins = 0
    losses = 0
    draws = 0
    total_games = 0

    # Track options statistics
    option_stats = {}
    # Track opponent statistics
    opponent_stats = {}

    # Count wins, losses, and draws for the user
    for game in user_games:
        total_games += 1

        # Track game result
        game_result = None

        if game.mode == 'bot' or game.mode == 'human':
            # In bot/human modes, compare user score with user2 score
            if game.score > game.score2:
                wins += 1
                game_result = 'win'
            elif game.score < game.score2:
                losses += 1
                game_result = 'loss'
            else:
                draws += 1
                game_result = 'draw'

            # Track opponent statistics
            if game.mode == 'bot':
                # Use "Bot" as the opponent name for bot games
                opponent = "Bot"
                if opponent not in opponent_stats:
                    opponent_stats[opponent] = {'played': 0, 'beaten': 0}
                opponent_stats[opponent]['played'] += 1
                if game_result == 'win':
                    opponent_stats[opponent]['beaten'] += 1
            elif game.user2 != 'none':
                # For human games, use the actual opponent's username
                if game.user2 not in opponent_stats:
                    opponent_stats[game.user2] = {'played': 0, 'beaten': 0}
                opponent_stats[game.user2]['played'] += 1
                if game_result == 'win':
                    opponent_stats[game.user2]['beaten'] += 1

        elif game.mode == 'tourn':
            # In tournament mode, compare user score with both user2 and user3
            user_score = game.score
            other_scores = [game.score2, game.score3]
            other_users = [game.user2, game.user3]

            # If user's score is higher than all others, it's a win
            if user_score > max(other_scores):
                wins += 1
                game_result = 'win'
            # If user's score is lower than any other score, it's a loss
            elif user_score < max(other_scores):
                losses += 1
                game_result = 'loss'
            # Otherwise it's a draw (equal highest score)
            else:
                draws += 1
                game_result = 'draw'

            # Track opponent statistics
            for opp in [game.user2, game.user3]:
                if opp != 'none':
                    if opp not in opponent_stats:
                        opponent_stats[opp] = {'played': 0, 'beaten': 0}
                    opponent_stats[opp]['played'] += 1
                    if game_result == 'win':
                        opponent_stats[opp]['beaten'] += 1

        # Track option statistics if options exist
        if game.options:
            for key, value in game.options.items():
                # Create a readable version of the option key
                readable_key = get_readable_option(key, value)

                if readable_key not in option_stats:
                    option_stats[readable_key] = {
                        'played': 0,
                        'wins': 0,
                        'losses': 0,
                        'draws': 0,
                        'success_rate': 0
                    }
                option_stats[readable_key]['played'] += 1
                if game_result == 'win':
                    option_stats[readable_key]['wins'] += 1
                elif game_result == 'loss':
                    option_stats[readable_key]['losses'] += 1
                elif game_result == 'draw':
                    option_stats[readable_key]['draws'] += 1

    # Calculate success rates for options
    for option, stats in option_stats.items():
        if stats['played'] > 0:
            stats['success_rate'] = (stats['wins'] / stats['played']) * 100

    # Find most played option
    most_played_option = None
    most_played_count = 0
    for option, stats in option_stats.items():
        if stats['played'] > most_played_count:
            most_played_count = stats['played']
            most_played_option = option

    # Find most successful option (min 3 games played)
    most_successful_option = None
    highest_success_rate = 0
    for option, stats in option_stats.items():
        if stats['played'] >= 3 and stats['success_rate'] > highest_success_rate:
            highest_success_rate = stats['success_rate']
            most_successful_option = option

    # Find least successful option (min 3 games played)
    least_successful_option = None
    lowest_success_rate = 100
    for option, stats in option_stats.items():
        if stats['played'] >= 3 and stats['success_rate'] < lowest_success_rate:
            lowest_success_rate = stats['success_rate']
            least_successful_option = option

    # Find most played opponent
    most_played_opponent = None
    most_played_opponent_count = 0

    for opponent, stats in opponent_stats.items():
        if stats['played'] > most_played_opponent_count:
            most_played_opponent_count = stats['played']
            most_played_opponent = opponent

    # Find most beaten opponent
    most_beaten_opponent = None
    most_beaten_count = 0
    for opponent, stats in opponent_stats.items():
        if stats['beaten'] > most_beaten_count:
            most_beaten_count = stats['beaten']
            most_beaten_opponent = opponent

    # Calculate percentages
    if total_games > 0:
        win_percentage = (wins / total_games) * 100
        loss_percentage = (losses / total_games) * 100
        draw_percentage = (draws / total_games) * 100
    else:
        win_percentage = 0
        loss_percentage = 0
        draw_percentage = 0

    # Prepare basic stats dictionary
    if (botCount+humanCount+tournCount) == 0:
        stats = {
            'total': 0,
            'modes': {
                'bot': 0,
                'human': 0,
                'tourn': 0
            }
        }
    else:
        stats = {
            'total': game_stats.count(),
            'modes': {
                'bot': botCount/(botCount+humanCount+tournCount)*100,
                'human': humanCount/(botCount+humanCount+tournCount)*100,
                'tourn': tournCount/(botCount+humanCount+tournCount)*100
            }
        }

    # Add result statistics
    stats['results'] = {
        'wins': win_percentage,
        'losses': loss_percentage,
        'draws': draw_percentage,
        'raw_counts': {
            'wins': wins,
            'losses': losses,
            'draws': draws,
            'total_games': total_games
        }
    }

    # Add option and opponent statistics
    stats['options'] = {
        'most_played': most_played_option if most_played_option else "N/A",
        'most_successful': most_successful_option if most_successful_option else "N/A",
        'least_successful': least_successful_option if least_successful_option else "N/A",
        'details': option_stats
    }

    # Make opponent stats available directly in the main stats dictionary
    stats['most_played_opponent'] = most_played_opponent if most_played_opponent else "N/A"
    stats['most_beaten_opponent'] = most_beaten_opponent if most_beaten_opponent else "N/A"

    # Keep the detailed structure as well
    stats['opponents'] = {
        'most_played': most_played_opponent if most_played_opponent else "N/A",
        'most_beaten': most_beaten_opponent if most_beaten_opponent else "N/A",
        'details': opponent_stats
    }

    # Calculate the most popular options (original code)
    all_options = [game.options for game in game_stats if game.options]
    most_played_options = {}
    if all_options:
        for game_options in all_options:
            for key, value in game_options.items():
                if key not in most_played_options:
                    most_played_options[key] = {}
                if value not in most_played_options[key]:
                    most_played_options[key][value] = 0
                most_played_options[key][value] += 1

    most_popular = {}
    for option_type, values in most_played_options.items():
        most_popular[option_type] = max(values.items(), key=lambda x: x[1])[0]

    # Add most popular options with readable labels
    most_popular_readable = {}
    for option_type, value in most_popular.items():
        most_popular_readable[option_type] = get_readable_option(option_type, value).split(':')[1]

    stats['most_played_options'] = most_popular
    stats['most_played_options_readable'] = most_popular_readable

    # Calculate radar chart values
    radar_values = calculate_radar_values(list(user_games))

    # Add radar chart data to stats
    stats['radar_chart'] = radar_values

    # Add the complete opponent stats for direct access
    stats['opponent_stats'] = opponent_stats

    # Return both the original stats and the raw opponent data for debugging
    context = {
        'stats': stats,
        'opponent_data': opponent_stats
    }
    return render(request, 'dashboard.html', context)
