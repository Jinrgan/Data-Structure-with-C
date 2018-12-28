#include "linklist.h"

int main(int argc, const char *argv[])
{
	linklist H;

	H=list_create();
	list_head_insert(H,10);
	list_head_insert(H,20);
	list_head_insert(H,30);
	list_head_insert(H,40);
	list_head_insert(H,50);
	list_head_insert(H,60);
	list_head_insert(H,70);
	list_head_insert(H,88);
	list_head_insert(H,90);

	list_show(H);
	list_reserve(H);
	list_show(H);

	list_order_insert(H,43);
	list_order_insert(H,80);
	list_show(H);

	H = list_head_delete(H);
	if(H == NULL)
	{
		printf("linklist is deleted!\n");
	}
	printf ("%p\n", H);

	return 0;
}
