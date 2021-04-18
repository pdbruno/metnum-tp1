#!/usr/bin/python

import sys
import csv
import pandas as pd
import numpy as np
from csv import reader


def wp(input):
    dataframe = pd.read_csv(input, sep=' ', skiprows=1, header=None)
    # cacona
    dataframe_inutil = pd.read_csv(input, sep=' ')
    teams_qty = int(dataframe_inutil.keys()[0])

    W = np.zeros((teams_qty, 1))
    N = np.zeros((teams_qty, 1))

    def process_line(row):
        i = row[1]-1 if row[2] > row[4] else row[3]-1
        j = row[3]-1 if row[2] > row[4] else row[1]-1
        W[i] = W[i] + 1
        N[j] = N[j] + 1
        N[i] = N[i] + 1

    dataframe.apply(process_line, axis=1)
    return (W / N)[:, 0]
