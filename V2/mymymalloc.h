#include<stdio.h>
#include<stddef.h>

char memory[25000];


//meta block of the allocating memory
struct memory_block{
	int size;
	int free;//either 0 or 1
	struct memory_block *prev;
	struct memory_block *next;
};

//freed memory meta data pointer
struct memory_block *free_block;

//Initially we need to defined the free memory meta data block
//Actually initially we have 24,968 bytes (32 bytes for memory_block) 
void InitMemory(){
	free_block->size=25000-sizeof(struct memory_block);
	free_block->free=1;
	free_block->next=NULL;	
}

void *MyMalloc(int NoOfBytes){
	//free_block->size = NoOfBytes;
	printf("%d %d",sizeof(free_block),NoOfBytes);
}


