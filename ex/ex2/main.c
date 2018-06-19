#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct alpf{
int number;
char word;
}alpf;

int main()
{
    int s=2;  int secword[100];
   alpf al[s];
   int i;
   for(i=0;i<s;i++){
    printf("%d:",i);
    scanf("%d %c",&al[i].number,&al[i].word);
   }

for(i=0;i<3;i++){
   if(i!=2)
   scanf("%d ",&secword[i]);
    else scanf("%d",&secword[i]);
}
int j;
for(i=0;i<3;i++)
{
    for(j=0;j<s;j++)
    {
        if(secword[i]==al[j].number)
            printf("%c",al[j].word);
    }
}
    return 0;
}
