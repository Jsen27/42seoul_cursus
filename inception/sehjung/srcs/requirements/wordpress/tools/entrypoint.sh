#!/bin/sh

if [ ! -d "/var/www/html/wp" ]; then

    chown nginx:nginx -R /var/www/html/*
    find /var/www/html -type d -exec chmod 777 {} \;
    find /var/www/html -type f -exec chmod 777 {} \;

    mkdir -p /var/www/html/
    wget https://wordpress.org/wordpress-6.2.tar.gz
    tar -zxf wordpress-6.2.tar.gz
    rm wordpress-6.2.tar.gz
    mv wordpress /var/www/html/wp

    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/bin/wp

    # WORDPRESS conf
    echo -e "<?php 
    define( 'DB_NAME', '${MYSQL_DATABASE}' ); \
    define( 'DB_USER', '${MYSQL_ADMIN_USER}' ); \
    define( 'DB_PASSWORD', '${MYSQL_ADMIN_PASSWORD}' ); \n$(cat /wp-config.php)" > /wp-config.php
    mv /wp-config.php /var/www/html/wp

    # WP INSTALL with WP CLI
    wp core install --path='/var/www/html/wp' \
        --url=${WP_USER_NAME}.42.fr/ --title="inception" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_USER}@42.fr --skip-email
    wp user create --path='/var/www/html/wp' \
        ${WP_USER_NAME} ${WP_USER_NAME}@42.fr \
        --user_pass=${WP_USER_PASSWORD} \
        --role=editor
    chown nginx:nginx -R /var/www/html/*
    find /var/www/html -type d -exec chmod 777 {} \;
    find /var/www/html -type f -exec chmod 777 {} \;
fi

# RUN PHP FAST CGI
php-fpm8 -F