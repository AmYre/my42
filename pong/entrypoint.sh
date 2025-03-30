#!/bin/sh
while ! nc -z db 5432; do
  echo "Waiting for postgres..."
  sleep 1
done

echo "PostgreSQL started"

python manage.py migrate
python manage.py runsslserver 0.0.0.0:8443