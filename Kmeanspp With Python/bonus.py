from sklearn import datasets
from sklearn import cluster
import numpy as np
import matplotlib.pyplot as plt


def eval_model(data, centroids):
    ''' Helper Function to calculate the sum of distances from closest centroid'''
    n, d = data.shape
    distances = np.zeros((n,k))
    for i in range(k):
        temp = data-centroids[i,:]
        temp = np.square(temp)
        temp = np.sum(temp,axis=1)
        distances[:,i] = temp.transpose()
    return np.sum(np.min(distances,axis=1))

iris_data = datasets.load_iris()
data = iris_data["data"]
y =[]
for k in range(1, 11):
    kmeans = cluster.KMeans(init="k-means++", n_clusters=k, random_state=0)
    kmeans.fit(data)
    centroids = kmeans.cluster_centers_
    y.append(eval_model(data,centroids))

x = [k for k in range (1,11)]
dif , elbow = plt.subplots()

line = elbow.plot(x,y)
elbow.annotate('Elbow Point', xy=(1, 1),
                xytext=(1, 1),
                arrowprops=dict(facecolor='black',
                                shrink=0.05), )

elbow.set_ylim(-2, 2)
plt.show()
#plt.savefig("elbow.png")