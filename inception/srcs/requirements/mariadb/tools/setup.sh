#!/bin/sh

if [ ! -d "/var/lib/mysql/$MYSQL_DB" ]; then
  mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal >/dev/null
  mysqld --bootstrap << EOF
use mysql;

flush privileges;

create database $MYSQL_DB;
create user '$MYSQL_USER'@'%' identified by '$MYSQL_PASSWORD';
grant all privileges on $MYSQL_DB.* to '$MYSQL_USER'@'%';

alter user '$MYSQL_ROOT'@'localhost' identified by '$MYSQL_ROOT_PASSWORD';

flush privileges;
EOF
fi

echo "mariadb ready, port is 3306"

exec mysqld --datadir=/var/lib/mysql
