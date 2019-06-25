#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int next;
} Person;

int main(void)
{
    int n, m;
    int current, remain, temp;
    Person * people;

    scanf("%d%d", &n, &m);
    people = ( Person * ) malloc( n * sizeof( Person ) );
    for ( int i = 0; i < n; i++ ) {
        people[i].id = i + 1;
        people[i].next = i + 1;
    }
    people[n - 1].next = 0;

    current = 0;
    remain = n;
    while ( remain > 1 ) {
        for ( int i = 1; i < m; i++ ) {
            temp = current;
            current = people[current].next;
        }
        people[temp].next = people[current].next;
        current = people[current].next;
        remain --;
    }

    printf("%d\n", people[current].id);

    free(people);
    return 0;
}
