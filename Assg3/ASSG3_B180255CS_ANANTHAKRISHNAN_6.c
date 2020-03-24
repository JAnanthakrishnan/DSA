#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int ht;
    int count;
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
int __height(struct node *root)
{
    if(root==NULL)
    return 0;
    return root->ht;   
}
struct node* newnode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->ht = 1;
    temp->count = 1;
    return temp;
}
struct node * rightrotate(struct node * y)
{
    struct node * x = y->left;
    struct node * T2 = x->right;
    x->right = y;
    y->left = T2;
    y->ht = maximum(__height(y->left),__height(y->right))+1;
    x->ht = maximum(__height(x->left),__height(x->right))+1;
    return x;
}
struct node * leftrotate(struct node * x)
{
    struct node * y = x->right;
    struct node * T2 = y->left;
    y->left = x;
    x->right = T2;
    y->ht = maximum(__height(y->left),__height(y->right))+1;
    x->ht = maximum(__height(x->left),__height(x->right))+1;
    return y;
}
int getbalancef(struct node * root)
{
    if(root==NULL)
    return 0;
    int bf = __height(root->left)-__height(root->right);
    return bf;
}
struct node * insert(struct node * root,int data)
{
    if(root==NULL)
        return newnode(data);
    if(data<root->data)
        root->left = insert(root->left,data);
    else if(data>root->data)
        root->right = insert(root->right,data);
    else
    {
        root->count = root->count+1;
        return root;
    }
    root->ht = maximum(__height(root->left),__height(root->right))+1;
    int bf = getbalancef(root);
    if(bf>1)
    {
        if(data<root->left->data)
            return rightrotate(root);
        else if(data>root->left->data)
        {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }
    }
    if(bf<-1)
    {
        if(data>root->right->data)
            return leftrotate(root);
        else if(data<root->right->data)
        {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
    }
    return root;
}
struct node * min(struct node * root)
{
    struct node * temp = root;
    while(temp->left!=NULL)
        temp = temp->left;
    return temp;
}
struct node * delete(struct node * root,int data)
{
    if(root==NULL)
        return NULL;
    if(data<root->data)
        root->left = delete(root->left,data);
    else if(data>root->data)
        root->right = delete(root->right,data);
    else
    {
        if((root->left==NULL)||(root->right==NULL))
        {
            struct node * temp = root->left?root->left:root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }  
    }
    if(root==NULL)
    return root;
    root->ht = 1+maximum(__height(root->left),__height(root->right))+1;
    int bf = getbalancef(root);
    if(bf>1)
    {
        if(getbalancef(root->left)>=0)
        {
            return rightrotate(root);
        }
        else
        {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }      
    }
    if(bf<-1)
    {
        if(getbalancef(root->right)<=0)
        {
            return leftrotate(root);
        }
        else
        {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }       
    }    
    return root;
}
void preorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        int n = root->count;
        while(n!=0)
        {
            printf("%d ",root->data);
            n--;
        }
        inorder(root->right);
    }
}
int main()
{
    struct node *root = NULL; 
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        root = insert(root,k);
    }
    inorder(root);
    printf("\n");
}
