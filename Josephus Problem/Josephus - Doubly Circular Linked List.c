// Change directions ( clockwise <--> counterclockwise ) each time

#include <stdio.h>
#include <stdlib.h>

typedef struct man {
    int id;
    struct man * next;
    struct man * prev;
} man;

man * head;
man * createList( int n );
int solveJosephus( int step );


int main(void)
{
    int n, m;

    while ( scanf("%d%d", &n, &m) != EOF ) {
        head = createList( n );
        printf("%d\n", solveJosephus( m ));
    }

    return 0;
}

man * createList( int n )
{
    man * p = ( man * ) malloc( sizeof( man ) );
    p->id = 1;
    p->next = p;
    p->prev = p;
    man * current = p;

    for ( int i = 2; i <= n; i++ ) {
        current->next = ( man * ) malloc( sizeof( man ) );
        current->next->prev = current;
        current = current->next;
        current->id = i;
    }
    current->next = p;
    p->prev = current;

    return p;
}

int solveJosephus( int step )
{
    man * current = head, * temp = head;
    enum { clockwise, counter_clockwise };
    int dir = clockwise;
    while ( current->next != current ) {
        if ( dir == clockwise ) {
            for ( int i = 1; i < step; i++ ) {
                temp = current;
                current = current->next;
            }

            temp->next = current->next;
            current->next->prev = temp;
            free( current );

            current = temp;
            dir = counter_clockwise;
        }
        else if ( dir == counter_clockwise ) {
            for ( int i = 1; i < step; i++ ) {
                temp = current;
                current = current->prev;
            }

            temp->prev = current->prev;
            current->prev->next = temp;
            free( current );

            current = temp;
            dir = clockwise;
        }
    }
    return current->id;
}
