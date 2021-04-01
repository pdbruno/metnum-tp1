#!/usr/bin/python

import sys
import csv
import pandas as pd
import numpy as np
from csv import reader

def process_line(row):
    i = row[1]-1
    j = row[3]-1
    W[i] = W[i] + 1
    N[j] = N[j] + 1
    N[i] = N[i] + 1

DATASET_PATH = 1

dataset = sys.argv[DATASET_PATH]

dataframe = pd.read_csv(dataset, sep=' ', skiprows=1, header=None)

# cacona
dataframe_inutil = pd.read_csv(dataset, sep=' ')
teams_qty = int(dataframe_inutil.keys()[0])

W = np.array(np.zeros((teams_qty, 1))) + 1
N = np.array(np.zeros((teams_qty, 1))) + 2

dataframe.apply(process_line, axis=1)

X = W / N

print('=== SOLUTION ===')
print(np.sort(X, axis=0))