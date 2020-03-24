#include <stdio.h> 
#include <stdlib.h> 



typedef struct node { 
    char data; 
  
    int priority; 
  
    struct node* next; 

    struct node* left;
    struct node* right;
  
}Node; 
  

Node* newNode(char d, int p, Node* left, Node* right) 
{ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
    temp->left = left;
    temp->right = right;
  
    return temp; 
} 
  


int peek(Node** head) 
{ 
    return (*head)->priority; 
} 
  
Node* pop(Node** head) 
{ 
    if(*head==NULL)
    return NULL;
    Node* temp = *head; 
    int val = temp->priority;
    (*head) = (*head)->next; 
    return temp;
} 
 
void push(Node** head, char d, int p, Node* left, Node* right) 
{ 
    if(*head==NULL){
        *head = newNode(d,p,left,right);
        return;
    }
    Node* start = (*head); 
    
  
    Node* temp = newNode(d, p , left,right); 
  
    if ((*head)->priority > p) { 
  
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        while (start->next != NULL && 
               start->next->priority < p) { 
            start = start->next; 
        } 

        temp->next = start->next; 
        start->next = temp; 
    } 
} 
int isEmpty(Node** head) 
{ 
    return (*head) == NULL; 
} 

Node* buildhuff(Node* pq,int count)
{
    Node *left, *right, * top;
    int lp,rp;
    //printf("%d\n",count);
    for(int i=0;i<count-1;i++)
    {
        left = pop(&pq);
        right = pop(&pq);
        if(left==NULL)
        lp = 0;
        else
        {
            lp = left->priority;
        }       
        if(right==NULL)
        rp = 0;
        else
        {
            rp = right->priority;
        } 
        //printf("%d",lp+rp);
        push(&pq,'$',lp+rp,left,right);
        
    }
 
    return pq;
}

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
} 

int isLeaf(Node* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
} 

void printCodes(Node* root,int arr[],int top,int len[])
{
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1,len);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1,len);
    }
    if (isLeaf(root)) { 
  
        printf("%c: ", root->data); 
        len[root->data] = top;
        printArr(arr, top); 
    } 
}

int main()
{
    int arr[128]={0};
    char str[100];
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0')
    {
        arr[str[i]]++;
        i++;
    }
   
    Node *pq = NULL;
    int count = 0;
  //  Node* pq = newNode('0',arr['0'],NULL,NULL);
    for(char m = 48;m<=122;m++)
    {
        if(arr[m]!=0){
        push(&pq,m,arr[m],NULL,NULL);
        count++;
        }
    }
/*    push(&pq,'b',arr['b'],NULL,NULL);
    push(&pq,'c',arr['c'],NULL,NULL);
    push(&pq,'d',arr['d'],NULL,NULL);
    push(&pq,'e',arr['e'],NULL,NULL);
    push(&pq,'f',arr['f'],NULL,NULL);
    push(&pq,'g',arr['g'],NULL,NULL);
    push(&pq,'h',arr['h'],NULL,NULL);
    push(&pq,'i',arr['i'],NULL,NULL);
    push(&pq,'j',arr['j'],NULL,NULL);
    push(&pq,'k',arr['k'],NULL,NULL);
    push(&pq,'l',arr['l'],NULL,NULL);
    push(&pq,'m',arr['m'],NULL,NULL);
    push(&pq,'n',arr['n'],NULL,NULL);
    push(&pq,'o',arr['o'],NULL,NULL);
    push(&pq,'p',arr['p'],NULL,NULL);
    push(&pq,'q',arr['q'],NULL,NULL);
    push(&pq,'r',arr['r'],NULL,NULL);
    push(&pq,'s',arr['s'],NULL,NULL);
    push(&pq,'t',arr['t'],NULL,NULL);
    push(&pq,'u',arr['u'],NULL,NULL);
    push(&pq,'v',arr['v'],NULL,NULL);
    push(&pq,'w',arr['w'],NULL,NULL);
    push(&pq,'x',arr['x'],NULL,NULL);
    push(&pq,'y',arr['y'],NULL,NULL);
    push(&pq,'z',arr['z'],NULL,NULL);*/
   // char ch = '0';
   // int count = 0;
   // for(int i=48;i<=122;i++)
   // {
   //     if(arr[ch]==0){
   //     deleteNode(&pq,ch);
   //     count++;
   //     }
   //     ch++;
   // }
    int x =count;
    
    
    Node* root = buildhuff(pq,x);
    
    int ar[100],top=0;
    int len[128] = {0};
    printCodes(root,ar,top,len);   
    int sum = 0;
    char ch = '0';
    for(int i=48;i<=122;i++)
    {
        sum+=(arr[ch]*len[ch]);
        ch++;
    }
    printf("%d\n",sum);
    //char u = getchar();
/////    //char v = getchar();
    //if(u==10)
    //return 0;
    main();
}
