#!/usr/bin/python

import sys
import numpy as np
from csv import reader


def cmm(input):
    C = None
    B = None

    with open(input, 'r') as read_obj:
        # pass the file object to reader() to get the reader object
        csv_reader = reader(read_obj, delimiter=' ')
        first = next(csv_reader)
        teams_qty = int(first[0])
        C = np.identity(teams_qty) * 2
        B = np.array(np.zeros((teams_qty, 1)))
        for row in csv_reader:
            i = int(row[1])-1
            j = int(row[3])-1
            C[i, j] = C[i, j] - 1
            C[j, i] = C[j, i] - 1
            C[j, j] = C[j, j] + 1
            C[i, i] = C[i, i] + 1
            B[i] = B[i] + 1
            B[j] = B[j] - 1

        B = (B / 2) + 1

    return np.linalg.solve(C, B)

