#include "linkstack.h"

linklist stack_create()
{
	linklist s;

	if((s=(linklist)malloc(sizeof(listnode)))==NULL){
		puts("malloc failed");
		return NULL;
	}
	s->next=NULL;

	return s;
}
int stack_empty(linklist s)
{
	return (s->next==NULL ? 1:0);
}


int stack_push(linklist s,datatype_ls value)
{
	linklist p;
	if((p=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		puts("malloc failed");
		return -1;
	}

	p->data = value;
	p->next=s->next;
	s->next = p;

	return 0;
}

datatype_ls stack_pop(linklist s)
{
	linklist p;
	datatype_ls ret;

	p=s->next;
	s->next=p->next;
	ret=p->data;

	free(p);
	p=NULL;

	return ret;
}

