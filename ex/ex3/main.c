#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int pred1(const void *el){
    int a= *(const int*)el;
    if((a%3)==0 && (a%2)!=0) return 1;
     else return 0;
}
int pred2(const void *el){

    double s= *(const double*)el;
    double a;
    double b;

    b=modf(s,&a);
    if(b==0 && fmod(a,3)==0 && fmod(a,2)!=0) return 1;
     return 0;
}

int count_if(void* arr,int m, int sz, int (*pred)(const void *))
{
    void* array=arr;
    int i; int t=0;
    for(i=0;i<m;i++)
    {
        if(pred(array+i*sz)==1)
            t++;
    }
    return t;
}


int main(){
    int sz; int m=3; int i; int ct=0;
    printf("size:");
    scanf("%d",&sz);

    int(*pred)(const void *);

   if(sz==4){
        int mass[m];
     printf("mass:");
        for(i=0;i<m;i++)
            scanf("%d",&mass[i]);
            pred=pred1;
        ct=count_if(mass,m,sz,pred);
   }

   if(sz==8){
        double dmass[m];
        printf("mass:");
    for(i=0;i<m;i++)
        scanf("%lf",&dmass[i]);
        pred=pred2;
    ct=count_if(dmass,m,sz,pred);
   }

    printf("%d",ct);
   return 0;
}

