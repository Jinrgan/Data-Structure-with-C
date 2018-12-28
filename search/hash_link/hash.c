#include "hash.h"

int p;

void init_hash(hash_tp *Hp,int m)
{
	(*Hp) = (hash_tp)malloc(sizeof(hash_tb1));
	if(NULL == *Hp){
		perror("malloc");
		exit(1);
	}
	
	(*Hp)->length = m;
	
	(*Hp)->h = (datatype *)malloc((*Hp)->length*sizeof(datatype));
	if(NULL == (*Hp)->h){
		perror("malloc");
		exit(1);
	}
	
	int i;
	for(i = 0; i < (*Hp)->length; i++)
		(*Hp)->h[i] = NULL;
}

int fun(int m)
{
	int i;
	
	for(; m > 1; m--){
		for(i = 2; i < m; i++)
			if(m % i == 0)
				break;
		if(i>=m)  //可选？
			return m;
	}
	return -1;
}

void create_hash(hash_tp hp, datatype_el *a)
{
	int hash_val, i;
	list_pnode new;

	p = fun(hp->length);
	if(p == -1)
		exit(1);
	
	for(i = 0; i < N; i++){
		//1.用除留余数法构建hash函数,用链地址法处理冲突
		hash_val = a[i] % p;
		//2.申请结点空间
		new = (list_pnode)malloc(sizeof(list_node));
		if(NULL == new){
			perror("malloc");
			exit(1);
		}
		new->data = a[i];
		//3.将记录插入到hash_val位置的指针只想链表中
		new->next = hp->h[hash_val];
		hp->h[hash_val] = new;

		hash_show(hp, hash_val, new);
		sleep(1);
	}
	
}

list_pnode hash_search(hash_tp hp, int key)
{
	int hash_val;
	list_pnode tp;

	hash_val = key % p; //用除留余数法得到hash地址
	for(tp = hp->h[hash_val];tp != NULL; tp = tp->next)
		if(tp->data == key)
			return tp;
	return NULL;
}

void hash_show(hash_tp hp, int hash_val, list_pnode new)
{
	list_pnode p;
	int i;

	for(i = 0; i < hp->length; i++){
		printf("hp->h[%02d]:", i);
		for(p = hp->h[i]; p != NULL; p = p->next)
			printf("--->%d", p->data);
		if(i == hash_val)
			printf(" now input:%d", new->data);
		printf("\n");
	}
	printf("****************************************\n");
}
