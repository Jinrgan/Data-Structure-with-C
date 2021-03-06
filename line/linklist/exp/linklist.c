#include "linklist.h"

linklist list_create()
{
	linklist H;
	if((H=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		printf("malloc failed!\n");
		return H;
	}
	H->data.coef = 0;
	H->data.exp = 0;
	H->next = NULL;

	return H;
}

linklist list_create2()
{
	linklist H,r,p;
	int value1, value2;
	if((H=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		printf("malloc failed!\n");
		return H;
	}
	H->data.coef = 0;
	H->data.exp = 0;
	H->next = NULL;
	r=H;

	while(1)
	{
		printf("input a number(-1 exit):");
		scanf("%d %d",&value1, &value2);
		if(value1 == -1)
			break;
		if((p=(linklist)malloc(sizeof(listnode)))==NULL)
		{
			printf("malloc failed\n");
			return H;
		}
		p->data.coef = value1;
		p->data.exp = value2;
		p->next = NULL;

		r->next = p;
		r=p;
	}
	return H;
}

int is_empty_linklist(linklist H)
{
	linklist p = H;
	return (p->next == NULL);
}


int list_head_insert(linklist H, float value1, int value2)
{
	linklist p;

	if((p=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data.coef = value1;
	p->data.exp  = value2;
	p->next = H->next;
	H->next = p;

	return 0;
}

int list_insert(linklist H, int pos,data_t value)
{
	linklist p,q;
	if(pos==0)
		p=H;
	else
		p=list_get(H,pos-1);
	if(p==NULL)
	{
		printf("para is invalid\n");
		return -1;
	}
	else
	{
		if((q=(linklist)malloc(sizeof(listnode)))==NULL)
		{
			printf("malloc failed\n");
			return -1;
		}
		q->data = value;
		q->next = p->next;
		p->next = q;
		return 0;
	}
}

int list_delete(linklist H, int pos)
{
	linklist p,q;
	if(pos == 0)
		p=H;
	else
		p=list_get(H,pos-1);

	if(p==NULL ||  p->next==NULL)
	{
		printf("para is invalid\n");
		return -1;
	}
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);
		q=NULL;
		return 0;
	}
}

linklist list_head_delete(linklist H)
{	
	linklist p = H;
	
	while(!is_empty_linklist(p))
	{
		list_delete(p, 0);
	}

	free(p);
	p = NULL;

	return p;
}

linklist list_get(linklist H, int pos)
{
	linklist p=H;
	int i=-1;
	if(pos<0)
	{
		printf("position is invalid:<0\n");
		return NULL;
	}
	while(p->next && i<pos)
	{
		p=p->next;
		i++;
	}
	//if(p->next)
	if(i==pos)
	{
		return p;
	}
	else
	{
		printf("position is invalid: > length\n");
		return NULL;
	}
}
/*linklist list_locate(linklist H, data_t value)
{
	linklist p=H->next;
	while(p&&p->data !=value)
	{
		p=p->next;
	}

	return p;
}
*/
void list_reserve(linklist H)
{
	linklist p,q;
	p=H->next;
	H->next = NULL;

	while(p)
	{
		q=p;
		p=p->next;
		q->next = H->next;
		H->next = q;
	}
}

/*int list_order_insert(linklist H, data_t value)
{
	linklist p, q;
	if((p=(linklist)malloc(sizeof(listnode)))==NULL)
	{
		printf("malloc faied\n");
		return -1;
	}
	p->data = value;
	q = H;
	while(q->next && q->next->data < value)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;

	return 0;
}
*/
void list_show(linklist H)
{
	while(H->next)
	{
		printf("%f, %d\t", H->next->data.coef, H->next->data.exp);
		H = H->next;
	}
	printf("\n");
}
