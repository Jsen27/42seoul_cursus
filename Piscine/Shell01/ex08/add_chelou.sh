#!/bin/bash
echo $FT_NBR1+$FT_NBR2 | tr "\'" '0' | tr "\\" '1' | tr "\"" "2" | tr "?" "3" | tr "\!" "4" | tr "m" "0" | tr "r" "1" | tr "d" "2" | tr "o" "3" | tr "c" "4" | xargs echo "obase=13; ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
