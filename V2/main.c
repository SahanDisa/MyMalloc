//Main.c

#include "mymalloc.h"
#include<stdio.h>

int main(){
 
 int *p=(int *)MyMalloc(100*sizeof(int));
 int a = 10;
 //*p = &a;
 printf("%d %d\n",*p,*p+1);
 char *q=(char *)MyMalloc(250*sizeof(char));
 int *r=(int *)MyMalloc(1000*sizeof(int));
 MyFree(p);
 char *w=(char *)MyMalloc(700);
 MyFree(r);
 int *k=(int *)MyMalloc(500*sizeof(int));
 printf("Allocation and deallocation is done successfully!");
 
}
