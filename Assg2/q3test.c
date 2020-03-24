#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long int powe(int i,int j)
{
    long int product = 1;
    while(j!=0)
    {
        product*=i;
        j--;
    }
    return product;
}
int main()
{
    struct node * root = NULL;
    char str[1000];
   //  printf("%d",powe(10,2));
    scanf("%[^\n]s",str);
    int i=0;
   // printf("%d",powe(10,2));
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]==')'||str[i]==' ')
        {
            i++;
            continue;
        }
        int j=0;
        int num = 0;
        char substr[1000]={'0'};
        while(48<=str[i]&&str[i]<=57)
        {
           // printf("%c",str[i]);
            //num+=(str[i++]-'0')*powe(10,j++);
            substr[j++]=str[i++];
        }
        substr[j]='\0';
        //printf("%s",substr);
        num = atoi(substr);
        printf("%d\n",num);
    }
}