//
// Created by volie on 22.10.2021.
//

#include "lib.h"

int **addMatrix(int **matrixA, int **matrixB, int rows, int columns)
{
    int **matrixC = new int *[rows];
    for(int i = 0; i < rows; i++)
        matrixC[i] = new int[columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return matrixC;
}

double **addMatrix(double **matrixA, double **matrixB, int rows, int columns)
{
    double **matrixC = new double *[rows];
    for(int i = 0; i < rows; i++)
        matrixC[i] = new double[columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return matrixC;
}

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns)
{
    int **matrixC = new int *[rows];
    for(int i = 0; i < rows; i++)
        matrixC[i] = new int[columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return matrixC;
}

double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns)
{
    double **matrixC = new double *[rows];
    for(int i = 0; i < rows; i++)
        matrixC[i] = new double[columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return matrixC;
}

int **multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int columnsA, int columnsB)
{
    int **matrixC = new int *[rowsA];
    for(int i = 0; i < rowsA; i++) {
        matrixC[i] = new int[columnsA];
    }

    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < columnsB; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < rowsA; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return matrixC;
}

double **multiplyMatrix(double **matrixA, double **matrixB, int rowsA, int columnsA, int columnsB)
{
    double **matrixC = new double *[rowsA];
    for(int i = 0; i < rowsA; i++) {
        matrixC[i] = new double[columnsA];
    }

    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < columnsB; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < rowsA; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return matrixC;
}

int **multiplyByScalar(int **matrixA, int rows, int columns, int scalar)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixA[i][j] = matrixA[i][j] * scalar;
        }
    }

    return matrixA;
}

double **multiplyByScalar(double **matrixA, int rows, int columns, double scalar)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixA[i][j] = matrixA[i][j] * scalar;
        }
    }

    return matrixA;
}

int **transpozeMatrix(int **matrixA, int rows, int columns)
{
    int **matrixT = new int *[columns];
    for(int i = 0; i < columns; i++)
        matrixT[i] = new int[rows];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixT[j][i] = matrixA[i][j];
        }
    }

    return matrixT;
}

double **transpozeMatrix(double **matrixA, int rows, int columns)
{
    double **matrixT = new double *[columns];
    for(int i = 0; i < columns; i++)
        matrixT[i] = new double[rows];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixT[j][i] = matrixA[i][j];
        }
    }

    return matrixT;
}

int **powerMatrix(int **matrixA, unsigned power, int rows, int columns)
{
    int **matrixC = new int *[rows];
    int **matrixD = new int *[rows];
    for(int i = 0; i < rows; i++) {
        matrixC[i] = new int[columns];
        matrixD[i] = new int[columns];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j];
        }
    }

    while(power >= 2) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                matrixD[i][j] = 0;
                for (int k = 0; k < rows; k++) {
                    matrixD[i][j] += matrixC[i][k] * matrixA[k][j];
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                matrixC[i][j] = matrixD[i][j];
            }
        }

        power--;
    }

    return matrixC;
}

double **powerMatrix(double **matrixA, unsigned power, int rows, int columns)
{
    double **matrixC = new double *[rows];
    double **matrixD = new double *[rows];
    for(int i = 0; i < rows; i++) {
        matrixC[i] = new double[columns];
        matrixD[i] = new double[columns];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrixC[i][j] = matrixA[i][j];
        }
    }

    while(power >= 2) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                matrixD[i][j] = 0;
                for (int k = 0; k < rows; k++) {
                    matrixD[i][j] += matrixC[i][k] * matrixA[k][j];
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                matrixC[i][j] = matrixD[i][j];
            }
        }

        power--;
    }

    return matrixC;
}

void subMatrix(int **matrixA, int **matrixTemp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                matrixTemp[i][j++] = matrixA[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void subMatrix(double **matrixA, double **matrixTemp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                matrixTemp[i][j++] = matrixA[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantMatrix(int **matrixA, int rows, int columns)
{
    int determinant = 0;
    int n = rows;

    if (n == 1) {
        return matrixA[0][0];
    }

    if (n == 2) {
        return (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
    }

    int **matrixTemp = new int *[n];
    for(int i = 0; i < n; i++)
        matrixTemp[i] = new int[n];

    int sign = 1;
    for (int i = 0; i < n; i++) {
        subMatrix(matrixA, matrixTemp, 0, i, n);
        determinant += sign * matrixA[0][i] * determinantMatrix(matrixTemp, n - 1, n - 1);
        sign = -sign;
    }

    return determinant;
}

double determinantMatrix(double **matrixA, int rows, int columns)
{
    double determinant = 0.0;
    int n = rows;

    if (n == 1) {
        return matrixA[0][0];
    }

    if (n == 2) {
        return (matrixA[0][0] * matrixA[1][1]) - (matrixA[0][1] * matrixA[1][0]);
    }

    double **matrixTemp = new double *[n];
    for(int i = 0; i < n; i++)
        matrixTemp[i] = new double[n];

    int sign = 1;
    for (int i = 0; i < n; i++) {
        subMatrix(matrixA, matrixTemp, 0, i, n);
        determinant += sign * matrixA[0][i] * determinantMatrix(matrixTemp, n - 1, n - 1);
        sign = -sign;
    }

    return determinant;
}

bool matrixIsDiagonal(int **matrixA, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if( (i != j) && (matrixA[i][j] != 0) ) {
                return false;
            }
        }
    }
    return true;
}

bool matrixIsDiagonal(double **matrixA, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if( (i != j) && (matrixA[i][j] != 0) ) {
                return false;
            }
        }
    }
    return true;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

int *sortRow(int *rowA, int columns)
{
    for (int i = 0; i < columns - 1; i++)
        for (int j = 0; j < columns - i - 1; j++)
            if (rowA[j] > rowA[j+1])
                swap(&rowA[j], &rowA[j+1]);

    return rowA;
}

double *sortRow(double *rowA, int columns)
{
    for (int i = 0; i < columns - 1; i++)
        for (int j = 0; j < columns - i - 1; j++)
            if (rowA[j] > rowA[j+1])
                swap(&rowA[j], &rowA[j+1]);

    return rowA;
}

int **sortRowsInMatrix(int **matrixA, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        matrixA[i] = sortRow(matrixA[i], columns);

    return matrixA;
}

double **sortRowsInMatrix(double **matrixA, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        matrixA[i] = sortRow(matrixA[i], columns);

    return matrixA;
}

void help()
{
    cout << "KALKULATOR MACIERZY" << endl << endl;
    cout << "Podaj: pierwszy argument - typ danych: 'int' lub 'double'" << endl;
    cout << "Podaj: drugi argument - dzialanie ktore chcesz wykonac, lista ponizej" << endl;
    cout << "Uzytkownik podaje ilosc wierszy, kolumn oraz wartosci macierzy" << endl;
    cout << "Wartosci do macierzy podawaj POJEDYNCZO(po kazdej enter) w kolejnosci wierszami od lewej do prawej" << endl << endl;
    cout << "Dzialania: " << endl;
    cout << "'addMatrix'         Dodawanie dwoch macierzy        [matrixA] [matrixB] [rows] [columns]" << endl;
    cout << "'subtractMatrix'    Odejmowanie dwoch macierzy      [matrixA] [matrixB] [rows] [columns]" << endl;
    cout << "'multiplyMatrix'    Mnozenie macierzy   [matrixA] [matrixB] [rowsA] [columnsA] [rowsB] [columnsB]" << endl;
    cout << "'multiplyByScalar'  Mnozenie macierzy przez skalar  [matrixA] [scalar] [rows] [columns]" << endl;
    cout << "'transpozeMatrix'   Transponowanie macierzy         [matrixA] [rows] [columns]" << endl;
    cout << "'powerMatrix'       Potegowanie macierzy            [matrixA] [power] [rows] [columns]" << endl;
    cout << "'determinantMatrix' Wyznacznik macierzy             [matrixA] [rows] [columns]" << endl;
    cout << "'MatrixIsDiagonal'  Sprawdzenie czy macierz jest diagonalna   [matrixA] [rows] [columns]" << endl;
    cout << "'swap'              Zamiana wartosci dwoch liczb    [a] [b]" << endl;
    cout << "'sortRow'           Sortowanie tablicy(wiersz macierzy)    [rowA] [columns]" << endl;
    cout << "'sortRowsInMatrix'  Sortowanie wierszy macierzy     [matrixA] [rows] [columns]" << endl;
    cout << "'help'              Wyswietlanie powyzszej dokumentacji" << endl;
}