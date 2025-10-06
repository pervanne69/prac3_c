/* ----------------------------------------------------*/
/* ИМЯ: Pogosian Samvel, ID пользователя: 23К0180      */
/* ДАТА: 06/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Демонстрация динамического размещения двумерного     */
/* массива и анализа адресов его элементов.             */
/* ИМЯ ФАЙЛА: two-dimension-arr.c                       */
/* ----------------------------------------------------*/
/* ФУНКЦИИ:                                            */
/* main() – выделяет память под двумерный массив,       */
/*          заполняет его, выводит значения и адреса,   */
/*          затем освобождает память.                   */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **arr = (int **)malloc(n * sizeof(int *));

    if (arr == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
        if (arr[i] == NULL) {
            perror("malloc failed");
            return 1;
        }
    }

    printf("Two dimension array elements and their addresses\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i + j;
            printf("arr[%d][%d] = %d, address = %p\n", i, j, arr[i][j], &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

