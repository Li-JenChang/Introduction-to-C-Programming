// Given an undirected simple connected graph, and then check whether it is bipartite or not.
/* Input Format:
   The first line contains an integer T, representing the number of graphs.
   For each graph:
   The first line contains two integers n, m, representing the number of vertices and the number of edges.
   The next m lines contain two integers u, v, representing that there is an undirected edge between vertex u and vertex v.
   (1 <= T <= 10 ; 2 <= n <= 1000 ; n - 1 <= m <= n^2 ; 1 <= u, v <= 1000)
   (NO multiple edges between two vertices and NO self cycle)                                                               */
/* Sample Input:
   2
   
   4 4
   1 2
   2 3
   3 4
   4 1
   
   3 3
   1 2
   1 3
   2 3
   Sample Output:
   Yes
   No              */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1002

void coloring(int vertex, int mark);

int edge[SIZE][SIZE];
int color[SIZE];
int v, e, flag = 1;

int main(void)
{
    int T;
    int vertex1, vertex2, check;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &v, &e);
        flag = 1;
        for (int i = 0; i < SIZE; i++)
            color[i] = -1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                edge[i][j] = 0;
            }
        }
        while (e > 0) {
            scanf("%d%d", &vertex1, &vertex2);
            edge[vertex1][vertex2] = 1;
            edge[vertex2][vertex1] = 1;
            e--;
        }
        coloring(1, 0);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

void coloring(int vertex, int mark)
{
    if (color[vertex] == -1) color[vertex] = mark;
    else if (color[vertex] != mark) {
        flag = 0;
        return;
    }
    else return;

    for (int i = 1; i <= v; i++) {
        if (edge[vertex][i] == 1)
            coloring(i, ~mark);
    }
}
