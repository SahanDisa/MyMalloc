#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define MAX_MALLOC_SIZE (25000)

#include<stddef.h>

//meta data block definition
struct block{
 size_t size;//Carries the size of the block described by it
 int free;//This flag is used to know whether the block described by the metadata structure is free or not -- > if free, it is set to 1. Otherwise 0
 struct block *next; //Points to the next metadata block
};

//function definitions of the header file
void initialize();
void split(struct block *fitting_slot,size_t size);
void *MyMalloc(size_t noOfBytes);
void merge();
void MyFree(void* ptr);

#endif
