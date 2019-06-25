// Placing three rooks on a 3 * 3 chessboard such that no one can attack each other

#include <stdio.h>
#define SIZE 3     // The size of the chessboard

int board[SIZE + 2][SIZE + 2];
void place(int row);

void show_board(void)
{
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    place(1);
    return 0;
}

int valid(int r, int c)
{
    for (int i = 0; i < r; i++) {
        if (board[i][c])
            return 0;
    }
    return 1;
}

void place(int row)
{
    if (row > SIZE) {
        show_board();
    }
    else {
        for (int j = 1; j <= SIZE; j++) {
            if (valid(row, j)) {
                board[row][j] = 1;
                place(row + 1);
                board[row][j] = 0;
            }
        }
    }
}
