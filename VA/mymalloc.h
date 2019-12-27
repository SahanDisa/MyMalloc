#ifndef _MYMALLOC_H_
#define _MYMALLOC_H_

#include<stdio.h>
#include<stddef.h>

extern void *MyMalloc(size_t size);
extern void MyFree(void *point);

//testing functions
extern void printer();
extern void address_of_pointer(void *point);

#endif
