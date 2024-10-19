// Krestiki-noliki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <locale.h>
#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    setlocale(LC_ALL, "Rus");
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}