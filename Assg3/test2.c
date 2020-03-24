#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void jmp(char * prefix)
{
    printf("%s",prefix);
    return;
}
int print_sub(char set[],char prefix[],int n,int k)
{
    printf("%d",k);
    if(k==0)
    {
        char ch = '\0';
        strncat(prefix,&ch,1);
        //printf("%s\n",prefix);
        jmp(prefix);
        return 0;
    }
    int i=0;
        char temp[] = "";
        strcpy(temp,prefix);
        strncat(temp,&set[i],1);
        char ch = '\0';
        strncat(temp,&ch,1);
        print_sub(set,temp,n,k-1);
}

int main()
{
    char set1[] = {'p','o'};
    int k = 3;
    char prefix[]="";
    print_sub(set1,prefix,5,k);
    printf("RRREEWWDENJENJRNJNT");
}