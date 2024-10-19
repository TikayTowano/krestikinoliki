#include <stdio.h>
#include <locale.h>

char board[3][3]; // Игровое поле
char currentPlayer; // Текущий игрок

// Функция для инициализации игрового поля
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Функция для отображения игрового поля
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Функция для проверки победителя
int checkWinner() {
    // Проверка строк и столбцов for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
        return 1; // Победа
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
        return 1; // Победа
    }
}
// Проверка диагоналей
if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1; // Победа
}
if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return 1; // Победа
}
return 0; // Нет победителя
}

// Функция для проверки ничьей
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Есть свободные клетки }
            }
        }
        return 1; // Ничья
    }

    int main() {
        setlocale(LC_ALL, "Rus");
        int row, col;
        currentPlayer = 'X';
        initializeBoard();

        while (1) {
            displayBoard();
            printf("Игрок %c, введите строку и столбец (0-2): ", currentPlayer);
            scanf("%d %d", &row, &col);

            // Проверка на допустимость хода if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Неверный ход. Попробуйте снова.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner()) {
            displayBoard();
            printf("Игрок %c выиграл!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("Ничья!\n");
            break;
        }

        // Смена игрока
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
