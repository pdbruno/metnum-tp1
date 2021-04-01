#!/usr/bin/python

import sys
import csv
import pandas as pd
import numpy as np
from csv import reader

def process_line(row):
    i = row[1]-1
    j = row[3]-1
    C[i, j] = C[i, j] - 1
    C[j, i] = C[j, i] - 1
    C[j, j] = C[j, j] + 1
    C[i, i] = C[i, i] + 1
    B[i] = B[i] + 0.5
    B[j] = B[j] - 0.5

DATASET_PATH = 1

dataset = sys.argv[DATASET_PATH]

dataframe = pd.read_csv(dataset, sep=' ', skiprows=1, header=None)

# cacona
dataframe_inutil = pd.read_csv(dataset, sep=' ')
teams_qty = int(dataframe_inutil.keys()[0])

C = np.identity(teams_qty) * 2
B = np.array(np.zeros((teams_qty, 1))) + 1

dataframe.apply(process_line, axis=1)

X = np.linalg.solve(C, B)

print(C)
print(B)
print('=== SOLUTION ===')
print(np.sort(X, axis=0))