#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define N 11

typedef int datatype;
typedef struct hashtb1{
	datatype *h;
	int length;
}hash_tb1, *hash_tp;

extern void init_hash(hash_tp *Hp,int m);
extern void create_hash(hash_tp hp, datatype *a);
extern int hash_search(hash_tp hp, int key);
extern void hash_show(hash_tp hp, int hash_val);

#endif