#include <stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *prev;
        struct node *next;
};
int main()
{
        struct node *head = NULL;
        int arr[1000];
        int num;
        char ch;
        int pos = 0;
        int size;
        for(size=0;;size++)
        {
                if(fscanf(stdin,"%d",&num)==1)
                {
                        arr[size]=num;
                }
                else if(fscanf(stdin,"%c",&ch)==1)
                {
                        if(ch=='x')
                                break;
                        else
                        {
                                printf("invalid character");
                                break;
                        }
                }
        }
        for(int i=0;i<size;i++)
        {
            
            if(i%2==0)
                pos = i/2;
            else
            {
                pos = (i+1)/2;
            }
            
            struct node * newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data=arr[i];
            newnode->prev=NULL;
            newnode->next=NULL;
            if(head==NULL)
            {

                head = newnode;
            }
            else
            {
                struct node * before = head;
                struct node * after = NULL;
                for(int j=1;j<pos;j++)
                {
                    before = before->next;
                }
                after = before->next;
                if(after!=NULL) after->prev = before;
                before->next=newnode;
                newnode->prev = before;
                newnode->next = after;	
                if(after!=NULL) after->prev = newnode;
            }

        }
        struct node * ptr = head;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
}