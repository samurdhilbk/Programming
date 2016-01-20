import numpy as np
import os
import networkx as nx
import math
from collections import Counter

f = open("input.txt","r")
out = open("boomerang_out.txt","w")
n = int(f.readline())
for cnt in range(n):
    k = int(f.readline())
    x = {}
    y = {}
    for i in range(k):
        temp = f.readline().split()
        x[i] = int(temp[0])
        y[i] = int(temp[1])
    sol = 0
    for i in range(k):
        #calculate how many times this one is in the center
        dis = {}
        for j in range(k):
            if i!=j:
                dis[j] = ((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j]))
        tally=Counter()
        for elem in dis:
            tally[dis[elem]] += 1
        #print cnt+1, i, dis, tally
        for elem in tally:
            if tally[elem] > 1:
                #sol += math.pow(2,tally[elem]) - tally[elem] - 1
                sol += (tally[elem] * (tally[elem] - 1) ) / 2
    out.write("Case #" + str(cnt+1) + ": " + str(int(sol)) + "\n")
out.close()
