NAME = inception

SRC_DIR = ./srcs

DOCKER_COMPOSE_FILE = $(SRC_DIR)/docker-compose.yaml

DOCKER_COMPOSE = sudo docker-compose -f $(DOCKER_COMPOSE_FILE)

VOLUME_MOUNTPOINT = /home/sehjung/data

$(NAME) : all

all : up

clean : stop
	rm -rf $(VOLUME_MOUNTPOINT)
	docker rm $$(docker ps -qa); \
	docker rmi -f $$(docker images -qa); \
	docker volume rm $$(docker volume ls -q) || \
	docker network rm $$(docker network ls -q) ||\
	echo "clean up"

re : clean
	docker pull alpine:3.16.5
	mkdir -p $(VOLUME_MOUNTPOINT)/mariadb $(VOLUME_MOUNTPOINT)/wordpress
	$(DOCKER_COMPOSE) build --no-cache
	$(DOCKER_COMPOSE) up -d

up :
	docker pull alpine:3.16.5
	mkdir -p $(VOLUME_MOUNTPOINT)/mariadb $(VOLUME_MOUNTPOINT)/wordpress
	$(DOCKER_COMPOSE) up -d --build

down :
	$(DOCKER_COMPOSE) down

start :
	$(DOCKER_COMPOSE) start

restart :
	$(DOCKER_COMPOSE) restart

stop :
	$(DOCKER_COMPOSE) stop

.PHONY: all clean re up down start restart stop
