#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char * word;
    struct node * next;
};
struct node * newnode(char *word)
{
    int n = strlen(word);
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->word = (char *)malloc(n*sizeof(char));
    strcpy(temp->word,word);
    temp->next = NULL;
}
int ascii(char * word)
{
    int asc=0;
    int n = strlen(word);
    for(int i=0;i<n;i++)
    {
        asc+=word[i];
    }
    return asc;
}
int arePermutation(char* str1, char* str2) 
{ 
    int count[256] = {0}; 
    int i; 
    for (i = 0; str1[i] && str2[i];  i++) 
    { 
        count[str1[i]]++; 
        count[str2[i]]--; 
    } 
    for (i = 0; i < 256; i++) 
        if (count[i]) 
            return 0; 
     return 1; 
} 
void insert(struct node ** root,char * word,int index)
{
    struct node * temp = newnode(word);
    if(root[index]==NULL)
    {
     root[index] = temp;
     return;
    }
    else{
        struct node * ptr = root[index];
        while(ptr->next!=NULL)
        {
            if(!strcmp(ptr->word,word))
            return;
            ptr = ptr->next;
        }
        if(!strcmp(ptr->word,word))
            return;
        ptr->next = temp;
        return;
    }
}
int main()
{
    char name1[]="mani";
    char name2[]="nami";    
    struct node * hash[120000];
    for(int i=0;i<120000;i++)
    {
        hash[i]=NULL;  
    }
    char needle[1000];
    char haystack[100000];
    int test;
    scanf("%d\n",&test);
    while(test!=0)
    {
        fgets(needle,1000,stdin);
        fgets(haystack,100000,stdin);
        int len = strlen(needle);
        //printf("!!%d!!",len);
        int len2 = strlen(haystack); 
        for(int i=0;i<len2-len+1;i++)
        {
            int j=0;
            char word[1000]={0};
            for(int j=0;j<len-1;j++)
            {
                word[j]=haystack[i+j];
            }
            word[strlen(word)+1]='\0';
            //printf("%s %d ",word,j);
            int asc = ascii(word);
            //printf("%d\n",asc);
            insert(hash,word,asc);
        }
        int mainasc = ascii(needle)-10;
        //printf("%d\n",mainasc);
        int flag = 0;
            if(hash[mainasc]!=NULL)
            {
                struct node * temp = hash[mainasc];
                while(temp!=NULL)
                {
                    //printf("%d %d",strlen(temp->word),strlen(needle));
                    char ch = '\0';
                    strncat(temp->word,&ch,1);
                    if(arePermutation(temp->word,needle))
                    {
                        printf("YES\n");
                        flag = 1;
                    }
                    break;
                    temp = temp->next;
                }
                if(flag==0)
                printf("NO\n");                
            }
            else
            {
                printf("NO\n");
            }
        test--;
        for(int i=0;i<120000;i++)
        {
            hash[i]=NULL;  
        }
    }
}