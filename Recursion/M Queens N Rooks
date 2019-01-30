// Placing M queens and N rooks on a (M + N) * (M + N) chessboard such that no one can attack one another

#include <stdio.h>
#define SIZE 15      // The maximum size of the chessboard

void place(int row);
int queenValid(int r, int c);
int rookValid(int r, int c);
int board[SIZE + 2][SIZE + 2];     // 0 for nothing, 1 for rook, and 2 for queen
int count = 0;
int M, N;
int queenCount = 0, rookCount = 0;

int main(void)
{
    scanf("%d%d", &M, &N);
    place(1);
    printf("%d\n", count);
    return 0;
}

void place(int row)
{
    if (row > M + N) {
        count++;
    }
    else {
        for (int j = 1; j <= M + N; j++) {
            if (queenValid(row, j)) {
                board[row][j] = 2;
                queenCount++;
                place(row + 1);
                board[row][j] = 0;
                queenCount--;
            }
            if (rookValid(row, j)) {
                board[row][j] = 1;
                rookCount++;
                place(row + 1);
                board[row][j] = 0;
                rookCount--;
            }
        }
    }
}

int queenValid(int r, int c)
{
    if (queenCount >= M) return 0;     // No available queens
    for (int i = 1; i < r; i++) {
        if (board[i][c] == 1 || board[i][c] == 2)     // This column had been placed other rooks or queens
            return 0;
    }
    // Check whether the two diagonal directions had been placed other rooks or queens
    for (int i = r - 1, j = c - 1; i >= 1 && j >= 1; i--, j--) {
        if (board[i][j] == 1 || board[i][j] == 2)
            return 0;
    }
    for (int i = r - 1, j = c + 1; i >= 1 && j <= M + N; i--, j++) {
        if (board[i][j] == 1 || board[i][j] == 2)
            return 0;
    }
    return 1;
}

int rookValid(int r, int c)
{
    if (rookCount >= N) return 0;     // No available rooks
    for (int i = 1; i < r; i++) {
        if (board[i][c] == 1 || board[i][c] == 2)     // This column had been placed other rooks or queens
            return 0;
    }
    // Check whether the two diagonal directions had been placed other queens (Rook does not matter)
    for (int i = r - 1, j = c - 1; i >= 1 && j >= 1; i--, j--) {
        if (board[i][j] == 2)
            return 0;
    }
    for (int i = r - 1, j = c + 1; i >= 1 && j <= M + N; i--, j++) {
        if (board[i][j] == 2)
            return 0;
    }
    return 1;
}
