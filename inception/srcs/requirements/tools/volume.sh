#!/bin/bash

#info.sh에 설정되어 있는 환경변수 wordpress_path를 사용합니다.
wordpress_path=$($(pwd)/srcs/requirements/tools/info.sh wordpress_path)
#info.sh에 설정되어 있는 환경변수 wordpress_path를 사용합니다.
mariadb_path=$($(pwd)/srcs/requirements/tools/info.sh mariadb_path)

if [ ! -d ${wordpress_path} ]; then
    mkdir -p ${wordpress_path}
fi
if [ ! -d ${mariadb_path} ]; then
    mkdir -p ${mariadb_path}
fi

if [ -d ${wordpress_path} ] && [ -d ${mariadb_path} ]; then

    echo "${wordpress_path} ready, ${mariadb_path} ready"
else
    echo "volume error" 1>&2
fi
