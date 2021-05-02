import sys
###################################################
############## HELPER FUNCTIONS####################
###################################################


#Gets 2 points and calculates the l2 distance between them (squared)
def calc_distance (point1, point2):
    assert len(point1)== len(point2)
    sum =0
    for i in range (len(point1)):
        sum+= (point1[i]-point2[i])**2
    return sum

#Gets a point and a list of current centroids and find the closest one to point (l2 distance)
def closest_centroid(point, centroids):
    min_distance = calc_distance(centroids[0],point)
    centroid =0
    for i in range(len(centroids)):
        distance = calc_distance(centroids[i],point)
        if distance < min_distance:
            min_distance = distance
            centroid = i
    return centroid

#gets to vectors of point and sums them elemntwise
def sum_points(point1,point2):
    assert len(point1)==len(point2)
    return [point1[i]+point2[i] for i in range (len(point1))]

#gets 2 tables of centroid and returns wheter they are identical
def is_centroid_equals(centroids, new_centroids):
    for i in range (len(centroids)):
        for j in range (len(centroids[i])):
            if centroids[i][j]!= new_centroids[i][j]:
                return False
    return True

def print_points(points):
    for point in points:
        for i in range(len(point)-1):
            print (format(point[i],'.4f'),end=',')
        print(format(point[len(point)-1],'.4f'))


##########################################################
################### Main Code ############################
##########################################################

#1st step: get input from command line
args = sys.argv
if len(args)==5:
    file_path = args[4]
    k=int(args[1])
    max_iter = int(args[2])
if len(args)==4:
    k=int(args[1])
    max_iter = 200
    file_path=args[3]

print (file_path)
#2nd step: import file and make it a list of points stored in data

f = open (file_path,"r")
data = []
for line in f:
    point_str = line[0:len(line)-1].split(',')
    point = [float(num) for num in point_str]
    data.append(point)

#3rd step: initailize centroids and calculate d
centroids = [data[i].copy() for i in range(k)]
d = len (data[0])

#4th step: run algorithm
for i in range (max_iter):
    #initialize array for calculations of new centroids and counter
    #Method: Sum and divide by count to get average
    new_centroids = [[0 for j in range (d)] for i in range (k)]
    counter = [0 for i in range (k)]

    #Calculate closest centroid for each point in data
    #than add it to new_centroid and add 1 to counter
    #at the end devide by counter
    for point in data:
        closest_centroid_index = closest_centroid (point, centroids)
        counter[closest_centroid_index] +=1
        new_centroids[closest_centroid_index] = sum_points(new_centroids[closest_centroid_index],point)
    for n in range (k):
        for m in range(d):
            if (counter [n] != 0):
                new_centroids[n][m] = new_centroids[n][m]/counter[n]
    if (is_centroid_equals(centroids,new_centroids)):
        break
    else:
        centroids = new_centroids

#5th step: format centroids table
print_points(centroids)









