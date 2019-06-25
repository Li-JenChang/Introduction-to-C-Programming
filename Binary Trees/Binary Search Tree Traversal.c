#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void create_tree( Node **root, int n );
void print_tree( Node *root );
void destroyTree( Node *root );
void insert( Node *root, Node **p );
void preOrder( Node *root );
void inOrder( Node *root );
void postOrder( Node *root );

void destroyTree( Node *root )
{
    if ( root != NULL ) {
        destroyTree( root->left );
        destroyTree( root->right );
        free( root );
    }
}

int main(void)
{
    int n;
    Node *root = NULL;
    scanf("%d",&n);
    create_tree( &root, n );
    print_tree( root );
    destroyTree( root );
    return 0;
}

void create_tree( Node **root, int n )
{
    if ( n > 0 ) {
        int number;
        scanf("%d", &number);
        Node *p = ( Node * ) malloc( sizeof( Node ) );
        p->data = number;
        p->left = NULL;
        p->right = NULL;
        if ( *root == NULL ) {
            *root = p;
        }
        else {
            insert( *root, &p );
        }
        create_tree( root, n - 1 );
    }
}

void insert( Node *root, Node **p )
{
    if ( ( (*p)->data < root->data ) && root->left != NULL ) {
        insert( root->left, p );
    }
    else if ( ( (*p)->data < root->data ) && root->left == NULL ) {
        root->left = *p;
    }
    else if ( ( (*p)->data > root->data ) && root->right != NULL ) {
        insert( root->right, p );
    }
    else if ( ( (*p)->data > root->data ) && root->right == NULL ) {
        root->right = *p;
    }
}

void print_tree( Node *root )
{
    if ( root != NULL ) {
        printf("preorder:");
        preOrder( root );
        printf("\n");
        printf("inorder:");
        inOrder( root );
        printf("\n");
        printf("postorder:");
        postOrder( root );
        printf("\n");
    }
}

void preOrder( Node *root )
{
    if ( root != NULL ) {
        printf(" %d", root->data);
        preOrder( root->left );
        preOrder( root->right );
    }
}

void inOrder( Node *root )
{
    if ( root != NULL ) {
        inOrder( root->left );
        printf(" %d", root->data);
        inOrder( root->right );
    }
}

void postOrder( Node *root )
{
    if ( root != NULL ) {
        postOrder( root->left );
        postOrder( root->right );
        printf(" %d", root->data);
    }
}
