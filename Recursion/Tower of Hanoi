// Tower of Hanoi

#include <stdio.h>

void hanoi(int from, int to, int buffer, int n);

int main(void)
{
    int n;
    printf("Number of disks: ");
    scanf("%d", &n);
    hanoi(1, 3, 2, n);

    return 0;
}

// Move n disks from a to b using c as a buffer 

void hanoi(int a, int b, int c, int n)
{
    if (n > 0) {
        hanoi(a, c, b, n - 1);                                           // Move the top n-1 disks from a to c 
        printf("Move the top disk from Tower %d to Tower %d\n", a, b);   // Move the last disk from a to b
        hanoi(c, b, a, n - 1);                                           // Move the top n-1 disks from c to b 
    }
}

// If there are n disks, we need to move at least 2^(n) - 1 times
