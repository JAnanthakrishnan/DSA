#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int flag;
};
int linearprobe_insert(struct node hash[],int data,int m)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {
        
        index = (hf + i)%m;
        if(hash[index].flag==0||hash[index].flag==2)
        break;
        else
        {
            i = i+1;
            if(i==m)
            return 0;
        }      
    } 
    //printf("The index is : %d\n",index);
    hash[index].data = data;
    hash[index].flag = 1;
    return 1;
}
int linearprobe_delete(struct node hash[],int data,int m)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {        
        index = (hf + i)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }
        
    } 
    hash[index].data = 0;
    hash[index].flag = 2;
    return 1;
}
int linearprobe_search(struct node hash[],int data,int m)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {        
        index = (hf + i)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }
        
    } 
    return 1;
}
int quadraticprobe_insert(struct node hash[],int data,int m,int c1,int c2)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {
        
        index = (hf + c1*i + c2*i*i)%m;
        if(hash[index].flag==0||hash[index].flag==2)
        break;
        else
        {
            i = i+1;
            if(i==m)
            return 0;
        }   
    }
    hash[index].data = data;
    hash[index].flag = 1;
    return 1;
}
int quadraticprobe_delete(struct node hash[],int data,int m,int c1,int c2)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {
        
        index = (hf + c1*i + c2*i*i)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }

    }
    hash[index].data = 0;
    hash[index].flag = 2;
    return 1;
}
int quadraticprobe_search(struct node hash[],int data,int m,int c1,int c2)
{
    int i=0;
    int hf = data%m;
    int index;
    while(1)
    {
        
        index = (hf + c1*i + c2*i*i)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }

    }
    return 1;
}
int is_prime(int n)
{
    if(n<=1)
    return 1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
int large_prime(int m)
{
    int R=0;
    for(int j=m-1;j>=1;j--)
    {
        if(is_prime(j)==1)
        {
            R = j;
            break;
        }
    } 
    return R;
}
int double_hash_insert(struct node hash[],int data,int m,int R)
{
    int i=0;
    int hf = data%m;   
    int hf2 = R - data%R;
    int index;
    while(1)
    {
        index = (hf + i*hf2)%m;
        if(hash[index].flag==0||hash[index].flag==2)
        break;
        else
        {
            i = i+1;
            if(i==m)
            return 0;
        }  
    }
    hash[index].data = data;
    hash[index].flag = 1;
    return 1;
}
int double_hash_delete(struct node hash[],int data,int m,int R)
{
    int i=0;
    int hf = data%m;    
    int hf2 = R - data%R;
    int index;
    while(1)
    {
        index = (hf + i*hf2)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }
    }
    hash[index].data = 0;
    hash[index].flag = 2;
    return 1;
}
int double_hash_search(struct node hash[],int data,int m,int R)
{
    int i=0;
    int hf = data%m;  
    int hf2 = R - data%R;
    int index;
    while(1)
    {
        index = (hf + i*hf2)%m;
        if(hash[index].flag==0)
        return 0;
        if(hash[index].data==data)
        break;
        else
        {
            i=i+1;
            if(i==m)
            return 0;
        }
    }
    return 1;
}
void print_hash(struct node hash[],int m)
{
    for(int i=0;i<m;i++)
    {
        printf("%d ",i);
        if(hash[i].flag==0||hash[i].flag==2)
        printf("( )\n");
        else
        printf("( %d )\n",hash[i].data);
    }
    return;
}
void linearprobe()
{
    int m;
     scanf("%d",&m);
    struct node hash[m];
    for(int i=0;i<m;i++)
    {
        hash[i].data = 0;
        hash[i].flag = 0;
    }
   
    char ch;
    int data;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&data);
            int x = linearprobe_insert(hash,data,m);
            if(x==0)
            printf("Hash table is full\n");
        }
        else if(ch == 's')
        {
            scanf("%d",&data);
            int x = linearprobe_search(hash,data,m);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'd')
        {
            scanf("%d",&data);
            int x = linearprobe_delete(hash,data,m);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'p')
        {
            print_hash(hash,m);
        }
        else if(ch == 't')
        {
            return;
        }

    } 
    
}
void quadraticprobe()
{
    int m;
    scanf("%d",&m);
    struct node hash[m];
    for(int i=0;i<m;i++)
    {
        hash[i].data = 0;
        hash[i].flag = 0;
    }
    
    int c1;
    int c2;
    scanf("%d",&c1);
    scanf("%d",&c2);
    char ch;
    int data;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&data);
            int x = quadraticprobe_insert(hash,data,m,c1,c2);
            if(x==0)
            printf("Hash table is full\n");
        }
        else if(ch == 's')
        {
            scanf("%d",&data);
            int x = quadraticprobe_search(hash,data,m,c1,c2);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'd')
        {
            scanf("%d",&data);
            int x = quadraticprobe_delete(hash,data,m,c1,c2);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'p')
        {
            print_hash(hash,m);
        }
        else if(ch == 't')
        {
            return;
        }

    } 
    
}
void double_hash()
{
    int m;
    scanf("%d",&m);
    struct node hash[m];
    for(int i=0;i<m;i++)
    {
        hash[i].data = 0;
        hash[i].flag = 0;
    }
    int R;
    R = large_prime(m);
    char ch;
    int data;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&data);
            int x = double_hash_insert(hash,data,m,R);
            if(x==0)
            printf("Hash table is full\n");
        }
        else if(ch == 's')
        {
            scanf("%d",&data);
            int x = double_hash_search(hash,data,m,R);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'd')
        {
            scanf("%d",&data);
            int x = double_hash_delete(hash,data,m,R);
            if(x==0)
            printf("%d\n",-1);
            else
            printf("%d\n",1);
        }
        else if(ch == 'p')
        {
            print_hash(hash,m);
        }
        else if(ch == 't')
        {
            return;
        }

    } 
    
}
int main()
{
    char ch;
    scanf("%c",&ch);
    if(ch=='a')
    linearprobe();
    if(ch=='b')
    quadraticprobe();
    if(ch=='c')
    double_hash();
    return 0;
}

