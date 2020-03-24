#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char *word;
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
void insert(struct node ** root,char * word,int cap)
{
    int n = strlen(word);
    int index = n%cap;
    struct node * temp = newnode(word);
    if(root[index]==NULL)
    {
     root[index] = temp;
    // printf("%d %s",index,root[index]->word);
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
void  extract_str(struct node ** root,char * str,int cap)
{
    int i =0;
    char *substr = (char *)malloc(100*sizeof(char));
    int j = 0;
    for(int i=0;;i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            
            substr[j] = '\0';
            j = 0;
           // printf("%s\n",substr);
            insert(root,substr,cap);
           // printf("%s",root[0]->word);
            if(str[i]=='\0')
            return;
        }
        else if((65<=str[i]&&90>=str[i])||(97<=str[i]&&122>=str[i]))
        {
            //printf("%c",str[i]);
            substr[j] = str[i];
            j++;
        }
    }
    substr[j]='\0';
    return;
}
void print_h(struct node ** root,int cap)
{
    for(int i=0;i<cap;i++)
    {
        if(root[i]==NULL)
        root[i] = newnode("NULL");
        struct node * temp = root[i];
        while(temp!=NULL)
        {
            printf("%s ",temp->word);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int cap;
    scanf("%d\n",&cap);
    struct node * root[cap];
    for(int i=0;i<cap;i++)
    {
        root[i]=NULL;  
    }
    char * str = (char *)malloc(1000*sizeof(char));
    scanf("%[^\n]s",str);
    extract_str(root,str,cap);
   // printf("%s",root[0]->word);
    print_h(root,cap);

}
