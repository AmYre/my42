FROM python:3.9-slim

RUN apt-get update && apt-get install -y \
	postgresql-client \
	gcc \
	netcat-openbsd \
	python3-dev \
	libpq-dev \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY requirements.txt /app/
RUN pip install -r requirements.txt

RUN pip install django-browser-reload

COPY . /app/

COPY entrypoint.sh /app/
RUN chmod +x /app/entrypoint.sh

EXPOSE 8443

CMD ["sh", "/app/entrypoint.sh"]