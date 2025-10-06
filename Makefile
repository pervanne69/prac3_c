# -----------------------------------------------------
# Makefile для Практической работы №5
# Автор: Pogosian Samvel (23К0180)
# Дата: 06/10/2025
# -----------------------------------------------------

CC = gcc

# Цели по умолчанию
all: main main2 one-dimension-arr two-dimension-arr

# Сборка main
main: main.c
	$(CC) $(CFLAGS) main.c -o main

# Сборка main2
main2: main2.c
	$(CC) main2.c -o main2

one-dimension-arr: one-dimension-arr.c
	$(CC) one-dimension-arr.c -o one-dimension-arr

two-dimension-arr: two-dimension-arr.c
	$(CC) two-dimension-arr.c -o two-dimension-arr

# Очистка скомпилированных файлов
clean:
	rm -f main main2 one-dimension-arr two-dimension-arr
