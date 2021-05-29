import numpy as np
import pandas as pd
import sys
#from Ipython.display import display

#Given A Matrix and centroid returns a vector of length from each point to center
def calc_distance_single_centroid(matrix, centroid):
    temp_mat = matrix - centroid
    temp_mat = np.square(temp_mat)
    dist = np.sum(temp_mat,axis=1)
    return dist



#1st Stage: get parameters from command line
args = sys.argv
if len(args)==5:
    k=int(args[1])
    max_iter = int(args[2])
    file_path1 = args[3]
    file_path2 = args[4]
else:
    k=int(args[1])
    max_iter = 200
    file_path1 = args[2]
    file_path2 = args[3]

#2nd Stage: Read Files and create a numpy matrix of inner joined data points
df1 = pd.read_csv(file_path1,header = None)
df2 = pd.read_csv (file_path2, header= None)

df = pd.merge(df1,df2,on=0,how='inner')
df = df.sort_values(0)
df = df.iloc[:,1:]
matrix = df.to_numpy()

#3rd Stage: Initiazlize some variables needed later
np.random.seed(0)
n,m = matrix.shape
indices = []
# dist [i,j] = l2 distance from point i to centroid j
# every entry of the table is initialized to infinity (So min distance won't be affected)
dists = np.ones((n,k))*float('inf')

#4th Stage: Initialize first centroid
centroid_index = np.random.choice(n)
centroid = matrix[centroid_index,:]

#5th Stage: Main loop of algorithm: updates a new centroid, calculates distances and selects another
for i in range (k):
    dists[:,i] = calc_distance_single_centroid(matrix,centroid);
    min_dist  = np.min(dists,axis=1)
    total_dist = np.sum(min_dist)
    pr = min_dist/total_dist
    indices.append(centroid_index)
    centroid_index = np.random.choice(n,p=pr)
    centroid = matrix[centroid_index,:]

