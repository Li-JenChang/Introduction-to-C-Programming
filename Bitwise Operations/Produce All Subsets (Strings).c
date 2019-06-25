// Produce All Subsets (Strings)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, lim;
    char str[16][10];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", str[i]);
    }
    lim = 1 << N;
    for (i = 0; i < lim; i++) {
        for (j = 0; j < N; j++) {
            if ((i & (1 << j)) != 0) {
                printf("%s ", str[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
