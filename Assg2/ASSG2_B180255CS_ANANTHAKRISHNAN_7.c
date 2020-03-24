#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* _newnode(int val)
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;

}
struct node * insert(struct node * root)
{
    scanf(" (");
    int data;
    if(scanf("%d",&data)==1)
    {
        
        root = _newnode(data);
        root->left=insert(root->left);
        scanf(")");
        root->right=insert(root->right);
        scanf(")");
    }
    scanf(" )");
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

int largest_bst(struct node * root,int * max,int * min,int * is_bst,int * max_size)
{
    if(root == NULL)
    {
        *is_bst = 1;
        return 0;
    }
    //int min_in = INT_MAX;
    int left_flag = 0;
    int right_flag = 0;
    int left_size,right_size;

    *max = INT_MIN;
    left_size = largest_bst(root->left,max,min,is_bst,max_size);
    if(*is_bst==1&&root->data>*max)
    left_flag=1;

    //min_in = *min;
    *min = INT_MAX;
    right_size = largest_bst(root->right,max,min,is_bst,max_size);
    if(*is_bst==1&&root->data<*min)
    right_flag=1;

    //if(min_in<*min)
    //*min = min_in;
    if(*min>root->data)
    *min = root->data;
    if(*max<root->data)
    *max = root->data;

    if(left_flag && right_flag)
    {
        if(left_size+right_size+1>*max_size)
        *max_size = left_size+right_size+1;
        return left_size+right_size+1;
    }
    else
    {
        *is_bst = 0;
        return 0;
    }
    
}

int maxbst_size(struct node * root)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int is_bst = 0;
    int max_size = 0;
    largest_bst(root,&max,&min,&is_bst,&max_size);
    return max_size;
}

int main()
{
    struct node * root = NULL;
    root = insert(root);
    //preorder(root);
    int n = maxbst_size(root);
    printf("%d\n",n); 
}