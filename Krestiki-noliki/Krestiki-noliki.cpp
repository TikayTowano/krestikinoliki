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

int checkWin(char board[SIZE][SIZE]) {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    // Проверка диагоналей
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;
    char playAgain;

    do {
        currentPlayer = 'X';
        moves = 0;

        while (1) {
            printBoard(board);
            printf("Игрок %c, введите строку и столбец (0-2): ", currentPlayer);
            scanf_s("%d %d", &row, &col);
