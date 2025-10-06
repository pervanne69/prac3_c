/* ----------------------------------------------------*/
/* ИМЯ: Pogosian Samvel, ID пользователя: 23К0180      */
/* ДАТА: 06/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Демонстрация динамического размещения одномерного    */
/* массива и анализа адресов его элементов.             */
/* ИМЯ ФАЙЛА: one-dimension-arr.c                       */
/* ----------------------------------------------------*/
/* ФУНКЦИИ:                                            */
/* main() – выделяет память под массив, заполняет его,  */
/*          выводит значения и адреса, освобождает память.*/
/* ----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        perror("malloc failed");
        return 1;
    }

    printf("Array elements and their addresses:\n");
    for (int i = 0; i< n; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d, address = %p\n", i, arr[i], (void * )&arr[i]);
    }
    free(arr);
    return 0;

}
