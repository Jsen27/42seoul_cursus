FROM debian:buster

EXPOSE 3306

COPY ./tools/install.sh /install.sh

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server mariadb-client && \
    mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod +x install.sh && \
    rm -f /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

ENTRYPOINT ["sh", "/install.sh"]
