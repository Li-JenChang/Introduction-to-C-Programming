// Convert decimal representation into binary representation

#include <stdio.h>

void dec_to_bin(int x);

int main(void)
{
    int z;
    while (scanf("%d", &z) == 1) {
        dec_to_bin(z);
        printf("\n");
    }
    return 0;
}

void dec_to_bin(int x)
{
    if (x > 0) {
        dec_to_bin(x / 2);
        if (x % 2) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}
