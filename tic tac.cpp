#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    int loc;
    char board[SIZE][SIZE];
    char flag = 'O';

    // Initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }

    printBoard(board);

    while (1) {
        printf("Enter location for player %c (1-9): ", flag);
        scanf("%d", &loc);

        // Convert location to board indices
        int row = (loc - 1) / SIZE;
        int col = (loc - 1) % SIZE;

        if (loc < 1 || loc > 9 || board[row][col] != '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = flag;

        // Check if current player has won
        if (checkWinner(board, flag)) {
            printBoard(board);
            printf("%c is the winner!\n", flag);
            break;
        }

        // Check for draw (board is full)
        int draw = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == '-') {
                    draw = 0;
                    break;
                }
            }
            if (!draw) break;
        }

        if (draw) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Toggle player
        flag = (flag == 'O') ? 'X' : 'O';
        printBoard(board);
    }

    return 0;
}

