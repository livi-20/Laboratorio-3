#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 3
#endif

void print_matrix(int a[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int is_magic_square(int a[SIZE][SIZE]) {
    if (SIZE <= 0) return 0;

    int target = 0;
    for (int j = 0; j < SIZE; ++j) target += a[0][j];

    for (int i = 0; i < SIZE; ++i) {
        int sum = 0;
        for (int j = 0; j < SIZE; ++j) sum += a[i][j];
        if (sum != target) return 0;
    }

    for (int j = 0; j < SIZE; ++j) {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) sum += a[i][j];
        if (sum != target) return 0;
    }

    int sum_d1 = 0;
    for (int i = 0; i < SIZE; ++i) sum_d1 += a[i][i];
    if (sum_d1 != target) return 0;

    int sum_d2 = 0;
    for (int i = 0; i < SIZE; ++i) sum_d2 += a[i][SIZE - 1 - i];
    if (sum_d2 != target) return 0;

    return 1;
}

void fill_random_matrix(int a[SIZE][SIZE], int minV, int maxV) {
    if (minV > maxV) { int t = minV; minV = maxV; maxV = t; }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[i][j] = (rand() % (maxV - minV + 1)) + minV;
        }
    }
}

int main(void) {
    int matrix[SIZE][SIZE] = {
#if SIZE == 3
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}

#else
        {0}

#endif
    };

#if SIZE != 3
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            matrix[i][j] = (i * SIZE) + j + 1;
#endif

    printf("La matriz utilizada corresponde a:\n");
    print_matrix(matrix);
    if (is_magic_square(matrix)) {
        printf("La matriz es cuadrado magico.\n");
    } else {
        printf("La matriz NO es cuadrado magico.\n");
    }


    srand((unsigned)time(NULL));
    int randomM[SIZE][SIZE];
    fill_random_matrix(randomM, 1, 9); 
    printf("\nMatriz aleatoria generada:\n");
    print_matrix(randomM);
    if (is_magic_square(randomM)) {
        printf("La matriz aleatoria ES cuadrado magico.\n");
    } else {
        printf("La matriz aleatoria NO es cuadrado magico.\n");
    }

    return 0;
}
