#!/bin/bash

wordpress_path=$($(pwd)/srcs/requirements/tools/info.sh wordpress_path)
mariadb_path=$($(pwd)/srcs/requirements/tools/info.sh mariadb_path)
conf=$($(pwd)/srcs/requirements/tools/info.sh conf)
hosts_path=$($(pwd)/srcs/requirements/tools/info.sh hosts_path)

rm -rf ${wordpress_path}
rm -rf ${mariadb_path}

sed -i "/${conf}/d" ${hosts_path}

echo "fclean"
