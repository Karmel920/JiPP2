//
// Created by volie on 22.10.2021.
//

#include <iostream>
#include "lib.h"
#include <string.h>
#include <string>

void DoAddMatrix(string typeMatrix);
void DoSubtractMatrix(string typeMatrix);
void DoMultiplyMatrix(string typeMatrix);
void DoMultiplyByScalar(string typeMatrix);
void DoTranspozeMatrix(string typeMatrix);
void DoPowerMatrix(string typeMatrix);
void DoDeterminantMatrix(string typeMatrix);
void DoMatrixIsDiagonal(string typeMatrix);
void DoSwap(string typeMatrix);
void DoSortRow(string typeMatrix);
void DoSortRowInMatrix(string typeMatrix);
void printMatrix(int **matrix, int rows, int columns);
void printMatrix(double **matrix, int rows, int columns);
void checkInput(int **matrix, int rows, int columns);
int **createIntMatrix(int rows, int columns);
double **createDoubleMatrix(int rows, int columns);
void destroyMatrix(int **matrix, int rows, int columns);
void destroyMatrix(double **matrix, int rows, int columns);

using namespace std;

int main(int argc, char *argv[]) {

    string typeMatrix;
    typeMatrix = argv[1];

    if(!strcmp(argv[1], "help"))
        help();
    else if(!strcmp(argv[2], "addMatrix"))
        DoAddMatrix(typeMatrix);
    else if(!strcmp(argv[2], "subtractMatrix"))
        DoSubtractMatrix(typeMatrix);
    else if(!strcmp(argv[2], "multiplyMatrix"))
        DoMultiplyMatrix(typeMatrix);
    else if(!strcmp(argv[2], "multiplyByScalar"))
        DoMultiplyByScalar(typeMatrix);
    else if(!strcmp(argv[2], "transpozeMatrix"))
        DoTranspozeMatrix(typeMatrix);
    else if(!strcmp(argv[2], "powerMatrix"))
        DoPowerMatrix(typeMatrix);
    else if(!strcmp(argv[2], "determinantMatrix"))
        DoDeterminantMatrix(typeMatrix);
    else if(!strcmp(argv[2], "MatrixIsDiagonal"))
        DoMatrixIsDiagonal(typeMatrix);
    else if(!strcmp(argv[2], "swap"))
        DoSwap(typeMatrix);
    else if(!strcmp(argv[2], "sortRow"))
        DoSortRow(typeMatrix);
    else if(!strcmp(argv[2], "sortRowsInMatrix"))
        DoSortRowInMatrix(typeMatrix);
    else if(!strcmp(argv[2], "help"))
        help();
    else {
        cout << "BLAD, zly badz zla ilosc parametrow" << endl << endl;
        help();
    }

    return 0;
}


int **createIntMatrix(int rows, int columns)
{
    int **matrix = new int* [rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    return matrix;
}

double **createDoubleMatrix(int rows, int columns)
{
    double **matrix = new double* [rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new double[columns];

    return matrix;
}

void destroyMatrix(int **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void destroyMatrix(double **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void checkInput(int **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                    cin >> matrix[i][j];
                }
                if(!cin.fail())
                    break;
            }
        }
    }
}


void checkInput(double **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                    cin >> matrix[i][j];
                }
                if(!cin.fail())
                    break;
            }
        }
    }
}


void printMatrix(int **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrix(double **matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DoAddMatrix(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);
        int **matrixB = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rows, columns);

        matrixC = addMatrix(matrixA, matrixB, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixB, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixB = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rows, columns);

        matrixC = addMatrix(matrixA, matrixB, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixB, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }

}

void DoSubtractMatrix(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);
        int **matrixB = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rows, columns);

        matrixC = subtractMatrix(matrixA, matrixB, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixB, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixB = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rows, columns);

        matrixC = subtractMatrix(matrixA, matrixB, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixB, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoMultiplyMatrix(string typeMatrix)
{
    int rowsA, columnsA, rowsB, columnsB;

    cout << "Podaj liczbe wierszy macierzy A: " << endl;
    cin >> rowsA;
    cout << "Podaj liczbe kolumn macierzy A: " << endl;
    cin >> columnsA;
    cout << "Podaj liczbe wierszy macierzy B: " << endl;
    cin >> rowsB;
    cout << "Podaj liczbe kolumn macierzy B: " << endl;
    cin >> columnsB;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rowsA, columnsA);
        int **matrixB = createIntMatrix(rowsB, columnsB);
        int **matrixC = createIntMatrix(rowsA, columnsB);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rowsA, columnsA);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rowsB, columnsB);

        matrixC = multiplyMatrix(matrixA, matrixB, rowsA, columnsA, columnsB);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rowsA, columnsB);

        destroyMatrix(matrixA, rowsA, columnsA);
        destroyMatrix(matrixB, rowsB, columnsB);
        destroyMatrix(matrixC, rowsA, columnsB);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rowsA, columnsA);
        double **matrixB = createDoubleMatrix(rowsB, columnsB);
        double **matrixC = createDoubleMatrix(rowsA, columnsB);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rowsA, columnsA);

        cout << endl << "Podaj wartosci macierzy B: " << endl;
        checkInput(matrixB, rowsB, columnsB);

        matrixC = multiplyMatrix(matrixA, matrixB, rowsA, columnsA, columnsB);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rowsA, columnsB);

        destroyMatrix(matrixA, rowsA, columnsA);
        destroyMatrix(matrixB, rowsB, columnsB);
        destroyMatrix(matrixC, rowsA, columnsB);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoMultiplyByScalar(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int scalar;

        int **matrixA = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << "Podaj skalar: " << endl;
        cin >> scalar;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe, podaj liczbe: " << endl;
                cin >> scalar;
            }
            if(!cin.fail())
                break;
        }

        matrixC = multiplyByScalar(matrixA, rows, columns, scalar);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double scalar;

        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << "Podaj skalar: " << endl;
        cin >> scalar;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe, podaj liczbe: " << endl;
                cin >> scalar;
            }
            if(!cin.fail())
                break;
        }

        matrixC = multiplyByScalar(matrixA, rows, columns, scalar);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoTranspozeMatrix(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        matrixC = transpozeMatrix(matrixA, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixA, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        matrixC = transpozeMatrix(matrixA, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoPowerMatrix(string typeMatrix)
{
    int rows, columns;
    unsigned power;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << "Podaj potege: " << endl;
        cin >> power;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe, podaj liczbe: " << endl;
                cin >> power;
            }
            if(!cin.fail())
                break;
        }

        matrixC = powerMatrix(matrixA, power, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        cout << "Podaj potege: " << endl;
        cin >> power;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe, podaj liczbe: " << endl;
                cin >> power;
            }
            if(!cin.fail())
                break;
        }

        matrixC = powerMatrix(matrixA, power, rows, columns);

        cout << endl << "Wynik: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoDeterminantMatrix(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int determinant;

        int **matrixA = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        determinant = determinantMatrix(matrixA, rows, columns);

        cout << endl << "Wynik: " << endl << determinant;

        destroyMatrix(matrixA, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double determinant;

        double **matrixA = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        determinant = determinantMatrix(matrixA, rows, columns);

        cout << endl << "Wynik: " << endl << determinant;

        destroyMatrix(matrixA, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoMatrixIsDiagonal(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        if(matrixIsDiagonal(matrixA, rows, columns))
            cout << "Macierz diagonalna" << endl;
        else
            cout << "Macierz nie jest diagonalna" << endl;

        destroyMatrix(matrixA, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        if(matrixIsDiagonal(matrixA, rows, columns))
            cout << "Macierz diagonalna" << endl;
        else
            cout << "Macierz nie jest diagonalna" << endl;

        destroyMatrix(matrixA, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoSwap(string typeMatrix)
{
    if(typeMatrix.compare("int") == 0) {
        int a, b;

        cout << "Podaj pierwsza liczbe a: " << endl;
        cin >> a;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                cin >> a;
            }
            if(!cin.fail())
                break;
        }
        cout << "Podaj druga liczbe b: " << endl;
        cin >> b;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                cin >> b;
            }
            if(!cin.fail())
                break;
        }

        swap(&a, &b);

        cout << "Po zamianie: " << endl << "Liczba a: " << a << endl << "Liczba b: " << b << endl;
    }
    else if(typeMatrix.compare("double") == 0) {
        double a, b;

        cout << "Podaj pierwsza liczbe a: " << endl;
        cin >> a;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                cin >> a;
            }
            if(!cin.fail())
                break;
        }
        cout << "Podaj druga liczbe b: " << endl;
        cin >> b;
        while(1) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                cin >> b;
            }
            if(!cin.fail())
                break;
        }

        swap(&a, &b);

        cout << "Po zamianie: " << endl << "Liczba a: " << a << endl << "Liczba b: " << b << endl;
    }
    else {
        cout << "Zly typ, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoSortRow(string typeMatrix)
{
    int columns;

    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int *rowA = new int[columns];
        int *rowC = new int[columns];

        cout << "Podaj wartosci tablicy A: " << endl;
        for(int i = 0; i < columns; i++) {
            cin >> rowA[i];
            while (1) {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                    cin >> rowA[i];
                }
                if (!cin.fail())
                    break;
            }
        }

        rowC = sortRow(rowA, columns);

        cout << "Posortowana tablica: " << endl;
        for(int j = 0; j < columns; j++)
            cout << rowC[j] << " ";

        delete [] rowA;
        delete [] rowC;
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double *rowA = new double[columns];
        double *rowC = new double[columns];

        cout << "Podaj wartosci tablicy A: " << endl;
        for(int i = 0; i < columns; i++) {
            cin >> rowA[i];
            while (1) {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Zle dane wejsciowe. Prosze podac liczbe: " << endl;
                    cin >> rowA[i];
                }
                if (!cin.fail())
                    break;
            }
        }

        rowC = sortRow(rowA, columns);

        cout << "Posortowana tablica: " << endl;
        for(int j = 0; j < columns; j++)
            cout << rowC[j] << " ";

        delete [] rowA;
        delete [] rowC;
    }
    else
    {
        cout << "Zly typ, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}

void DoSortRowInMatrix(string typeMatrix)
{
    int rows, columns;

    cout << "Podaj liczbe wierszy: " << endl;
    cin >> rows;
    cout << "Podaj liczbe kolumn: " << endl;
    cin >> columns;

    if(typeMatrix.compare("int") == 0)
    {
        int **matrixA = createIntMatrix(rows, columns);
        int **matrixC = createIntMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        matrixC = sortRowsInMatrix(matrixA, rows, columns);

        cout << "Macierz z posortowanymi wierszami: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else if(typeMatrix.compare("double") == 0)
    {
        double **matrixA = createDoubleMatrix(rows, columns);
        double **matrixC = createDoubleMatrix(rows, columns);

        cout << "Podaj wartosci macierzy A: " << endl;
        checkInput(matrixA, rows, columns);

        matrixC = sortRowsInMatrix(matrixA, rows, columns);

        cout << "Macierz z posortowanymi wierszami: " << endl;
        printMatrix(matrixC, rows, columns);

        destroyMatrix(matrixA, rows, columns);
        destroyMatrix(matrixC, rows, columns);
    }
    else
    {
        cout << "Zly typ macierzy, podaj 'int' lub 'double'" << endl;
        cout << "Dokumentacja po wywolaniu 'help'" << endl;
        return;
    }
}