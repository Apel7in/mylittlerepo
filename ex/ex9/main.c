#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[85];
    fgets(s,85,stdin);
    int g=strlen(s)/2;
    int k;
    if((strlen(s)%2)==0) k=g-1;
    else k=g;

    char s1[g], s2[g];
    int i;
    for(i=0;i<g;i++)
    {
        s1[i]=s[i];
    }
    int j=0;
    for(i=g;i<strlen(s);i++)
    {
        s2[j]=s[i];
        j++;
    }
    for(i=0;i<k;i++)
    {
        printf("[%c]",s1[i]);
        printf("[%c]",s2[i]);
    }
    return 0;
}
