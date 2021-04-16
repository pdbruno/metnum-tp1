#!/usr/bin/python

import sys
import csv
import numpy as np
from csv import reader


DATASET_PATH = 1

dataset = sys.argv[DATASET_PATH]

def keener(input):
    K = None

    with open(input, 'r') as read_obj:
        csv_reader = reader(read_obj, delimiter=' ')

        first = next(csv_reader)

        teams_qty = int(first[0])

        C = np.identity(teams_qty) * 2

        K = np.array(np.zeros((teams_qty, teams_qty)))
        S = np.array(np.zeros((teams_qty, teams_qty)))
        J = np.zeros((teams_qty, teams_qty), dtype=bool)

        for row in csv_reader:
            i = int(row[1])-1
            pointsi = int(row[2])
            j = int(row[3])-1
            pointsj = int(row[4])

            if pointsi > pointsj:
                winner = i
                loser = j
            else:
                winner = j
                loser = i

            J[winner][loser] = True
            J[loser][winner] = True

            S[winner][loser] += max(pointsi, pointsj)
            S[loser][winner] += min(pointsi, pointsj)

    for i in range(teams_qty):
        for j in range(teams_qty):
            K[i][j] = h((S[i][j] + 1) / (S[i][j] + S[j][i] + 2)) if J[i][j] else 0


    return power_iteration(K, 10000)

def h(x):
    return (0.5+ 0.5 * np.sign(x-0.5) * np.sqrt(abs(2*x-1)))

def power_iteration(A, num_simulations):
    # Ideally choose a random vector
    # To decrease the chance that our vector
    # Is orthogonal to the eigenvector
    b_k = np.random.rand(A.shape[1])

    for _ in range(num_simulations):
        # calculate the matrix-by-vector product Ab
        b_k1 = np.dot(A, b_k)

        # calculate the norm
        b_k1_norm = np.linalg.norm(b_k1)

        # re normalize the vector
        b_k = b_k1 / b_k1_norm

    return b_k
