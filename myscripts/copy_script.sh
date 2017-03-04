#!/bin/bash
dir=$HOME/Desktop/710/plot
des=$HOME/Desktop/result
for i in "$des"/*/*; do
	if [ -e "$i"/hit.txt ]; then
		cp "$dir"/chip0plot.cpp "$i"
		cp "$dir"/barplot.py "$i"
	else
		echo "$i: hit.txt doesn't exist!"
	fi
done
echo 'copy Done.'
