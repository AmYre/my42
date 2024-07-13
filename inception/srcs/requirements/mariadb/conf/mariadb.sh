#!/bin/bash

service mariadb start
sleep 6

mariadb -e "CREATE DATABASE IF NOT EXISTS \`${DATABASE}\`;"
mariadb -e "CREATE USER IF NOT EXISTS \`${ADMIN}\`@'localhost' IDENTIFIED BY '${ADM_PASSWORD}';"
mariadb -e "GRANT ALL PRIVILEGES ON \`${DATABASE}\`.* TO \`${ADMIN}\`@'%' IDENTIFIED BY '${ADM_PASSWORD}';"
mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${ADM_PASSWORD}';"
mariadb -e "FLUSH PRIVILEGES;"

mysqladmin -u root -p$ADM_PASSWORD shutdown
mysqld_safe --port=3306 --bind-address=0.0.0.0 --socket='/run/mysqld/mysqld.sock' --user=mysql --datadir='/var/lib/mysql'