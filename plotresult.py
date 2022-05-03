import matplotlib.pyplot as plt
import numpy as np
import os,math
n=[]
time=[]
os.chdir('D:/algorithm/hw4')
with open("./result.txt",'r')as f:
    lines=f.readlines()
    for line in lines:
        tmp=line.split()
        n.append(tmp[0])
        time.append((tmp[1]) )
    for val in n :
        print(val)
    for vall in time:
        print(vall)
plt.xlabel('# of items')
plt.ylabel('Time Complexity')
plt.plot(n,time, label ='bruteforce')
plt.grid()
plt.show()