#include <stdio.h>
#include "kmeans_algo.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int calc_d(char* row){
    // counts how many commas exists and return that number +1.
    int c = 0;
    int i = 0;
    while (row[i]!='\n'){
        if (row[i]==','){
            c++;
        }
        i++;
    }
    c++;
    return c;
}

double* parse_datapoint(char* row ,int d){
    //Allocate space from OS and assert it
    double *point =calloc(d,sizeof (double ));
    assert (point!=NULL);
    char *pointer;
    double number;
    int loc=0;
    char delim[] = ",";
    //get the first number before comma
    pointer = strtok(row,delim);
    while (pointer!= NULL ){
        //convert string to double
        number = atof(pointer);
        point [loc] = number;
        // get the next string between commas.
        pointer = strtok(NULL,delim);
        loc ++;
    }
    return point;
}

double l2_dist(double* point1, double* point2, int d){
    double sum = 0;
    int i;
    for (i=0;i<d;i++){
        sum += pow((point1[i]-point2[i]),2);
    }
    return sum;
}


void print_array (double* point,int d){
    int i;
    for (i=0;i<d;i++){
        printf("%f\n", point[i]);
    }
}

int main() {
    char str[] = "-0.9626,7.5403,-0.5724,-3.6368,-4.5917,10.0681,-5.6816,-5.8396,6.0236,-0.7875,-2.5990\n";
    int d = calc_d(str);
    printf("d= %d \n",d);
    double* point = parse_datapoint(str,d);
    print_array(point,d);

}
