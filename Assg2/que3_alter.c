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

void print_mirror(struct node * root)
{
    if(root==NULL)
    {
        printf("()");
    }
    if(root!=NULL){
    printf("(");
    printf("%d",root->data);
    print_mirror(root->right);
    print_mirror(root->left);
    printf(")");
    }
}
int main()
{
    struct node * root = NULL;
    char str[1000];
   //  printf("%d",powe(10,2));
    scanf("%[^\n]s",str);
    int i=0;
   // printf("%d",powe(10,2));
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]==')'||str[i]==' ')
        {
            i++;
            continue;
        }
        int j=0;
        int num = 0;
        char substr[1000]={'0'};
        while(48<=str[i]&&str[i]<=57)
        {
           // printf("%c",str[i]);
            //num+=(str[i++]-'0')*powe(10,j++);
            substr[j++]=str[i++];
        }
        substr[j]='\0';
        //printf("%s",substr);
        num = atoi(substr);
        root = insert(root,num);
    }
    print_mirror(root);
}