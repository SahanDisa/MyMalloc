#include <stdio.h>
#include <stddef.h>

#define mem_size 25000

char memory[25000];//The size of the memory is 25000bytes with 1 char = 1 byte 


//meta data block definition
//doubly linked list
struct block{
 size_t size;//Carries the size of the block described by it
 int free;//This flag is used to know whether the block described by the metadata structure is free or not -- > if free, it is set to 1. Otherwise 0
 struct block *next; //Points to the next metadata block
};

//point to the initial block of memory which initially free
struct block *freeList=(void*)memory;

//function definitions of the header file
void initialize();
void split(struct block *fitting_slot,size_t size);
void *MyMalloc(size_t noOfBytes);
void merge();
void MyFree(void* ptr);


//implementation

void initialize(){
 freeList->size=mem_size-sizeof(struct block);
 freeList->free=1;
 freeList->next=NULL;
 printf("%d\n",freeList->size);
}

void MyFree(void* ptr){
 if(((void*)memory<=ptr)&&(ptr<=(void*)(memory+25000))){
  struct block* curr=ptr;
  --curr;
  curr->free=1;
  merge();
 }
 else printf("Please provide a valid pointer allocated by MyMalloc\n");
}

void split(struct block *fitting_slot,size_t size){
 struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block));
 new->size=(fitting_slot->size)-size-sizeof(struct block);
 new->free=1;
 new->next=fitting_slot->next;
 fitting_slot->size=size;
 fitting_slot->free=0;
 fitting_slot->next=new;
}

//If the allocation is success MyMalloc returns a void pointer else it returns NULL
void *MyMalloc(size_t noOfBytes){
 struct block *curr,*prev; // to traverse through the other block of memory blocks
 void *result;//pointer is to return the starting address of the allocated memory
 
 if(!(freeList->size)){
 	printf("%d\n",freeList->size);
	initialize();
	printf("Memory initialized\n");
 }
 
 curr=freeList;//temp pointer to start of the block
 
 while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL)){
  prev=curr;
  curr=curr->next;
  printf("One block checked %d\n",prev->size);
 }
 if((curr->size)==noOfBytes){
  curr->free=0;
  result=(void*)(++curr);
  printf("Exact fitting block allocated of %d\n",curr->size);
  return result;
 }
 else if((curr->size)>(noOfBytes+sizeof(struct block))){
  split(curr,noOfBytes);
  result=(void*)(++curr);
  printf("Fitting block allocated with a split %d\n",curr->size);
  return result;
 }
 //Allocation unsuccess
 else{
  result=NULL;
  printf("Sorry. No sufficient memory to allocate\n");
  return result;
 }
}


//To avoid externel fragmentations
//merge the consecutive free blocks
void merge(){
 struct block *curr,*prev;
 curr=freeList;
 while((curr->next)!=NULL){
  if((curr->free) && (curr->next->free)){
   curr->size+=(curr->next->size)+sizeof(struct block);
   curr->next=curr->next->next;
  }
  prev=curr;
  curr=curr->next;
 }
}

