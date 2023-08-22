#!/bin/sh

if [ ! -d "/var/www/html/$MYSQL_DATABASE" ]; theni
    echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;" > init.sql
    echo "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' ;" >> init.sql
    echo "CREATE USER IF NOT EXISTS '$MYSQL_ADMIN_USER'@'%' IDENTIFIED BY '$MYSQL_ADMIN_PASSWORD';" >> init.sql
    echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' ;" >> init.sql
    echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD' ;" >> init.sql
    echo "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_ADMIN_USER'@'%' IDENTIFIED BY '$MYSQL_ADMIN_PASSWORD' WITH GRANT OPTION;" >> init.sql
    echo "GRANT SELECT, CREATE, INSERT, UPDATE, DELETE ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';" >> init.sql
    echo "FLUSH PRIVILEGES ;" >> init.sql
fi

mysql_install_db --auth-root-authentication-method=normal
mysqld
