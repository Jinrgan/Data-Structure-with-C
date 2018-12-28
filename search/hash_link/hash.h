#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define N 11

typedef int datatype_el;

typedef struct listnode
{
	datatype_el data;
	struct listnode *next;
}list_node, *list_pnode;

typedef list_pnode datatype;
typedef struct hashtb1{
	datatype *h;
	int length;
}hash_tb1, *hash_tp;

extern void init_hash(hash_tp *Hp,int m);
extern void create_hash(hash_tp hp, datatype_el *a);
extern list_pnode hash_search(hash_tp hp, int key);
extern void hash_show(hash_tp hp, int hash_val, list_pnode new);

#endif
