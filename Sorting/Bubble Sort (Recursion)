#include <stdio.h>
#include <stdlib.h>

void bubbleSort( int a[], int len );
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
    bubbleSort( a, len );
    for ( int i = 0; i < len; i++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

// The recursive version of bubble sort

void bubbleSort( int a[], int len )
{
    // Termination condition
    if ( len == 1 ) return;
    // Put maximum value to a[len - 1]
    for ( int i = 1; i < len; i++ ) {
        if ( a[i - 1] > a[i] )
            swap( &a[i - 1], &a[i] );
    }
    // Recursive step
    bubbleSort( a, len - 1 );
}

void swap( int * p, int * q )
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
