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

struct node* findMin(struct node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if(root->left != NULL)
    {
      // printf("T2");
        return findMin(root->left);
    }
    else
    {
      //  printf("T3");
        return root;
    }    
}
struct node* findMax(struct node* root)
{
    if (root == NULL)
    {
       // printf("T1");
        return NULL;
    }
    
    if(root->right != NULL)
    {
       // printf("T2");
        return findMax(root->right);
    }
    else
    {
       // printf("T3");
        return root;
    }    
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
struct node * level(struct node * root,int val,int *lev)
{
    if(root==NULL)
    return NULL;
    if(root->data == val||root == NULL)
        return root;
    else if(root->data<val)
    {
        *lev+=1;
        return level(root->right,val,lev);
    }
    else
    {
        *lev+=1;
        return level(root->left,val,lev);
    }   
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

struct node * delete(struct node * root,int val)
{
    if(root == NULL)
        return NULL;
    if (root->data<val)
    {
        root->right = delete(root->right,val);
    }
    else if (root->data>val)
    {
        root->left = delete(root->left,val);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            struct node * temp;
            if(root->left==NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;           
        }
        else
        {
            struct node * temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
   
}

void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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
void postorder(struct node * root)
{
    if(root!=NULL)
    {
        postorder(root->left);  
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node * predecessor(struct node * root,struct node * ptr)
{
    if(ptr==NULL)
        return NULL;
    if(ptr->left!=NULL)
        return findMax(ptr->left);
    struct node * pred = NULL;
    while(root!=NULL)
    {
        if(ptr->data>root->data)
        {
            pred = root;
            root = root->right;
        }
        else if(ptr->data<root->data)
        {
            root = root->left;
        }
        else
        {
            break;
        }
        
        
    }
   return pred; 

}
struct node * sucessor(struct node * root,struct node * ptr)
{
    if(ptr==NULL)
    return NULL;
    if(ptr->right!=NULL)
        return findMin(ptr->right);
    struct node * succ = NULL;
    while(root!=NULL)
    {
        if(ptr->data<root->data)
        {
            succ = root;
            root = root->left;
        }
        else if(ptr->data>root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
        
        
    }
    
return succ;
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
        else if(!strcmp(str,"delt"))
        {
            int val;
            scanf("%d",&val);
            struct node * ptr = search(root,val);
            if(ptr!=NULL)
            root = delete(root,val);
            else
            {
                printf("NOT FOUND\n");
            }
            
        }
        else if(!strcmp(str,"srch"))
        {
            int val;
            scanf("%d",&val);
            struct node * ptr = search(root,val);
            if(ptr!=NULL)
            {
                printf("FOUND\n");
            }
            else
            {
                printf("NOT FOUND\n");
            }
            
        }
        else if(!strcmp(str,"levl"))
        {
            int val;
            scanf("%d",&val);
            int lev = 0;
            struct node * ptr = level(root,val,&lev);
            if(ptr!=NULL)
            {
                printf("%d\n",lev);
            }
            else
            {
                printf("NOT FOUND\n");
            }
            
        }
        else if(!strcmp(str,"minm"))
        {
           struct node * ptr = findMin(root);
           if(ptr==NULL)
           printf("NIL\n");
           else
           {
               printf("%d\n",ptr->data);
           }
           

        }
        else if(!strcmp(str,"maxm"))
        {
            struct node * ptr = findMax(root);
            if(ptr==NULL)
            printf("NIL\n");
            else
            {
                printf("%d\n",ptr->data);
            }
        }
        else if(!strcmp(str,"pred"))
        {
            int val;
            scanf("%d",&val);
            struct node * ptr = search(root,val);
            if(ptr==NULL)
            printf("NULL\n");
            else{
            struct node * pred = predecessor(root,ptr);
            if(pred==NULL)
            printf("-1\n");
            else    
            printf("%d",pred->data);}
        }
        else if(!strcmp(str,"succ"))
        {
            int val;
            scanf("%d",&val);
            struct node * ptr = search(root,val);
            if(ptr==NULL)
            printf("NULL\n");
            else{
            struct node * succ = sucessor(root,ptr);
            if(succ==NULL)
            printf("-1\n");
            else
            printf("%d",succ->data);}
        }
        else if(!strcmp(str,"inor"))
        {
            inorder(root);
            printf("\n");
        }
        else if(!strcmp(str,"prer"))
        {
            preorder(root);
            printf("\n");
        }
        else if(!strcmp(str,"post"))
        {
            postorder(root);
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