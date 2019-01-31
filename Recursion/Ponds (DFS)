/* Given a map sized m * n consists of two symbols '~' and '.', representing water and land respectively. Then, find out how many ponds
   (consecutive position of water) are there on the map. (1 <= m, n <= 1000) */
/* Sample Input:
   2 3
   ~.~
   ~..
   Sample Output: 2  */

#include <stdio.h>
#define size 1005

void num_ponds(int i, int j, int count);
char map[size][size];
int mark[size][size] = {0};
int m, n;

int main(void)
{
    int count = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        while (getchar() != '\n');
        for (int j = 0; j < n; j++) {
            scanf("%c", &map[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (mark[i][j] == 0 && map[i][j] == '~')
                num_ponds(i, j, ++count);
    }
    printf("%d\n", count);
    return 0;
}

void num_ponds(int i, int j, int count)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;
    if (mark[i][j] > 0 || map[i][j] != '~')
        return;
    mark[i][j] = 1;
    num_ponds(i, j - 1, count);
    num_ponds(i, j + 1, count);
    num_ponds(i - 1, j, count);
    num_ponds(i + 1, j, count);
}
