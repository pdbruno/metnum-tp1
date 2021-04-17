#!/usr/bin/python

import sys
import numpy as np
from csv import reader


def cmm_rala(input):
    with open(input, 'r') as read_obj:
        # pass the file object to reader() to get the reader object
        csv_reader = reader(read_obj, delimiter=' ')
        first = next(csv_reader)
        teams_qty = int(first[0])
        C = [(i, i, 2) for i in range(teams_qty)]
        b = [1 for i in range(teams_qty)]

        for row in csv_reader:
            num_row = [int(num) for num in row]
            i = num_row[1]-1 if num_row[2] > num_row[4] else num_row[3]-1
            j = num_row[3]-1 if num_row[2] > num_row[4] else num_row[1]-1
            C[i] += 1
            C[j] += 1
            if coord:= tieneEnCoordenada(C, i, j) != -1:
                C[coord]+= 1
            else
                C.append((i, j, 1))

            if coord:= tieneEnCoordenada(C, j, i) != -1:
                C[coord]+= 1
            else
                C.append((j, i, 1))

            b[i] += 0.5
            b[j] -= 0.5

        diagonalizar(C, b)

    return despejar(C, b)

def tieneEnCoordenada(lista, i, j):
    for (x, y, _), index in zip(lista, range(len(lista)):
        if x == i and y == j:
            return index
    return -1

def diagonalizar(C, b):
    pass

def despejar(C, b):
    return []