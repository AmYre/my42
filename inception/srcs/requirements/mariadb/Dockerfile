FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

RUN apt-get install mariadb-server -y

COPY ./conf/mariadb.sh /mariadb.sh

RUN chmod +x /mariadb.sh

ENTRYPOINT ["./mariadb.sh"]