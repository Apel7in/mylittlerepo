#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 typedef struct Book{
 char name[30];
 char author[30];
 unsigned int pages;
 char isbn[20];
 }Book;

 int comp(const void* a, const void* b){

    Book* c = (Book*)a;
    Book* d = (Book*)b;
    if(strcmp(c->name, d->name))
        return strcmp(d->name, c->name);
    else if(strcmp(c->author,d->author))
        return strcmp(d->author,c->author);
    else return c->pages - d->pages;
}

int main()
{
    int j;
    int i;
    scanf("%d",&i);
    Book bk[i];
    for(j=0;j<i;j++){
    scanf("%s %s %d %s",&bk[j].name,&bk[j].author,&bk[j].pages,&bk[j].isbn);
    }
    qsort(bk,i,sizeof(Book),comp);
    int k;
    for(k=0;k<i;k++){
        printf("%s %s %d %s\n", bk[k].name, bk[k].author, bk[k].pages, bk[k].isbn);
    }
    return 0;
}
