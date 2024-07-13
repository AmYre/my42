FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y php7.4 php-fpm php-mysql mariadb-client curl

COPY /conf/wordpress.sh /

RUN  chmod +x wordpress.sh

ENTRYPOINT ["./wordpress.sh"]