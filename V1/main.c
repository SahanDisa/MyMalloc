//Main.c

#include "mymalloc.h"

int main(){
 
 int *p=(int *)MyMalloc(100*sizeof(int));
 char *q=(char *)MyMalloc(250*sizeof(char));
 double *r=(double *)MyMalloc(1000*sizeof(int));
 
 MyFree(p);
 
 char *w=(char *)MyMalloc(700);
 
 MyFree(r);
 
 float *k=(int *)MyMalloc(500*sizeof(float));
 
 return 0;
}
