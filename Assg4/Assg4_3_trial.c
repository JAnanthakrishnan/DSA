#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int rank;
    int size;
    struct node * parent;
    struct node * rep;
};
struct node * makeset(int x)
{
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->rank = 0;
    root->size = 1;
    root->parent = root;
    root->rep = root;
    return root;
}
struct node * link(struct node *x, struct node *y)
{
    y->parent = x;
    y->rep = x;
    x->size = x->size+1;
    return x;
}
struct node * link_rank(struct node *x,struct node *y)
{
    if(x->rank<y->rank)
    {
        x->parent = y;
        x->rep = y;
        y->size++;
        return y;
    }
    if(x->rank>y->rank)
    {
        y->parent = x;
        y->rep = x;
        x->size++;
        return x;
    }
    if(x->rank==y->rank)
    {
        y->parent = x;
        y->rep = x;
        x->size++;
        x->rank++;
        return x;
    }
}
struct node * find(struct node * x,int *count)
{
    *count = *count + 1;
    if(x->parent==x)
        return x;
    else
        return find(x->parent,count);
    
}
struct node * find_path(struct node * x,int *count)
{
    *count = *count+1;
    if(x->parent==x)
        return x;
    else
    {
        struct node * temp = find_path(x->parent,count);
        x->parent = temp;
        return temp;
    }
}
int main()
{
    struct node* arr[100]={NULL};
    
    struct node* root[100];
    int i = 0;
    int count = 0;
    while(1)
    {
        int val;
        char ch;
          int x,y;
          int j;
        scanf("%c ",&ch);
        if(ch=='m')
        {
            scanf("%d",&val);
            root[i] = makeset(val);
            arr[i]=root[i];
            i++;

        }
        if(ch == 'u')
        {
            scanf("%d",&x);
            scanf("%d",&y);
            int j;
            for(j=0;j<100;j++)
            {
                if(arr[j]->data==x)
                break;
            }
            struct node * x1 = find_path(arr[j],&count);
            for(j=0;j<100;j++)
            {
                if(arr[j]->data==y)
                break;
            }
            struct node * y1 = find_path(arr[j],&count);
            x1 = link_rank(x1,y1);
            printf("%d",y1->rep->data);

        }
        if(ch=='f')
        {
            int x;
            scanf("%d",&x);
            int j;
            for(j=0;j<100;j++)
            {
                if(arr[j]->data==x)
                break;
            }
            struct node * x1 = find_path(arr[j],&count);
            printf("%d",x1->rep->data);           
        }
        if(ch=='s')
        {
            printf("%d\n",count);
        }
    }
}