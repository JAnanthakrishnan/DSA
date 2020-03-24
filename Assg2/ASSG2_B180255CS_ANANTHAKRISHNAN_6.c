#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int sum;
    struct node* left;
    struct node* right;
};
struct node* _newnode(int val)
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->sum = 0;
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
int mksum(struct node * root)
{
   if(root==NULL)
   {
       return 0;
   }
   root->sum = root->data + mksum(root->left) + mksum(root->right);
   return root->sum;
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
void print_string(struct node * root)
{
    if(root==NULL)
    {
        printf("( ) ");
    }
    if(root!=NULL){
    printf("( ");
    printf("%d ",root->sum);
    print_string(root->left);
    print_string(root->right);
    printf(") ");
    }
}
int main()
{
    struct node * root = NULL;
    root = insert(root);
   // preorder(root);
    mksum(root);
    print_string(root);
    printf("\n");
    
}