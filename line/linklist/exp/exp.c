#include "linklist.h"

void myexp();

int main()
{
	myexp();
	
	return 0;
}

void myexp()
{
	linklist Ha, Hb, Hc;
	linklist pa, pb;
	Ha = list_create();
	Hb = list_create();
	Hc = list_create();

	list_head_insert(Ha, 3, 16);
	list_head_insert(Ha, 8, 8);
	list_head_insert(Ha, 2, 1);
	list_head_insert(Ha, 5, 0);
	list_show(Ha);
	list_head_insert(Hb, -8, 8);
	list_head_insert(Hb, 23, 6);
	list_head_insert(Hb, 6, 1);

	pa = Ha->next;
	pb = Hb->next;
	while(pa && pb)
	{
		if(pa->data.exp < pb->data.exp)
		{
			list_head_insert(Hc, pa->data.coef, pa->data.exp);
			pa = pa->next;
		}
		else if(pa->data.exp > pb->data.exp)
		{
			list_head_insert(Hc, pb->data.coef, pb->data.exp);
			pb = pb->next;
		}
		else if(pa->data.exp == pb->data.exp)
		{
			if(pa->data.coef + pb->data.coef)
				list_head_insert(Hc, pa->data.coef + pb->data.coef, pa->data.exp);
			pa = pa->next;
			pb = pb->next;
		}
	}
	while(pa)
	{
		list_head_insert(Hc, pa->data.coef, pa->data.exp);
		pa = pa->next;
	}

	list_reserve(Hc);

	list_show(Hc);
	
}
