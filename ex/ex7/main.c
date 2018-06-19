#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pol(char strok[50], int a){
    if(a>=(strlen(strok)-a))
        return 1;
    if(strok[a]==strok[strlen(strok)-a-1])
            return pol(strok,a+1);
        else return 0;

}

int main()
{
    char strok[50];
    scanf("%s",strok);
    if(pol(strok,0)==1)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
