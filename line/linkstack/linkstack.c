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


int stack_push(linklist s,datatype value)
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

datatype stack_pop(linklist s)
{
	linklist p;
	datatype ret;

	p=s->next;
	s->next=p->next;
	ret=p->data;

	free(p);
	p=NULL;

	return ret;
}

datatype stack_top(linklist s)
{
	return (s->next->data);
}

void stack_clear(linklist s)
{
	linklist p;

	printf("clear:");
	p=s->next;
	while(p)
	{
		s->next=p->next;
		printf("%d ",p->data);
		free(p);
		p=s->next;
	}
	putchar(10);
}
void stack_free(linklist s)
{
	linklist p;

	printf("free:");
	p=s;
	while(p)
	{
		s=s->next;
		printf("%d ",p->data);
		free(p);
		p=s;
	}
	putchar(10);

}

