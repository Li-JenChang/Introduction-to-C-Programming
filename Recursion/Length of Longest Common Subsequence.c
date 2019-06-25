// Length of Longest Common Subsequence
// Input two lines of strings and then output the length of their longest common subsequence

#include <stdio.h>
#include <string.h>

int LCS(int i, int j);
char a[1100];
char b[1100];

int main(void)
{
    char ch, chs, ch_b;
    int i;
    while ((ch = getchar()) != EOF) {
        a[0] = ch;
        i = 1;
        while ((chs = getchar()) != '\n') {
            a[i] = chs;
            i++;
        }
        a[i] = '\0';
        i = 0;
        while ((ch_b = getchar()) != '\n') {
            b[i] = ch_b;
            i++;
        }
        b[i] = '\0';
        printf("%d\n", LCS(0, 0));
    }
}

int MAX(int x, int y)
{
    return (x > y)? x : y;
}

int LCS(int i, int j)
{
    if (i >= strlen(a) || j >= strlen(b))
        return 0;
    if (a[i] == b[j]) {
        return 1 + LCS(i + 1, j + 1);
    }
    else {
        return MAX(LCS(i + 1, j), LCS(i, j + 1));
    }
}
