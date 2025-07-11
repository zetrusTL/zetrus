CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

BUILD_DIR = .


all: s21_cat

s21_cat: cat.c CatFlags.c CatFlags.h
	$(CC) $(CFLAGS) cat.c CatFlags.c -o $(BUILD_DIR)/s21_cat

clean:
	rm -f *.o $(BUILD_DIR)/s21_cat

de: clean all