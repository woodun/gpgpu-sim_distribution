"""
Author: David Chai
Email: rchai@email.wm.edu
Python Version: python3.5
This script is used to read the data from text files and bar plot.
"""
import matplotlib as mpl
mpl.use('agg')
import numpy as np
import matplotlib.pyplot as plt
import os

# ***********************stats maipulation***********************

hit=[([]*7) for i in range(17)]
percent=[([]*6) for i in range(17)]
#print (hit[1][5])

c=0 # as counter
with open("numbers.txt") as number:
	for line in number:
		hit[c]=[int(n) for n in line.split()]
		c+=1
# print(hit)
c=0 # initialize again
with open("percent.txt") as pp:
	for line in pp:
		percent[c]=[float(n) for n in line.split()]
		c+=1
print(percent)

# ***********************start plotting***********************
bank=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
x=['1','2','3','4','5','>=6']
y=percent
for i in range(17):
	for j in range(6):
		y[i][j]*=100

bar_width = 0.05

index = np.arange(len(y[0]))
ax=plt.subplot(111)

a1=ax.bar(index,y[0],bar_width,color='b',label='bank0')
a2=ax.bar(index+bar_width,y[1],bar_width,color='cyan',label='bank1')
a3=ax.bar(index+2*bar_width,y[2],bar_width,color='lime',label='bank2')
a4=ax.bar(index+3*bar_width,y[3],bar_width,color='yellow',label='bank3')
a5=ax.bar(index+4*bar_width,y[4],bar_width,color='lightsalmon',label='bank4')
a6=ax.bar(index+5*bar_width,y[5],bar_width,color='r',label='bank5')
a7=ax.bar(index+6*bar_width,y[6],bar_width,color='k',label='bank6')
a8=ax.bar(index+7*bar_width,y[7],bar_width,color='pink',label='bank7')
a9=ax.bar(index+8*bar_width,y[8],bar_width,color='blueviolet',label='bank8')
a10=ax.bar(index+9*bar_width,y[9],bar_width,color='aqua',label='bank9')
a11=ax.bar(index+10*bar_width,y[10],bar_width,color='wheat',label='bank10')
a12=ax.bar(index+11*bar_width,y[11],bar_width,color='darkred',label='bank11')
a13=ax.bar(index+12*bar_width,y[12],bar_width,color='crimson',label='bank12')
a14=ax.bar(index+13*bar_width,y[13],bar_width,color='c',label='bank13')
a15=ax.bar(index+14*bar_width,y[14],bar_width,color='olive',label='bank14')
a16=ax.bar(index+15*bar_width,y[15],bar_width,color='grey',label='bank15')
# a3=plt.bar(index+2*bar_width,y[2],bar_width)


# xlabel
plt.xticks(index + 8*bar_width, x)
plt.xlabel('Hit Times')
plt.ylabel('Percentage of DRAM Hit')
# y range
plt.ylim(ymax=100, ymin=0)
# graph title
plt.title('DRAM Bank Hit Bar Statistics')
# legend configuration
ax.legend(loc=1, prop={'size':9},fancybox=True, ncol=4)

# output to the current directory
plt.savefig('general.png')