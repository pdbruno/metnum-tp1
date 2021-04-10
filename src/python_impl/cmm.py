#!/usr/bin/python

import sys
import numpy as np
from csv import reader

DATASET_PATH = 1
#dataset = sys.argv["/home/msorondo/Desktop/Metodos Numericos/metnum-tp1/tests/test1.in"]
dataset = "/home/msorondo/Desktop/Metodos Numericos/metnum-tp1/tests/test1.in"
C = None
B = None

# open file in read mode
with open(dataset, 'r') as read_obj:
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

X = np.linalg.solve(C, B)


#np.set_printoptions(formatter={'float': lambda x: "{0:0.6f}".format(x)})
#print(C)
#print(B)
print('=== SOLUTION ===')
print(X)
#print(np.sort(X, axis=0))

""" 
/****************************************************************
Module colley -computes rating scores of the teams
INPUT: A (games by 4) matrix [team i score i team j score j]
teams - number of teams
OUTPUT: vector Cvec, where Cvec(i) is the rating score of team i
*****************************************************************/
start colley(A,teams);
/* begin module colley*/
/* N[i,j] = number of times team i played team j*/
/* WL[i,1] = number of wins by team i, WL[i,2]= number of losses by team i*/
N=j(teams,teams,0);
WL=j(teams,2,0);
do i=1 to nrow(A);
    N[A[i,1],A[i,3]]=N[A[i,1],A[i,3]]+1;
    N[A[i,3],A[i,1]]=N[A[i,3],A[i,1]]+1;
    if A[i,2]>A[i,4] then
        do;
            WL[A[i,1], 1]=WL[A[i,1],1]+1;
            WL[A[i,3], 2]=WL[A[i,3],2]+1;
        end;
    else
        do;
            WL[A[i,1], 2]=WL[A[i,1],2]+1;
            WL[A[i,3], 1]=WL[A[i,3],1]+1;
        end;
end;
total = N[ ,+];

C=j(teams,teams,0); /* initialize Colley matrix to zero*/
B=j(teams,1,0); /* initialize B vector to zero*/

/* Fill in Colley matrix and B vector */
do i=1 to teams;
    B[i,1]=1+(WL[i,1]-WL[i,2])/2;
    C[i,i]=2+total[i,1];
    do j=i+1 to teams;
        C[i,j]=-N[i,j]; C[j,i]=-N[i,j];
    end;
end;

Cvec = solve(C,B);
return(Cvec);
finish;
/* end module colley*/ 
"""