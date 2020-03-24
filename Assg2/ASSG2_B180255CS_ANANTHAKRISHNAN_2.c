#include <stdio.h>
#include <string.h>
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


struct node * insert(struct node * root , int data)
{
    if(root==NULL)
    {
       // printf("T1");
        return _newnode(data);
    }
    else if(root->data<data)
    {
       // printf("T2");
        root->right = insert(root->right,data);
    }
    else
    {
      //  printf("T3");
        root->left = insert(root->left,data);
    }   
    return root; 
}





void print_string(struct node * root)
{
    if(root==NULL)
    {
        printf("( ) ");
    }
    if(root!=NULL){
    printf("( ");
    printf("%d ",root->data);
    print_string(root->left);
    print_string(root->right);
    printf(") ");
    }
}

int main()
{
    struct node * root = NULL;
    while(1)
    {
        char str[10];
        scanf("%s",str);
        if(!strcmp(str,"insr"))
        {
            int val;
            scanf("%d",&val);
            root = insert(root,val);
        } 
        else if(!strcmp(str,"prep"))
        {
            print_string(root);
            printf("\n");
        }
        else if (!strcmp(str,"stop"))
        {
            return 0;
        }
        else 
            continue;
        
    }
}