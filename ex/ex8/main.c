#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Figure {
char name[30];
int x;
int y;
}Figure;

int comp(const void* a, const void* b){

    Figure* c = (Figure*)a;
    Figure* d = (Figure*)b;
    if((abs(c->x) - abs(d->x))>0)
        return 1;
       else return -1;
}

int comp2(const void* a, const void* b){

    Figure* c = (Figure*)a;
    Figure* d = (Figure*)b;
    if((abs(c->y) - abs(d->y))>0)
        return 1;
       else return -1;
}

int main()
{
    int sz;
    scanf("%d",&sz);
    Figure fig[sz];
    int i;
    for(i=0;i<sz;i++)
    {
        scanf("%s %d %d",&fig[i].name,&fig[i].x,&fig[i].y);
    }
    qsort(fig,sz,sizeof(Figure),comp);
    qsort(fig,sz,sizeof(Figure),comp2);
    for(i=0;i<sz;i++){
    printf("%s %d %d ",fig[i].name,fig[i].x,fig[i].y);
    }
    return 0;
}
