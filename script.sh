#!/bin/bash

start=$1
end=$2
x=$3

for (( i=1; i <= $x; i++ ))
do
	ARG=`ruby -e "puts ($start..$end).to_a.shuffle.join(' ')"`
	./push_swap $ARG > results/log.txt
	cat results/log.txt | ./checker $ARG | tr '\n' ' '
	# echo $ARG | tr '\n' ' '
	cat results/log.txt | wc -l
done
