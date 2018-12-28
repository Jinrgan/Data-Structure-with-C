#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

typedef struct node{
	datatype data;
	struct node* next;
}listnode,*linklist;

extern linklist stack_create();
extern int stack_empty(linklist s);
extern void stack_clear(linklist s);
extern int stack_push(linklist s,datatype value);
extern datatype stack_pop(linklist s);
extern datatype stack_top(linklist s);
extern void stack_free(linklist s);

#endif
