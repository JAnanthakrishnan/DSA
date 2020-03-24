#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    struct node* arr1[10000]={NULL};
    struct node* arr2[10000]={NULL};
    struct node* arr3[10000]={NULL};
    struct node* arr4[10000]={NULL};
    for(int k=0;k<100;k++)
    {
            arr3[k]=makeset(INT_MIN);
            arr1[k]=makeset(INT_MIN);
            arr2[k]=makeset(INT_MIN);
            arr4[k]=makeset(INT_MIN);
    }

    //struct node* root1[100];
    //struct node* root2[100];
    //struct node* root3[100];
    //struct node* root4[100];

    int i = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    while(1)
    {
        int val;
        char ch;
          int x,y;
          int j;
        scanf("%c",&ch);
        if(ch=='m')
        {
            scanf("%d",&val);
            int j;
            for(j=0;j<=i;j++)
            {
                if(arr1[j]->data==val)
                break;
            }
            if(j!=i+1)
            {
                printf("PRESENT\n");
                continue;
            }
            arr3[i]=makeset(val);
            arr1[i]=makeset(val);
            arr2[i]=makeset(val);
            arr4[i]=makeset(val);
            printf("%d\n",val);
            i++;

        }
        if(ch == 'u')
        {
            scanf("%d",&x);
            scanf("%d",&y);
            int j;
            for(j=0;j<=i;j++)
            {
                if(arr1[j]->data==x)
                break;
            }
            if(j==i+1)
            {
                printf("ERROR\n");
                continue;
            }
            struct node * x1 = find(arr1[j],&count1);
            for(j=0;j<=i;j++)
            {
                if(arr1[j]->data==y)
                break;
            }
            if(j==i+1)
            {
                printf("ERROR\n");
                continue;
            }
            struct node * y1 = find(arr1[j],&count1);
            if(x1!=y1)
            x1 = link(x1,y1);
            //printf("%d",y1->rep->data);

            for(j=0;j<=i;j++)
            {
                if(arr2[j]->data==x)
                break;
            }
            struct node * x2 = find(arr2[j],&count2);
            for(j=0;j<=i;j++)
            {
                if(arr2[j]->data==y)
                break;
            }
            struct node * y2 = find(arr2[j],&count2);
            if(x2!=y2)
            x2 = link_rank(x2,y2);
            //printf("%d",y2->rep->data);

            for(j=0;j<=i;j++)
            {
                if(arr3[j]->data==x)
                break;
            }
            struct node * x3 = find_path(arr3[j],&count3);
            for(j=0;j<=i;j++)
            {
                if(arr3[j]->data==y)
                break;
            }
            struct node * y3 = find_path(arr3[j],&count3);
            if(x3!=y3)
            x3 = link(x3,y3);
            //printf("%d",y3->rep->data);

            for(j=0;j<=i;j++)
            {
                if(arr4[j]->data==x)
                break;
            }
            struct node * x4 = find_path(arr4[j],&count4);
            for(j=0;j<=i;j++)
            {
                if(arr4[j]->data==y)
                break;
            }
            struct node * y4 = find_path(arr4[j],&count4);
            if(x4!=y4)
            x4 = link_rank(x4,y4);
            //printf("%d",y4->rep->data);

            printf("%d %d %d %d\n",y1->rep->data,y2->rep->data,y3->rep->data,y4->rep->data);

        }
        if(ch=='f')
        {
            int x;
            scanf("%d",&x);
            int j;
            for(j=0;j<=i;j++)
            {
                if(arr1[j]->data==x)
                break;
            }
            if(j==i+1)
            {
                printf("NOT FOUND\n");
                continue;
            }
            struct node * x1 = find(arr1[j],&count1);
            //printf("%d",x1->rep->data);


            for(j=0;j<=i;j++)
            {
                if(arr2[j]->data==x)
                break;
            }
            struct node * x2 = find(arr2[j],&count2);
            //printf("%d",x2->rep->data); 

            for(j=0;j<=i;j++)
            {
                if(arr3[j]->data==x)
                break;
            }
            struct node * x3 = find_path(arr3[j],&count3);
            //printf("%d",x3->rep->data); 

            for(j=0;j<=i;j++)
            {
                if(arr4[j]->data==x)
                break;
            }
            struct node * x4 = find_path(arr4[j],&count4);
            //printf("%d",x4->rep->data);    
            printf("%d %d %d %d\n",x1->rep->data,x2->rep->data,x3->rep->data,x4->rep->data);
      
        }
        if(ch=='s')
        {
            printf("%d %d %d %d\n",count1,count2,count3,count4);
        }
        if(ch=='e')
        {
            return 0;
        }
    }
}