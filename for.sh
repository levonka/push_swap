#!/bin/bash

x=$1

for (( i=1; i <= $x; i++ ))
do
    echo ">>>>> $i <<<<<"
	./script.sh 1 $i 3
done
