#include <stdio.h>
#include <stdlib.h>

void insertionSort( int a[], int len );
void swap( int * p, int * q );

int main(void)
{
    int * a = NULL;
    int len = 0;     // number of integers
    scanf("%d", &len);
    a = (int *) malloc( len * sizeof(int) );
    for ( int i = 0; i < len; i++ ) {
        scanf("%d", &a[i]);
    }
    insertionSort( a, len );
    for ( int i = 0; i < len; i++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

// The recursive version of insertion sort

void insertionSort( int a[], int len )
{
    // Termination condition
    if ( len == 1 ) return;
    // Recursive step
    insertionSort( a, len - 1 );
    // Insert a[len - 1] to the correct place
    for ( int i = len - 1; i > 0 && a[i - 1] > a[i]; i-- ) {
        swap( &a[i - 1], &a[i] );
    }
}

void swap( int * p, int * q )
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
