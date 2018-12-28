#include "linklist.h"

int joseph(int n, int k, int m);

int main()
{
	joseph(8, 3, 4);

	return 0;
}


int joseph(int n, int k, int m)
{
	int i; linklist p, L, r;
	L = NULL;
	
	for(i = 1; i <= n; i++)
	{
		p = (linklist)malloc(sizeof(listnode));
		p->data = i;
		if(L == NULL)
			L = p;
		else 
			r->next = p;
		r = p;
	}
	p->next = L;
	r = L;

	for(i=1; i<k; i++)
		r = r->next;

	while(r->next != r)
	{
		for(i=1; i <= m-2; i++)
			r = r->next;
		p = r->next;
		
		r->next = p->next;
		printf("%d, ", p->data);
		free(p);
		r = r->next;
	}
	printf("%d\n", r->data);

	return 0;
}
