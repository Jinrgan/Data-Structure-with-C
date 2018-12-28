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
		(*Hp)->h[i] = -1;
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

void create_hash(hash_tp hp, datatype *a)
{
	int hash_val, i;
	p = fun(hp->length);
	if(p == -1)
		exit(1);
	
	for(i = 0; i < N; i++){
		//1.用除留余数法构建hash函数
		hash_val = a[i] % p;
		//2.用线性探查法处理冲突
		while(hp->h[hash_val] != -1)
			hash_val = (hash_val+1) % hp->length;
		//3.将记录存储在hash_val的位置
		hp->h[hash_val] = a[i];
		hash_show(hp, hash_val);
		sleep(1);
	}
	
}

int hash_search(hash_tp hp, int key)
{
	int hash_val, flag = 0;
	
	hash_val = key % p; //用除留余数法得到hash地址
	
	while(hp->h[hash_val] != key){
		hash_val = (hash_val+1) % hp->length;
		flag++;
		if(flag == hp->length)
			return -1;
	}
	return hash_val;
}

void hash_show(hash_tp hp, int hash_val)
{
	int i;
	
	for(i = 0; i < hp->length; i++)
		if(i == hash_val)
			printf("hp->h[%02d]:%d <---当前插入\n", i, hp->h[i]);
		else
			printf("hp->h[%02d]:%d\n", i, hp->h[i]);
	printf("*****************************************\n");
}