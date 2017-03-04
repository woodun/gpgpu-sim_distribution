#!/bin/bash
echo 'The current folder is: '; pwd
cd CUDA
for i in SLA TRA CONS FWT BlackScholes LPS SCP; do
	cd "$i"
	if [ -e output* ]; then
		echo "$i: $(cat output* | grep "average row locality" | tail -1 | grep -Eo "[0-9]*\.[0-9]*")"
	else
		echo "$i: File Doesn't Exist!!!"
	fi
	cd ..
done
cd ../polybench
for i in 2DCONV 3MM FDTD-2D GEMM 3DCONV ATAX BICG SYR2K SYRK GESUMMV GRAMSCHM MVT 2MM; do
	cd "$i"
	if [ -e output* ]; then
		echo "$i: $(cat output* | grep "average row locality" | tail -1 | grep -Eo "[0-9]*\.[0-9]*")"
	else
		echo "$i: File Doesn't Exist!!!"
	fi
	cd ..
done
echo 'All files read. Please see the terminal!'
