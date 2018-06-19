#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int c=0; int w=0;
int rec(int b){

    if(!(b=b/10)) return c;
    else {
        c++;
        rec(b);
    }

}

int recPow(int a, int b)
{
    int res;
    if(b==0)return 1;
    if(b==1)return 10;
    res=recPow(10,b-1)*10;
    return res;
}

int rec2(int g)
{

       if(c!=-1){
        w=w+(g%10)*recPow(10,c);
        c--;
        g=g/10;
        rec2(g);
       }
       else return w;
}


int main()
{
   int a;
   scanf("%d",&a);
   rec(a);
   printf("%d",rec2(a));
    return 0;
}
