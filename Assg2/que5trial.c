#include <stdio.h>
int main()
{
    char str[1000];
    
    scanf("(");
    scanf("%[^\n]s",str);
    printf("%s",str);
}