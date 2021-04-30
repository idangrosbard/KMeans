//
// Created by Y on 4/23/2021.
//

#include "main.h"
#include <time.h>
#include <stdio.h>

void methodA() {
    char c;
    FILE* fp = fopen(".\\tests\\input_3.txt", 'r');
    while(c != '\n') {
        c = getc( fp );
    }
}

void methodB() {
    char buff[255];
    FILE* fp = fopen(".\\tests\\input_3.txt", 'r');
    fgets(buff, 255, fp );
}

int main() {
    clock_t begin = clock();

    methodA();

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d", time_spent);

    begin = clock();

    methodB();

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d", time_spent);
}