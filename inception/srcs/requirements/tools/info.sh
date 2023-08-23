#!/bin/bash

# * 이 sh 파일은 하나의 프로그램처럼, 두번째 인자에 넣은 환경변수를 echo로 출력한다.
# * EX) sh ./info.sh intra_id  입력 시, echo intra_id 실행된다. 
# List -----
# intra_id : intra id
# wordpress_path : wordpress path for volume
# mariadb_path : mariadb path for volume
# hosts_path : /etc/hosts for local dns
# conf : /etc/hosts configuration for local dns

intra_id=sehjung

volume_path=/home/${intra_id}/data

wordpress_path=${volume_path}/wordpress
mariadb_path=${volume_path}/mariadb


hosts_path="/etc/hosts"
conf="127.0.0.1 ${intra_id}.42.fr"


if [ $# -eq 0 ]
then
    echo "NO ARGUMENTS" 1>&2
    exit 1
fi

if [ "intra_id" = $1 ]
then
    echo ${intra_id}
elif [ "wordpress_path" = $1 ]
then
    echo ${wordpress_path}
elif [ "mariadb_path" = $1 ]
then
    echo ${mariadb_path}
elif [ "hosts_path" = $1 ]
then
    echo ${hosts_path}
elif [ "conf" = $1 ]
then
    echo ${conf}
else
    echo "NOT FOUND INFO" 1>&2
fi
