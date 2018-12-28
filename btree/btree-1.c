#include "btree.h"
#include "linkqueue.h"
#include "linkstack.h"

btree_pnode create_btree1(void)
{
	dataype_bt ch;
	btree_pnode new;
	scanf("%c",&ch);
	if('#'==ch)
	{
		return NULL;
	}
	else
	{
		//创建根结点
		new=(btree_pnode)malloc(sizeof(btree_node));
		if(NULL==new)
		{
			perror("malloc");
			exit(-1);
		}
		new->data=ch;
		//用相同方法创建左子数
		new->lchild=create_btree1();
		//用相同方法创建右子数
		new->rchild=create_btree1();
	}
	return new;
}

void create_btree(btree_pnode *T)
{
	dataype_bt ch;
	scanf("%c",&ch);
	if('#'==ch)
	{
		return ;
	}
	else{
		//创建根结点
		(*T)=(btree_pnode)malloc(sizeof(btree_node));
		if(NULL==(*T))
		{
			perror("malloc");
			exit(-1);
		}
		(*T)->data=ch;
		//用相同方法创建左子数
		create_btree(&((*T)->lchild));
		//用相同方法创建右子数
		create_btree(&((*T)->rchild));
	}
}
//先序遍历
void pre_order(btree_pnode t)
{
	if(t!=NULL)
	{
		//访问根结点
		printf("%c",t->data);
		//先序遍历左子树
		pre_order(t->lchild);
		//先序遍历右子树
		pre_order(t->rchild);
	}
}
//先序非递归遍历
void unpre_order(btree_pnode t)
{
	linklist top;//top为指向栈顶结点的指针

	top=stack_create();//初始化链式栈
	while(t!=NULL || !(stack_empty(top))){
		if(t!=NULL){
			printf("%c",t->data);
			if(t->rchild !=NULL)
				stack_push(top,t->rchild);
			t=t->lchild;
		}else
			t=stack_pop(top);
	}
}

//中序遍历
void mid_order(btree_pnode t)
{
	if(t!=NULL)
	{
		//中序遍历左子树
		mid_order(t->lchild);
		//访问根结点
		printf("%c",t->data);
		//中序遍历右子树
		mid_order(t->rchild);
	}
}

//后序遍历
void post_order(btree_pnode t)
{
	if(t!=NULL)
	{
		//后序遍历左子树
		post_order(t->lchild);
		//后序遍历右子树
		post_order(t->rchild);
		//访问根结点
		printf("%c",t->data);
	}
}
//层次遍历
void level_order(btree_pnode t)
{
	link_pqueue q;
	init_linkqueue(&q);//初始化链式队列


	while(t!=NULL)
	{
		//访问t指向的结点数据
		printf("%c",t->data);
		//当t的左指针不为空，则入队
		if(t->lchild!=NULL)
			in_linkqueue(t->lchild,q);
		//当t的右指针不为空，则入队
		if(t->rchild!=NULL)
			in_linkqueue(t->rchild,q);
		//队列不为空，则出队
		if(!is_empty_linkqueue(q))
			out_linkqueue(q,&t);
		else
			break;
	}
}
