import numpy as np
import math
import matplotlib.pyplot as plt

regular = np.loadtxt(fname = 'Regular.txt', delimiter = ' ')
bottom = np.loadtxt(fname = 'Bottom.txt', delimiter = ' ')
X = [] #for size
Y = []
Regular_= []
Bottom_ = []



for i in range(len(regular)):
    for j in range(2):
        if j == 0:
            X.append(regular[i][j])
        else: 
            Y.append(regular[i][j])




for i in range(len(bottom)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            Bottom_.append(bottom[i][j])



plt.plot(X, Y, 'r', label = 'HeapSort')
plt.plot(X, Bottom_, 'g', label = 'BottomUpHeapSort')

plt.show()