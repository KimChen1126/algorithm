import matplotlib.pyplot as plt
import numpy as np
import os,math
row=41
time=[[]]*8
aver=[]
ans=[]
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
            aver.append(sum)
            sum=0
for val in n :
    print(val)
# for i in range(len(time)):
#     aver.append(np.log2(sum(time[i])/len(time[i])))
for ave in aver:
    print(ave)
    ans.append(np.log(ave))
    print(ave)
plt.xlabel('# of items')
plt.ylabel('Time Complexity')
plt.plot(n,ans, label ='bruteforce')
plt.grid()
plt.show()