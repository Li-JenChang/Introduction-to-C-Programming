#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int id;
    struct _person * next;
} Person;

int main(void)
{
    int n, m, remain;
    Person * head, * current, * temp;

    scanf("%d%d", &n, &m);

    head = ( Person * ) malloc( sizeof( Person ) );
    head->id = 1;
    head->next = head;
    current = head;

    for ( int i = 2; i <= n; i++ ) {
        current->next = ( Person * ) malloc( sizeof( Person ) );
        current = current->next;
        current->id = i;
    }
    current->next = head;

    current = head;
    while ( current->next != current ) {
        for ( int i = 1; i < m; i++ ) {
            temp = current;
            current = current->next;
        }
        temp->next = current->next;
        free( current );
        current = temp->next;
    }
    printf("%d\n", current->id);

    free( current );
    return 0;
}
