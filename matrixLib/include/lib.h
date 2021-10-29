//
// Created by volie on 22.10.2021.
//

#ifndef JIPP2_LIB_H
#define JIPP2_LIB_H

#include <iostream>

using namespace std;

int **addMatrix(int **matrixA, int **matrixB, int rows, int columns);
double **addMatrix(double **matrixA, double **matrixB, int rows, int columns);

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns);
double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns);

int **multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int columnsA, int columnsB);
double **multiplyMatrix(double **matrixA, double **matrixB, int rowsA, int columnsA, int columnsB);

int **multiplyByScalar(int **matrixA, int rows, int columns, int scalar);
double **multiplyByScalar(double **matrixA, int rows, int columns, double scalar);

int **transpozeMatrix(int **matrixA, int rows, int columns);
double **transpozeMatrix(double **matrixA, int rows, int columns);

int **powerMatrix(int **matrixA, unsigned power, int rows, int columns);
double **powerMatrix(double **matrixA, unsigned power, int rows, int columns);

void subMatrix(int **matrixA, int **matrixTemp, int p, int q, int n);
void subMatrix(double **matrixA, double **matrixTemp, int p, int q, int n);

int determinantMatrix(int **matrixA, int rows, int columns);
double determinantMatrix(double **matrixA, int rows, int columns);

bool matrixIsDiagonal(int **matrixA, int rows, int columns);
bool matrixIsDiagonal(double **matrixA, int rows, int columns);

void swap(int *a, int *b);
void swap(double *a, double *b);

int *sortRow(int *rowA, int columns);
double *sortRow(double *rowA, int columns);

int **sortRowsInMatrix(int **matrixA, int rows, int columns);
double **sortRowsInMatrix(double **matrixA, int rows, int columns);

void help();


#endif //JIPP2_LIB_H
