// Placing eight queens on an 8 * 8 chessboard such that no one can attack one another

#include <stdio.h>
#define SIZE 8     // The size of the chessboard

int q[SIZE];       // q[row] = column
int count;
void place(int row);

void show_board(void)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (q[i] == j)
                printf("@");
            else
                printf("0");
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    place(0);
    printf("number of solutions: %d\n", count);
    return 0;
}

int valid(int r, int c)
{
    for (int i = 0; i < r; i++) {
        if (q[i] == c)
            return 0;
        if (c - q[i] == r - i)
            return 0;
        if (q[i] - c == r - i)
            return 0;
    }
    return 1;
}

void place(int row)
{
    if (row >= SIZE) {
        show_board();
        count++;
    }
    else {
        for (int j = 0; j < SIZE; j++) {
            if (valid(row, j)) {
                q[row] = j;
                place(row + 1);
            }
        }
    }
}
