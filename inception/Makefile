DC := sudo docker-compose -f srcs/docker-compose.yml

all:
	@mkdir -p /home/amben-ha/data/db
	@mkdir -p /home/amben-ha/data/wp
	@docker ps -q | grep . || $(DC) up --buil -d

stop:
	$(DC) stop

start:
	$(DC) start

down:
	$(DC) down

clean:
	$(DC) down --rmi all --volumes

fclean:
	sudo docker system prune -a --volumes
	sudo rm -rf /home/amben-ha/data

re: fclean all

logs:
	$(DC) logs

help:
	@echo "Utilisez 'make all' pour construire et démarrer les services."
	@echo "Utilisez 'make build' pour construire les services."
	@echo "Utilisez 'make up' pour lancer les services en arrière-plan."
	@echo "Utilisez 'make down' pour arrêter les services."
	@echo "Utilisez 'make clean' pour arrêter et supprimer les conteneurs, réseaux, images, et volumes."
	@echo "Utilisez 'make fclean' pour un nettoyage complet, y compris les volumes non anonymes."
	@echo "Utilisez 'make re' pour reconstruire et redémarrer les services."
	@echo "Utilisez 'make logs' pour afficher les logs des services."