//
// Created by Y on 4/21/2021.
//

#ifndef KMEANS_KMEANS_ALGO_H
#define KMEANS_KMEANS_ALGO_H

/*
 * gets a path to the file containing the datapoints, and parses each line as a different point
 */
double** load_dataset(char* path_to_datapoints);

/*
 * gets a row from the file, and parses it as a double array point.
 */
double* parse_datapoint(char* row ,int d);

/*
 * gets the result k means and prints them to console
 */

void print_means(double** kmeans, int k, int d);

/*
 * count how many commas in the row, and return d (num of commas +1)
 */
int calc_d(char* row);

/*
 * Gets an array of [N,d] dims, and calculates the means.
 */
double** calc_k_means(double** data_points, int k, int N, int d, int max_iter);

/*
 * calculates a running average to get the next u values
 * creates an internal double[k][d] of sum of points - sums
 * creates an internal int[k] of count of points per u value - counts
 * divides the each line of internal sums array by internal counts array
 */
double** calc_k_means_iter(double** data_points, double** former_k_means, int k, int N, int d);

/*
 * calculates the l2 distance (square distance per coordinate) of the 2 points (each point contains d coordinates)
 * returns the distance
 */
double l2_dist(double* point1, double* point2, int d);


#endif //KMEANS_KMEANS_ALGO_H
