/* Use recursive function to find the number of times the second string occurs as a subsequence of the first string,
   whether continuously or discontinuously. (The length of each string < 30) */
// Sample Input: abcabc abc
// Sample Output: 4

#include <stdio.h>
#include <string.h>

int match_pt(int i, int j);
char a[30], b[30];

int main(void)
{
    char ch, ch_a, ch_b;
    int i;
    while ((ch = getchar()) != EOF) {
        a[0] = ch;
        i = 1;
        while ((ch_a = getchar()) != ' ') {
            a[i] = ch_a;
            i++;
        }
        a[i] = '\0';
        i = 0;
        while ((ch_b = getchar()) != '\n') {
            b[i] = ch_b;
            i++;
        }
        b[i] = '\0';
        printf("%d\n", match_pt(0, 0));
    }
    return 0;
}

int match_pt(int i, int j)
{
    if (strlen(a) >= strlen(b)) {
        if (j == strlen(b))
            return 1;
        if (i == strlen(a))
            return 0;
        if (a[i] == b[j])
            return match_pt(i + 1, j + 1) + match_pt(i + 1, j);
        else
            return match_pt(i + 1, j);
    }
    else
        return 0;
}
