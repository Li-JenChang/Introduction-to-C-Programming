// Make Change
// Input number of different values of coins, all the values of coins, and the amount of money that needs to be made change for
// Output all kinds of ways of making change

#include <stdio.h>
#include <stdlib.h>
#define MAXNV 6     // nv denotes the number of different values of coins

int values[MAXNV];
int numbers[MAXNV];

void show(int nv);
void change(int amount, int smallest, int nv);
int compare(const void * a, const void * b);

int main(void)
{
    int nv, money;
    scanf("%d", &nv);
    if (nv > MAXNV || nv < 1) return 0;
    for (int i = 0; i < nv; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%d", &money);
    qsort(values, nv, sizeof(int), compare);     // Sort the values in ascending order
    change(money, 0, nv);
    return 0;
}

void show(int nv)
{
    printf("(%d", numbers[0]);
    for (int i = 1; i < nv; i++)
        printf(",%d", numbers[i]);
    printf(")\n");
}

void change(int amount, int smallest, int nv)
{
    if (smallest < nv) {
        if (amount == 0) {
            show(nv);
        }
        else if (amount > 0) {
            change(amount, smallest + 1, nv);

            numbers[smallest]++;
            change(amount - values[smallest], smallest, nv);
            numbers[smallest]--;
        }
    }
}

int compare(const void * a, const void * b)
{
    int * pa = (int *) a;
    int * pb = (int *) b;
    if (*pa > *pb) return 1;
    else if (*pa < *pb) return -1;
    else return 0;
}
