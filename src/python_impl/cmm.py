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
            num_row = [int(num) for num in row]
            i = num_row[1]-1 if num_row[2] > num_row[4] else num_row[3]-1
            j = num_row[3]-1 if num_row[2] > num_row[4] else num_row[1]-1
            C[i, j] = C[i, j] - 1
            C[j, i] = C[j, i] - 1
            C[j, j] = C[j, j] + 1
            C[i, i] = C[i, i] + 1
            B[i] = B[i] + 1
            B[j] = B[j] - 1

        B = (B / 2) + 1
        print(C)
        print(B)

    return np.linalg.solve(C, B)

