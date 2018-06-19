#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct res{
char ress[50];
int cnt;
}res;


int comp(const void* a, const void* b){

    res* c = (res*)a;
    res* d = (res*)b;
    return strcmp(c->ress, d->ress);
}

int main()
{
    res rez[50];
    int i;
    for(i=0;i<50;i++){
    scanf("%s",&rez[i].ress);
    if(!strcmp(rez[i].ress,"Total")){
        break;
    }
    scanf("%d",&rez[i].cnt);
    }
    qsort(rez,i,sizeof(res),comp);
    int j;
    for(j=0;j<i;j++)
        printf("%s %d\n",rez[j].ress,rez[j].cnt);
    return 0;
}
