import numpy as np
import math
import matplotlib.pyplot as plt

data = np.loadtxt(fname = 'worst.txt', delimiter = ' ')
data_best = np.loadtxt(fname = 'best.txt', delimiter = ' ')
data_average = np.loadtxt(fname = 'average.txt', delimiter = ' ')
X = [] #for size
Y = []
best = []
average = []



for i in range(len(data)):
    for j in range(2):
        if j == 0:
            X.append(data[i][j])
        else: 
            Y.append(data[i][j])




for i in range(len(data_best)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            best.append(data_best[i][j])

for i in range(len(data_average)):
    for j in range(2):
        if j == 0:
            continue
        else: 
            average.append(data_average[i][j])


plt.plot(X, Y, 'r', label = 'worst')
plt.plot(X, best, 'g', label = 'best')
plt.plot(X, average, 'y', label = 'average')

plt.show()