/* ----------------------------------------------------*/
/* ИМЯ: Pogosian Samvel, ID пользователя: 23К0180      */
/* ДАТА: 06/10/2025                                    */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                               */
/* Программа генерирует массив случайных чисел,        */
/* определяет количество простых чисел в массиве и    */
/* находит минимальное простое число (если оно есть). */
/* ИСПОЛЬЗУЕМЫЕ ФУНКЦИИ:                               */
/* main() – ввод размера массива, генерация чисел,    */
/*          вызов функции подсчёта простых чисел и   */
/*          вывод результатов.                        */
/* is_prime() – проверяет, является ли число простым. */
/* get_prime_count_and_min() – считает количество и   */
/*          минимум простых чисел в массиве.         */
/* ФАЙЛ: main.c                                       */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 500


/* ----------------------------------------------------*/
/* ФУНКЦИЯ: is_prime                                  */
/* ПАРАМЕТРЫ:                                        */
/*  number – проверяемое целое число                  */
/* ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ:                            */
/*  1 – если число простое                            */
/*  0 – если число составное                          */
/* ----------------------------------------------------*/

int is_prime(int number) {
    if (number < 2) return 0;
    for (int j = 2; j * j <= number; j++) {
        if (number % j == 0) return 0;
    } 
    return 1;

}

/* ----------------------------------------------------*/
/* ФУНКЦИЯ: get_prime_count_and_min                   */
/* ПАРАМЕТРЫ:                                        */
/*  size      – размер массива                         */
/*  arr       – указатель на массив чисел             */
/*  mini_ptr  – указатель на переменную для минимума  */
/*  count     – указатель на переменную для подсчёта  */
/* ЗАДАЧА:                                           */
/*  Подсчитывает количество простых чисел и находит  */
/*  минимальное простое число в массиве.             */
/* ----------------------------------------------------*/

int get_prime_count_and_min(int size, int *arr, int *mini_ptr, int *count) {
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i])) {
            *count += 1;
            if (arr[i] < *mini_ptr) {
               *mini_ptr = arr[i];
            }
        }
    }

    return 0;
}


/* ----------------------------------------------------*/
/* ФУНКЦИЯ: main                                     */
/* ПАРАМЕТРЫ: нет                                    */
/* ЗАДАЧА:                                           */
/*  1. Инициализация генератора случайных чисел       */
/*  2. Ввод размера массива                           */
/*  3. Создание массива и заполнение случайными числами*/
/*  4. Вывод массива                                  */
/*  5. Подсчёт количества простых чисел и минимум     */
/*  6. Вывод результатов                              */
/* ----------------------------------------------------*/

int main() {
    
    srand(time(NULL));

    int n;

    int count = 0;

    int mini = MAX_NUMBER;

    int *n_ptr = &n;

    int *mini_ptr = &mini;

    int *count_ptr = &count;
    
    printf("Input size of an array:\n");

    scanf("%d",n_ptr);

    printf("Size of an array is %d\n", n);
   
    int *arr = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_NUMBER;
    }

    printf("Initial array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    get_prime_count_and_min(n, arr, mini_ptr, count_ptr);
    
    printf("\nCount of prime numbers is %d\n", count);

    if (count != 0) {
        printf("Minimum of prime numbers is %d\n", mini);
    } else {
        printf("There is no prime numbers, so minimum is undefined\n");
    }
    free(arr);

    return 0;
}
