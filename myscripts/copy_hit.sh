#!/bin/bash
dir=/home/scratch/rchai/GTX480_16/
des=~/gpu/hit
if [ ! -d "$des" ]; then
	mkdir "$des"
fi
echo "$dir"; echo "$des"
#cd "$des"
if [ ! -d "$des"/CUDA ]; then
	mkdir "$des"/CUDA
fi
if [ ! -d "$des"/polybench ]; then
	mkdir "$des"/polybench
fi
echo 'Preparation Done.'
for i in SLA TRA CONS FWT BlackScholes LPS SCP; do
	if [ ! -d "$des"/CUDA/"$i" ]; then
		mkdir "$des"/CUDA/"$i"
	fi
	cp "$dir""CUDA"/"$i"/hit.txt "$des"/CUDA/"$i"/
done
echo 'CUDA done.'
#cd ../polybench
for i in 2DCONV 3MM FDTD-2D GEMM 3DCONV ATAX BICG SYR2K SYRK GESUMMV GRAMSCHM MVT 2MM; do
	if [ ! -d "$des"/polybench/"$i" ]; then
		mkdir "$des"/polybench/"$i"
	fi
	cp "$dir""polybench"/"$i"/hit.txt "$des"/polybench/"$i"/
done
echo 'polybench Done.'
echo 'copy hit.txt Done.'

