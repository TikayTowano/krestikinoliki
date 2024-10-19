#include <stdio.h>
#include <locale.h>

char board[3][3]; // ������� ����
char currentPlayer; // ������� �����

// ������� ��� ������������� �������� ����
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// ������� ��� ����������� �������� ����
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

// ������� ��� �������� ����������
int checkWinner() {
    // �������� ����� � �������� for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
        return 1; // ������
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
        return 1; // ������
    }
}
// �������� ����������
if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1; // ������
}
if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return 1; // ������
}
return 0; // ��� ����������
}

// ������� ��� �������� ������
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // ���� ��������� ������ }
            }
        }
        return 1; // �����
    }

    int main() {
        setlocale(LC_ALL, "Rus");
        int row, col;
        currentPlayer = 'X';
        initializeBoard();

        while (1) {
            displayBoard();
            printf("����� %c, ������� ������ � ������� (0-2): ", currentPlayer);
            scanf("%d %d", &row, &col);

            // �������� �� ������������ ���� if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("�������� ���. ���������� �����.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner()) {
            displayBoard();
            printf("����� %c �������!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("�����!\n");
            break;
        }

        // ����� ������
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
