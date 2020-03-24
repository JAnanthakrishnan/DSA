#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct node{
    int data;
    int ht;
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
        return root;
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
    root->ht = 1+maximum(__height(root->left),__height(root->right));
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
struct node * search(struct node * root,int val)
{
    if(root==NULL)
    return NULL;
    if(root->data == val||root == NULL)
        return root;
    else if(root->data<val)
    {
        return search(root->right,val);
    }
    else
    {
        return search(root->left,val);
    }   
}
void printtree(struct node * root)
{
    if(root==NULL)
    {
        printf("( ) ");
    }
    if(root!=NULL){
    printf("( ");
    printf("%d ",root->data);
    printtree(root->left);
    printtree(root->right);
    printf(") ");
    }
}
int is_avl(struct node * root,int minm,int maxm)
{
    if(root == NULL)
    return 1;
    int bf = getbalancef(root);
    if(bf<-1||bf>1)
    return 0;
    else{
        if(root->data<minm||root->data>maxm)
        return 0;
        return is_avl(root->left,minm,root->data-1)&&is_avl(root->right,root->data+1,maxm);
    }
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
    struct node *root = NULL; 
    
    while(1)
    {
        char str[1000];
        scanf("%s",str);
        if(!strcmp(str,"insr"))
        {
            //printf("Test");
            int data;
            scanf("%d",&data);
            root = insert(root,data);
        }
        if(!strcmp(str,"srch"))
        {
            int data;
            scanf("%d",&data);
            struct node * temp = search(root,data);
            if(temp==NULL)
            {
                printf("FALSE\n");
            }
            else
            {
                printf("TRUE\n");
            }
            
        }
        if(!strcmp(str,"pbal"))
        {
            int data;
            scanf("%d",&data);
            struct node * temp = search(root,data);
            printf("%d\n",getbalancef(temp));
        }
        if(!strcmp(str,"delt"))
        {
            int data;
            scanf("%d",&data);
            struct node * temp = search(root,data);
            if(temp==NULL)
            {
                printf("FALSE\n");
            }
            else
            {
                root = delete(root,data);
            }
        }
        if(!strcmp(str,"disp"))
        {
            printtree(root);
            printf("\n");
        }
        if(!strcmp(str,"avlc"))
        {
            if(is_avl(root,INT_MIN,INT_MAX))
            printf("AVL\n");
            else
            {
                printf("NOT_AVL\n");
            }
        }
        if(!strcmp(str,"exit"))
        {
            return 0;
        }

    }
}
