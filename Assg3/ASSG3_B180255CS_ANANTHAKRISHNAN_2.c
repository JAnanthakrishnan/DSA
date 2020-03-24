#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
int maximum(int a,int b)
{
    if(a>b)
    return a;
    else
    {
        return b;
    }
    
}
int _height(struct node * root)
{
    if(root==NULL)
        return 0;
    else
        return maximum(_height(root->left),_height(root->right))+1;
}
struct node* newnode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node * insert(struct node * root)
{
    scanf(" (");
    int val;
    if(scanf("%d",&val))
    {
        root = newnode(val);
        scanf("(");
        root->left = insert(root->left);
        scanf("(");
        root->right = insert(root->right);
    }
    scanf(" )");
    return root;
}
struct node * min(struct node * root)
{
    struct node * temp = root;
    while(temp->left!=NULL)
        temp = temp->left;
    return temp;
}
struct node * max(struct node * root)
{
    struct node * temp = root;
    while(temp->right!=NULL)
        temp = temp->right;
    return temp;
}
int is_avl(struct node * root,int *height)
{
    int lh = 0;int rh = 0;
    int l=0,r=0;
    if(root == NULL)
    {
        *height = 0;
        return 1;
    }
    l = is_avl(root->left,height);
    r = is_avl(root->right,height);
    *height = maximum(lh,rh)+1;
    int bf = lh-rh;
    if(bf<-1||bf>1)
    return 0;
    else
    {
        return l&&r;
    }
    
}
int is_bst(struct node * root,int * prev)
{
    if(root!=NULL)
    {
        is_bst(root->left,prev);
       // printf("%d %d\n",root->data,*prev);
        if(root->data<*prev)
        return 0;
        *prev = root->data;
        is_bst(root->right,prev);
    }
    else
    return 1;
}
int main()
{
    int height = 0;
    int prev = INT_MIN;
    struct node * root = NULL;
    root = insert(root);
    int f = is_avl(root,&height);
    int g = is_bst(root,&prev);

    printf("%d\n",f&&g);
}

