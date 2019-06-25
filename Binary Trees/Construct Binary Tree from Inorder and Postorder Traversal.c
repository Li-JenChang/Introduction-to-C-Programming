#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree( int *inorder, int *postorder, int N );
void showPreorder( Node *root );
int indexSearch( int *a, int start, int end, int value );
Node* createTree( int *inorder, int *postorder, int inorder_start, int inorder_end, int *postorderIndex );

void freeTree(Node *root)
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
    int *inorder, *postorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = ( int * ) malloc( n * sizeof( int ) );
    postorder = ( int * ) malloc( n * sizeof( int ) );
    for ( i = 0; i < n; i++ ) scanf("%d", &inorder[i]);
    for ( i = 0; i < n; i++ ) scanf("%d", &postorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree( inorder, postorder, n );
    /*------------Print out the tree ------------*/
    showPreorder( root );
    freeTree( root );
    free( inorder );
    free( postorder );

    return 0;
}

Node* buildTree( int *inorder, int *postorder, int N )
{
    int inorder_start = 0, inorder_end = N - 1;
    int postorderIndex = N - 1;
    return createTree( inorder, postorder, inorder_start, inorder_end, &postorderIndex );
}

Node* createTree( int *inorder, int *postorder, int inorder_start, int inorder_end, int *postorderIndex )
{
     if ( inorder_start > inorder_end ) return NULL;     // empty subtree

     Node *p = ( Node * ) malloc( sizeof( Node ) );
     p->data = postorder[(*postorderIndex)--];
     p->left = NULL;
     p->right = NULL;

     if ( inorder_start == inorder_end ) return p;     // leaf
     else {
        int inorderIndex = indexSearch( inorder, inorder_start, inorder_end, p->data );
        p->right = createTree( inorder, postorder, inorderIndex + 1, inorder_end, postorderIndex );
        p->left = createTree( inorder, postorder, inorder_start, inorderIndex - 1, postorderIndex );
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

void showPreorder( Node *root )
{
    if ( root != NULL ) {
        printf("%d ", root->data);
        showPreorder( root->left );
        showPreorder( root->right );
    }
}
