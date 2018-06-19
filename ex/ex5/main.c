#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct slow{
    char fword[50];
    char sword[50];
}slow;

int main()
{

    slow sl[50];
    int i; int j;
   for(i=0;i<50;i++){
    printf("1. ");
    scanf("%s",&sl[i].fword);
    if(!strcmp(sl[i].fword,"ugabuga")){
     printf("!\n");
       break;
    }
    scanf("%s",&sl[i].sword);
    }

    int c;
    do{
    c = getchar();
    }
    while(c != EOF && c != '\n');
    char strok[50];
    fgets(strok,50,stdin);

    int k;
    for(k=0;k<strlen(strok);k++)
    {
            strok[k]=tolower(strok[k]);
    }


    char * istr; int u;
    istr=strtok(strok," \n");
    while(istr!=NULL)
    {
        for(u=0;u<i;u++){
        if(strcmp(istr,sl[u].fword)==0){
        printf("%s ",sl[u].sword);
        break;
            }
            if(u==(i-1))
             printf("<unknown> ");

        }

        istr=strtok(NULL," \n");
    }
    return 0;
}
