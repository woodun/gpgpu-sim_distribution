The plot folder has 2 sub-directories. "First Version" is the raw plot of a hit.txt without knowing for which mem_chip. "Final Version" is the refined plot scripts to draw all the banks for 6 memory chips.

If you want to use the plot script, please copy the three files into the folder containing "hit.txt", like:

\# Do copy...
cd my_hit.txt_path

\# Then run:
g++ allchipstat.cpp
./a.out
Here you can see the numbers.txt and percent.txt of the 6 chips. Then you have 2 choices, the first one is to run "python3 single_chip_plot.py" plus a number n from 1-6, representing you're going to plot the nth chip bank hit stats(for example, run: python3 single_chip_plot.py 3, and you will get the chip#3 bank hit plots.). Or you can just run "./plot_all.sh" and you can get all the six chips plots in the current folder.

All the plots after running the program will be seen in the current folder. Have fun!
