#include <stdio.h>
#include <stdlib.h>

enum status { DEAD, ALIVE };

int main(void)
{
    int n, m;
    int *people, *mark;
    int current, remain, count;

    scanf("%d%d", &n, &m);

    people = ( int * ) malloc( n * sizeof( int ) );
    mark = ( int * ) malloc( n * sizeof( int ) );

    for ( int i = 0; i < n; i++ ) {
        people[i] = i + 1;
        mark[i] = ALIVE;
    }
    current = 0;
    remain = n;

    while ( remain > 1 ) {
        for ( count = 0; count < m; ) {
            if ( mark[current] == ALIVE ) count++;
            if ( count < m ) {
                current++;
                if ( current >= n ) current = 0;
            }
        }
        mark[current] = DEAD;
        remain--;
    }

    for ( int i = 0; i < n; i++ ) {
        if ( mark[i] == ALIVE ) {
            printf("%d\n", people[i]);
            break;
        }
    }

    return 0;
}
