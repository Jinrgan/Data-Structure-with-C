#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char dataype_bt;

typedef struct btreenode{
	dataype_bt data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

extern btree_pnode create_btree1(void);
extern void create_btree(btree_pnode *T);
extern void pre_order(btree_pnode t);
extern void unpre_order(btree_pnode t);
extern void mid_order(btree_pnode t);
extern void post_order(btree_pnode t);
extern void level_order(btree_pnode t);
#endif
