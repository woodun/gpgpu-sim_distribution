#!/bin/bash
src=$HOME/Desktop
dir=$HOME/Desktop/result_16
for i in "$dir"/*/*; do
	if [ -d "$i" ]; then
		cd "$i"
		cp "$src"/allchipstat.cpp ./
		cp "$src"/plot_all.sh ./
		cp "$src"/single_chip_plot.py ./
		g++ allchipstat.cpp
		./a.out
		./plot_all.sh
		echo "$i Done."
		cd ../../
	fi
done