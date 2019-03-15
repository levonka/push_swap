#!/bin/bash

start=$1
end=$2
x=$3

#rm log

for (( i=1; i <= $x; i++ ))
do
	ARG=`ruby -e "puts ($start..$end).to_a.shuffle.join(' ')"`
#	echo $ARG
#	echo $ARG >> log
#	./push_swap $ARG >> log
	./push_swap $ARG > log.txt
	cat log.txt | ./checker $ARG
done
