import numpy as np
import math
import matplotlib.pyplot as plt

Lomuto = np.loadtxt(fname = 'Lomuto.txt', delimiter = ' ')
Hoare = np.loadtxt(fname = 'Hoare.txt', delimiter = ' ')
Median = np.loadtxt(fname = 'Median.txt', delimiter = ' ')
MedianH = np.loadtxt(fname = 'MedianH.txt', delimiter = ' ')

YLomuto = []
YHoare = []
YMedian = []
YMedianH = []

X = [] #for size
Y = []
Regular_= []
Bottom_ = []



for i in range(len(Lomuto)):
    for j in range(2):
        if j == 0:
            X.append(Lomuto[i][j])
        else: 
            YLomuto.append(Lomuto[i][j])




for i in range(len(Hoare)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            YHoare.append(Hoare[i][j])


for i in range(len(Median)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            YMedian.append(Median[i][j])


for i in range(len(MedianH)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            YMedianH.append(MedianH[i][j])

plt.plot(X, YMedian, 'y', label = 'Median with Lomuto')
plt.plot(X, YLomuto, 'r', label = 'Lomuto')
plt.plot(X, YHoare, 'g', label = 'Hoare')

#plt.plot(X, YMedianH, 'y', label = 'Median with Hoare')

plt.show()