#!/bin/bash
des=$HOME/Desktop/result
for i in "$des"/*/*; do
	if [ -e "$i"/hit.txt ]; then
		cd "$i"
		g++ chip0plot.cpp
		./a.out
		python3 barplot.py
	fi
done
echo ' Done.'
