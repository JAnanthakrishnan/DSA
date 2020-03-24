#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* insert(struct node* head,int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head==NULL)
    {
        printf("\nT1\n");
        head = newnode;
    }
    else
    {
        struct node* ptr = head;
        if(ptr->next==NULL)
        {
            if(val<ptr->data)
            {
                printf("\nT2\n");
                newnode->next=ptr;
                ptr->prev = newnode;
                newnode->prev = NULL;
                head = newnode;
            }
            else
            {
                printf("\nT3\n");
                ptr->next = newnode;
                newnode->prev = ptr;
                newnode->next = NULL;
            }
        }
        else
        {
            struct node * ptr = head;
            while(val>ptr->data && ptr->next!=NULL)
            {
                ptr = ptr->next;   
            }
            if(ptr->next==NULL&&ptr->data<val)
            {
                printf("\nT4\n");
                ptr->next = newnode;
                newnode->prev = ptr;
                newnode->next = NULL; 
            }
            else
            {
                struct node* bef = ptr->prev;
                if(bef==NULL)
                {
                    printf("\nT5\n");
                    newnode->next=ptr;
                    ptr->prev = newnode;
                    newnode->prev = NULL;
                    head = newnode; 
                }
                else
                {
                    printf("\nT6\n");
                    bef->next = newnode;
                    ptr->prev = newnode;
                    newnode->next = ptr;
                    newnode->prev = bef;
                }
            }
        }
    }
    return head;
}
int main()
{
    printf("Enter the size of the array :");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array :");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    struct node * head = NULL;
    for(int i=0;i<n;i++)
    {
        head = insert(head,arr[i]);
    }
    struct node * ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}