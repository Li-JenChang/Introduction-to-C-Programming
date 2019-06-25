#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree(int *inorder, int *preorder, int inorder_start, int inorder_end);
void showPostorder(Node *root);
void freeTree(Node *root);

int indexSearch( int *a, int start, int end, int value );

void freeTree( Node *root )
{
    if ( root != NULL ) {
        freeTree( root->left );
        freeTree( root->right );
        free( root );
    }
}

int main(void)
{

    int i, n;
    int *inorder, *preorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = ( int * ) malloc( n * sizeof( int ) );
    preorder = ( int * ) malloc( n * sizeof( int ) );
    for ( i = 0; i < n; i++ ) scanf("%d", &inorder[i]);
    for ( i = 0; i < n; i++ ) scanf("%d", &preorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree( inorder, preorder, 0, n - 1 );
    /*------------Print out the tree ------------*/
    showPostorder( root );
    freeTree( root );
    free( inorder );
    free( preorder );
    return 0;
}

Node* buildTree( int *inorder, int *preorder, int inorder_start, int inorder_end )
{
    static int preorderIndex = 0;     // We must remember the previous position of the preorder array
    if ( inorder_start > inorder_end ) return NULL;

    Node *p = ( Node * ) malloc( sizeof( Node ) );
    p->data = preorder[preorderIndex++];
    p->left = NULL;
    p->right = NULL;

    if ( inorder_start == inorder_end ) return p;
    else {
        int inorderIndex = indexSearch( inorder, inorder_start, inorder_end, p->data );
        p->left = buildTree( inorder, preorder, inorder_start, inorderIndex - 1 );
        p->right = buildTree( inorder, preorder, inorderIndex + 1, inorder_end );
        return p;
    }
}

int indexSearch( int *a, int start, int end, int value )
{
    for ( int i = start; i < end; i++ ) {
        if ( a[i] == value )
            return i;
    }
}

void showPostorder( Node *root )
{
    if ( root != NULL ) {
        showPostorder( root->left );
        showPostorder( root->right );
        printf("%d ", root->data);
    }
}
