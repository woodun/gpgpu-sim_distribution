#!/bin/bash
for i in {1..6}; do
	python3 single_chip_plot.py "$i"
done
echo 'All 6 plots done.'
