#include<stdlib.h>
#include<stdio.h>

int main(){
	int a = 10;
	int *ptr;
	ptr = &a;
	
	printf("%d %d\n",ptr,*ptr);
	
	
	return 0;
}
