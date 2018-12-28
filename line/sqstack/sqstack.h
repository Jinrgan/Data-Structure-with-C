#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

typedef struct node{
	datatype *data;
	int maxlen;
	int top;
}sqstack;

extern sqstack* stack_create(int len);
extern int stack_empty(sqstack* s);
extern int stack_full(sqstack* s);
extern void stack_clear(sqstack* s);
extern int stack_push(sqstack* s,datatype value);
extern datatype stack_pop(sqstack* s);
extern datatype stack_top(sqstack* s);
extern void stack_free(sqstack *s);

#endif
