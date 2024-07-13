#!/bin/bash

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress

echo "***Installing WordPress***"
find /var/www/wordpress/ -mindepth 1 -delete
wp core download --allow-root --path="/var/www/wordpress"
sleep 6
wp core config --dbhost=mariadb:3306 --dbname="$DATABASE" --dbuser="$ADMIN" --dbpass="$ADM_PASSWORD" --allow-root --path="/var/www/wordpress"
wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$ADMIN" --admin_password="$ADM_PASSWORD" --admin_email="$ADM_EMAIL" --allow-root --path="/var/www/wordpress"
wp user create "$WP_USER" "$WP_EMAIL" --user_pass="$WP_PASSWORD" --role=author --allow-root --path="/var/www/wordpress"

sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf
mkdir -p /run/php
/usr/sbin/php-fpm7.4 -F