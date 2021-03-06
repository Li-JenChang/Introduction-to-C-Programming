// Convert Prefix Notation into Infix Notation and Calculate the Answer
// Input Format: * + 2 3 + 4 + - 5 6 - 7 8       [prefix]
// ((2 + 3) * ( 4 + ((5 - 6) + (7 - 8)))) = 10   [infix]

#include <stdio.h>
#include <ctype.h>

int calculate(void);
int main(void)
{
    int ans;
    ans = calculate();
    printf(" = %d\n", ans);
    return 0;
}

int calculate(void)
{
    int ans, A, B;
    char c;
    c = getchar();
    if (isspace(c)) {         // c == ' ' || c == '\t' || c == '\n'
        ans = calculate();
    }
    else if (c == '+') {
        printf("(");
        A = calculate();
        printf(" + ");
        B = calculate();
        printf(")");
        ans = A + B;
    }
    else if (c == '-') {
        printf("(");
        A = calculate();
        printf(" - ");
        B = calculate();
        printf(")");
        ans = A - B;
    }
    else if (c == '*') {
        printf("(");
        A = calculate();
        printf(" * ");
        B = calculate();
        printf(")");
        ans = A * B;
    }
    else if (c == '/') {
        printf("(");
        A = calculate();
        printf(" / ");
        B = calculate();
        printf(")");
        ans = A / B;
    }
    else if (isdigit(c)) {
        ungetc(c, stdin);     // In order to read the numbers that are more than one digit
        scanf("%d", &ans);    // Put c back to stdin and use scanf to read the whole part of the number
        printf("%d", ans);
    }
    return ans;
}
