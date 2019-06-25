#include <stdio.h>
#include <stdlib.h>

void bubbleSort( int a[], int len );
void swap( int * p, int * q );

int main(void)
{
    int * a = NULL;
    int len = 0;
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

// The loop version of bubble sort

void bubbleSort( int a[], int len )
{
    for ( int i = len - 1; i >= 0; i-- ) {
        for ( int j = 0; j < i; j++ ) {
            if ( a[j] > a[j + 1] )
                swap( &a[j], &a[j + 1] );
        }
    }
}

void swap( int * p, int * q )
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
