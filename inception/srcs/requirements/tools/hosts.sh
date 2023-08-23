#!/bin/bash

conf=$($(pwd)/srcs/requirements/tools/info.sh conf)
hosts_path=$($(pwd)/srcs/requirements/tools/info.sh hosts_path)

if [ ! -e ${hosts_path} ]; then
    touch ${hosts_path}
fi

LINE_cnt=$(cat ${hosts_path} | grep -x "${conf}" | wc -l)

if [ ${LINE_cnt} -eq 0 ]; then
    echo ${conf} >> ${hosts_path}
fi

LINE_cnt=$(cat ${hosts_path} | grep -x "${conf}" | wc -l)

if [ ${LINE_cnt} -eq 0 ]; then
    echo "@${hosts_path} is invalid" 1>&2
else
    echo "@${hosts_path} is ready"
fi
