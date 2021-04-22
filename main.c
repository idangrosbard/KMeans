#include <stdio.h>
#include "kmeans_algo.h"
#include <string.h>
#include <stdlib.h>

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
    double *point =calloc(d,sizeof (double ));
    char *pointer;
    double number;
    int loc=0;
    char delim[] = ",";
    pointer = strtok(row,delim);
    while (pointer!= NULL ){
        number = atof(pointer);
        point [loc] = number;
        pointer = strtok(NULL,delim);
        loc ++;
    }
    return point;
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
