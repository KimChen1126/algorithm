import matplotlib.pyplot as plt
import numpy as np
import sys
import os,math
aver=[]
ans=[]
brute=[]
n=[5,10,15,20,25,30,35,40]
os.chdir('D:/algorithm/hw4')
with open("./result.txt",'r')as f:
    tmpp=0
    lines=f.readlines()
    sum=0
    for line in lines:
        tmp=line.split()
        sum+=float(tmp[1])
        tmpp+=1
        if tmpp==3:
            tmpp=0
            aver.append(sum/3)
            sum=0
with open("./result2.txt",'r')as g:
    lines=g.readlines()
    for line in lines:
        print(line)
        tmp=line.split()
        print(tmp)
        brute.append(float(tmp[1]))

for ave in aver:
    print(ave)
    ans.append(ave)
    # print(ave)
print(brute)
plt.title("[107022210/107022218]brute force vs branch and bound ")
plt.xlabel('# of items')
plt.ylabel('Time(sec)')
plt.plot(n,ans)
plt.plot(n,brute)
plt.legend(["branch and bound","brute force"])
plt.yscale("log")
plt.grid()
plt.show()
sys.exit()