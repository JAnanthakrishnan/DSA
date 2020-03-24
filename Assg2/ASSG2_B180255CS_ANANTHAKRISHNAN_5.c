#include <stdio.h>
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
int maximum(int a,int b)
{
    return (a>=b)?a:b;
}
int long_path(struct node* root,int * height)
{
    int lh = 0;
    int rh = 0;
    int rd = 0;
    int ld = 0;
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }
    ld = long_path(root->left,&lh);
    rd = long_path(root->right,&rh);
    *height = maximum(lh,rh)+1;
    return maximum(lh+rh+1,maximum(ld,rd));  
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
int main()
{
    struct node * root = NULL;
    root = insert(root);
    //preorder(root);
    int height = 0;
    int path = long_path(root,&height);
    printf("%d %d\n",height-1,path-1);
    
}