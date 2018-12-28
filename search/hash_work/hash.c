#include <stdio.h>
#include <stdlib.h>

#define N 12

typedef struct linknode{
	int data;
	struct linknode *next;
}linknode_t;

void insert_hash(linknode_t *hash, int data);
int find_hash(linknode_t *hash, int data);

int main(int argc, const char * argv[])
{
	int data[N] = {20, 76, 53, 2, 7, 89, 100, 36, 24, 25, 37, 77};
	linknode_t hash[N] = {0, NULL};
	int i = 0;
	for(; i < N; i++)
		insert_hash(hash, data[i]);
		
	find_hash(hash, atoi(argv[1])) ? printf("%d is exist\n", atoi(argv[1])) : printf("%d is not exist\n", atoi(argv[1]));
	
	return 0;
}

void insert_hash(linknode_t *hash, int data)
{
	int key = data % N;
	
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = data;
	node->next = NULL;
	
	linknode_t *p = &hash[key];
	while(p->next)
	{
		if(p->next->data < data)
			p = p->next;
		else
			break;
	}
	node->next = p->next;
	p->next = node;
	
}

int find_hash(linknode_t *hash, int data)
{
	int key = data % N;
	linknode_t *p = &hash[key];
	
	while(p->next)
	{
		if(data == p->next->data)
			return 1;
		else if(data < p->next->data)
			return 0;
		else
			p = p->next;
	}
}