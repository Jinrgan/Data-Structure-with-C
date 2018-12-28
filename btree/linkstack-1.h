#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

typedef btree_pnode datatype_ls;

typedef struct node{
	datatype_ls data;
	struct node* next;
}listnode,*linklist;

extern linklist stack_create();
extern int stack_empty(linklist s);
extern int stack_push(linklist s,datatype_ls value);
extern datatype_ls stack_pop(linklist s);


#endif
