#include<stdio.h>
#include "mymalloc.h"

int main(){
	//Allocation
	int *allocation_1 = (int *)MyMalloc(sizeof(int)*9);
	printer();
	float *allocation_2 = (float *)MyMalloc(sizeof(float)*8);
	printer();
	
	MyFree((void *)allocation_2); 
	printer();
	MyFree((void *)allocation_1);
	printer();
	char *allo_3 = (char *)MyMalloc(sizeof(char)*12);
	printer();
	double *allo_4 = (double *)MyMalloc(sizeof(double)*5);
	printer();
	double *allo_5 = (double *)MyMalloc(sizeof(double)*10);
	return 0;
}
