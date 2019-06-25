#include <stdio.h>
#include <stdlib.h>

int Josephus( int n );

int main(void)
{
    int n, m;

    scanf("%d", &n);
    m = 2;

    printf("%d\n", Josephus( n ));

    return 0;
}

int Josephus( int n )
{
    if ( n == 1 ) return 1;
    else if ( n % 2 == 0 )                  // even number: f(n) = 2 * f(n / 2) - 1
        return 2 * Josephus( n / 2 ) - 1;
    else
        return 2 * Josephus( n / 2 ) + 1;   // odd number: f(n) = 2 * f((n - 1) / 2) + 1
}
