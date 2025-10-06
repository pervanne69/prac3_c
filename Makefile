# -----------------------------------------------------
# Makefile для Практической работы №5
# Автор: Pogosian Samvel (23К0180)
# Дата: 06/10/2025
# -----------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Цели по умолчанию
all: main main2

# Сборка main
main: main.c
	$(CC) $(CFLAGS) main.c -o main

# Сборка main2
main2: main2.c
	$(CC) $(CFLAGS) main2.c -o main2

# Очистка скомпилированных файлов
clean:
	rm -f main main2
