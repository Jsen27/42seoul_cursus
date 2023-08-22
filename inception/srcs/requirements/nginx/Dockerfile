FROM debian:buster

EXPOSE 443

COPY ./tools/setup.sh /setup.sh

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y nginx openssl && \
    mkdir -p /etc/ssl && \
    chmod +x setup.sh

COPY conf/default.conf /etc/nginx/conf.d/default.conf

ENTRYPOINT ["sh", "/setup.sh"]
