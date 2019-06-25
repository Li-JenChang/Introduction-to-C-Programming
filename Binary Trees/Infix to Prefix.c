/* This program constructs a syntax tree from an infix Boolean expression (with parenthesis).
   EXPR = FACTOR | EXPR OP FACTOR
   FACTOR = ID | (EXPR)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];     // string to store the input expression
int pos;                // current position of parsing, from end to start

typedef enum { ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR } TokenSet;
char sym[NUMSYM] = "ABCD&|";

typedef struct _node {
    TokenSet data;
    struct _node * left;
    struct _node * right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* newNode( char c );
void freeTree( BTNode * root );
void printPrefix( BTNode * root );

int main(void)
{
    size_t len;
    fgets( expr, sizeof( expr ), stdin );
    len = strlen( expr );
    if ( len > 0 && expr[len-1] == '\n' ) {
        --len;
        expr[len] = '\0';
    }
    pos = strlen( expr ) - 1;
    BTNode *root = EXPR();
    printPrefix( root );
    freeTree( root );
    return 0;
}

/* EXPR = FACTOR | EXPR OP FACTOR */

BTNode* EXPR()
{
    char c;
    BTNode *node = NULL, *right = NULL;
    if ( pos >= 0 ) {
        right = FACTOR();    // 1. EXPR = FACTOR

        if ( pos > 0 ) {     // 2. the EXPR OP FACTOR case
            c = expr[pos];
            if ( c == '&' || c == '|' ) {
                node = newNode( c );
                node->right = right;
                pos--;
                node->left = EXPR();
            }
            else
                node = right;     // 1. EXPR = FACTOR
        }
        else
            node = right;     // 1. EXPR = FACTOR
    }
    return node;
}

/* FACTOR = ID | (EXPR) */

BTNode* FACTOR()
{
    char c;
    BTNode *node = NULL;

    if ( pos >= 0 ) {
        c = expr[pos--];
        if ( c >= 'A' && c <= 'D' ) {     // FACTOR = ID
            node = newNode( c );
        }
        else if ( c == ')' ) {     // FACTOR = (EXPR)
            node = EXPR();

            if ( expr[pos--] != '(' ) {     // The left parenthesis is needed.
                printf("Error: not matching parenthesis!\n");
                freeTree( node );
            }
        }
    }
    return node;
}

BTNode* newNode( char c )
{
    BTNode *node = ( BTNode * ) malloc( sizeof( BTNode ) );
    for (int i = 0; i < NUMSYM; i++ )
        if ( c == sym[i] ) node->data = i;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void freeTree( BTNode *root )
{
    if ( root != NULL ) {
        freeTree( root->left );
        freeTree( root->right );
        free( root );
    }
}

void printPrefix( BTNode *root )
{
    if ( root != NULL ) {
        printf("%c", sym[root->data]);
        printPrefix( root->left );
        printPrefix( root->right );
    }
}
