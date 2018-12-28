#ifndef __HINKLIST_H__
#define __HINKLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node{
	data_t data;
	struct node * next;
}listnode, * linklist;

extern linklist list_create();
extern linklist list_create2();
extern int is_empty_linklist(linklist H);
extern int list_head_insert(linklist H, data_t value);
extern int list_insert(linklist H, int pos, data_t value);
extern int list_delete(linklist H, int pos);
extern linklist list_head_delete(linklist H);
extern linklist list_get(linklist H, int pos);
extern linklist list_locate(linklist H, data_t value);
extern void list_reserve(linklist H);
extern void list_show(linklist H);
extern int list_order_insert(linklist H, data_t value);

#endif
