#include <stdio.h>
#include <stdlib.h>
struct node{
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
int main()
{
    struct node * root = newnode(5);
    root->left = newnode(10);
    root->right = newnode(12);
    root->left->left = newnode(30);
    root->left->right = newnode(32);
    root->left->left->left = newnode(20);
    root->left->left->left->left = newnode(55);
    int h = _height(root);
    printf("%d",h);

}