#include<stdio.h>
#define n 112
#define start 0

char memory[n];	//size of a char is 1 byte, so size of a char array of 25000 elements is 25000 bytes
void *ptr;
static int a = 0;//work as a position var through the main memory	
//OS variables
int sp_os_mem;//allocate memory for this variable for last 8 bytes in the memory for simplicity
int sp_os_mem1;
int i = start;//allocate memory for this variable in the last 4 bytes in the memory for simplicity

//------------------actual memory allocation avaliable size-------------------------------//
// 0----------------------------24987 from index vice
//So initially 12 bytes are vacant in the memory
 

void *MyMalloc(size_t size){
	//initial state of the allocate the contiguous block of memory 
	if(size == 0){
		return NULL;//memory waste 16 bytes if the size is 0 also, This condition avoid sunk allocations 
	}
	if(a==0 && a+size < n-12){
		printf("initial allocation a is : %d\n",a);
		memory[a] = size;
		memory[a+1] = 1;//flag to allocate
		
		//e.g :-4*2 + 8 for the allocation_1
		a+=16;//a = sizeof(int)*2 + sizeof(*ptr);
		
		ptr = (void *)&memory[a];
		//printf("%d %d\n",&memory[16],a);
		//printf("%d %d %d\n",a,(int *)ptr,a+1);
		a += size;
		printf("%d\n",a);
		//address_of_pointer(ptr);
		return ptr;
	}
	//Normal state of allocating memory
	else if(a>0 && a+size < n-12){
		printf("normal state\n");
		memory[a++] = size;//size
		memory[a++] = 1;//flag
		
		a += 14;
		
		ptr = (void *)&memory[a];
		printf("%d %d %d \n",a,(int *)ptr,a+1);
		
		//address_of_pointer(ptr);
		
		a+=size;
		
		return ptr;
	}else if(a>0 && a+size > n-12){
		//status of searching the first fit for allocation
		i=start;
		//search the place for first fit
		for(i=0; i<n-8; i++){
			if(memory[i]>=4 && memory[i+1]==0){
				//free block
				if(memory[i]==size){
					//nothing to split
					printf("split is not need\n");
					memory[i+1]=1;
				}else if(memory[i]>size){
						//need to split
						printf("split is needed\n");
						memory[i] -= size;
						
						memory[memory[i]+ 1 + 16] = 1;
						memory[memory[i]+16] = size;
						sp_os_mem = memory[memory[i]+16];
						//set the pointer
						ptr = (void *)&memory[sp_os_mem + 16];
						//set the rest of size to previous block
						return ptr;
				}else{
					printf("Go to next block\n");
					
				}
			}
		}
		printf("Allocation unsucessful\n");
		return NULL;
	}
	//If the allocation of the memory is unsucessful malloc returns NULL
	else {
		printf("Allocation unsucessful\n");
		return NULL;
	}
	
	//MyMalloc returns the pointer of the starting address of the memory block
}

void MyFree(void *point){
	//printf("MyFree calls %d \n",(void*)point);
	
    //binary search to find the address
    if((void*)point < &memory[n/2-1]){
    	//printf("first half\n");
    	for(i=start; i<n/2 -1; i++){
    		if(&memory[i+16]==(void*)point){
    			printf("found address\n");
    			memory[i+1]=0;//set flag to zero
    			break;
			}
		}
		
		
	}else{
		//printf("second half\n");
		for(i=n/2; i<n -1; i++){
    		if(&memory[i+16]==(void*)point){
    			printf("found address\n");
    			memory[i+1]=0;//set flag to zero
    			break;
			}
		}
	}
	//find the next block of memory is free or not
		sp_os_mem = i;
		i = memory[i]+16;//pass i for the next block
		sp_os_mem1 = i; 
		//combine two free blocks whether next block is empty
		//we call it merge
		if(memory[sp_os_mem1]!=0 && memory[sp_os_mem+1]==0){
			memory[sp_os_mem] += memory[sp_os_mem1] + 16;
			memory[sp_os_mem1] = 0;
			memory[sp_os_mem1+1] = 0;
			
		}else{
			printf("Nothing to merge\n");
		}
	
}
//////////////////////////////////////other methods(testing purpose methods//////////////////////////////////////////
//for testing purpose only
void printer(){
	int q=0;
	for(q=0;q<112;q++){
		printf("%d",memory[q]);
	}
	printf("\n");
}

void address_of_pointer(void *point){
	printf("\t%d\n",point);
}
