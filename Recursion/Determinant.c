// Given a n * n square matrix A, and then calculate the determinant of A. (Denoted by det(A))
/* Input Format:
   The first line contains one integer n, representing the size of A.
   For the next n lines, each line contains n integers, representing each entry in A. (1 <= n <= 8)  */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 8     // The maximum size of the matrix

void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n);
long long determinant(int matrix[SIZE][SIZE], int n);

int main(void)
{
    int n;
    int A[SIZE][SIZE];
    long long ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    ans = determinant(A, n);
    printf("%lld\n", ans);
    return 0;
}

void get_cofactor(int matrix[SIZE][SIZE], int temp[SIZE][SIZE], int p, int q, int n)
{
    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Copying into temporary matrix only those elements which are not in given row and column
            if (i != p && j != q) {
                temp[row][col] = matrix[i][j];
                col++;
                // Current row is completely filled
                if (col == n - 1) {
                    row++;
                    col = 0;
                }
            }
        }
    }
}

long long determinant(int matrix[SIZE][SIZE], int n)
{
    long long det = 0;
    int temp[SIZE][SIZE];
    int sign = 1;
    if (n == 1)
        return matrix[0][0];
    for (int j = 0; j < n; j++) {
        get_cofactor(matrix, temp, 0, j, n);
        det += sign * matrix[0][j] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}
