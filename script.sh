#!/bin/bash

start=$1
end=$2
x=$3

#rm log

for (( i=1; i <= $x; i++ ))
do
	ARG=`ruby -e "puts ($start..$end).to_a.shuffle.join(' ')"`
	./push_swap $ARG > log.txt
	cat log.txt | ./checker $ARG | tr '\n' ' '
	# echo $ARG | tr '\n' ' '
	cat log.txt | wc -l
done
