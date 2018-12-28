#include "btree.h"

int main(int argc, const char *argv[])
{
	btree_pnode t;

	create_btree(&t);//创建二叉树

	printf("先序遍历序列：");
	pre_order(t);
	putchar(10);

	printf("先序非递归遍历序列：");
	unpre_order(t);
	putchar(10);

	printf("中序遍历序列：");
	mid_order(t);
	putchar(10);

	printf("后序遍历序列：");
	post_order(t);
	putchar(10);

	printf("层次遍历序列：");
	level_order(t);
	putchar(10);

	return 0;
}
