DC=docker-compose
APP=pong

all: up

build:
	$(DC) build

# add -d before set as finished
up:
	$(DC) up --build -d

stop:
	$(DC) stop

start:
	$(DC) start

down:
	$(DC) down --remove-orphans

admin:
	$(DC) exec $(APP) python manage.py createsuperuser

logs:
	$(DC) logs -f $(APP)

migrate:
	$(DC) exec $(APP) python manage.py makemigrations $(APP)
	$(DC) exec $(APP) python manage.py migrate

clean:
	$(DC) down -v
	find . -type d -name "__pycache__" -exec rm -r {} +
	find . -type f -name "*.pyc" -delete

fclean: clean
	docker system prune -a -f --volumes

re: fclean all

.PHONY: build up down logs migrate clean fclean

# Makefile error 130 is normal - exit code for quitting with ctrl+c signal
# added -d to up rule so containers run in detached mode - background - less verbose/ less error messages (take away -d for developing and debugging)
# use make stop or make down to pause or remove containers (instead of quitting with ctrl+c previously)
# exec not needed for rules with commands run outside of containers
# admin and migrate rules run inside running containers so exec is needed