#!/bin/bash
if [ -e output_*.txt ]
then
	cat output_*.txt | grep "average row locality" | tail -1 | grep -o "[0-9]*\.[0-9]*"
else
	echo "output file doesn\'t exist!!!"
fi
