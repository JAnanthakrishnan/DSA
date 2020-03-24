#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * _newnode(int val)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}


struct node * insert(struct node * root)
{
    scanf(" (");
    int data;
    if(scanf("%d",&data)==1)
    {
        
        root = _newnode(data);
        root->right=insert(root->left);
       scanf(")");
        root->left=insert(root->right);
       scanf(")");
    }
    scanf(" )");
    return root;
}

void print_mirror(struct node * root)
{
    if(root==NULL)
    {
        printf("( ) ");
    }
    if(root!=NULL){
    printf("( ");
    printf("%d ",root->data);
    print_mirror(root->left);
    print_mirror(root->right);
    printf(") ");
    }
}
int main()
{
    struct node * root = NULL;
    root = insert(root);
    print_mirror(root);
    printf("\n");
}