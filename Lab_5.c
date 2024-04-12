//mai.c
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

double** creation_matrix(int n){
    double** matrix1 = (double**)malloc(n * sizeof(double*));
    printf("Введите элементы матрицы: \n");
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }
    return matrix1;
}

void print_matrix(int n, double** matrix1, double** matrix2){
    char operation;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);
    double** result = matrix_calculator(matrix1, matrix2, n, operation);
    printf("Результат операции: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n,i,j;
    
    printf("Введите размерность квадратной матрицы n: ");
    scanf("%d", &n);

    double** matrix1 = creation_matrix(n);
    double** matrix2 = creation_matrix(n);

    print_matrix(n, matrix1, matrix2);

    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    return 0;
}

//matrix_operations.h
double** matrix_calculator(double** matrix1, double** matrix2, int n, char operation);

//matrix_operations.c
#include <stdlib.h>

double** allocation_memory(int n){
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }
    return result;
}
double** matrix_calculator(double** matrix1, double** matrix2, int n, char operation) {
    int i,j,k;
	double** result = allocation_memory( n);
    
    if (operation == '+') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    
    if (operation == '-') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                 result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }
    
    if (operation == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = 0;
                for (k = 0; k<n; k++){
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    return result;
}
