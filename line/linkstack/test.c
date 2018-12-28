#include "linkstack.h"

int main(int argc, const char *argv[])
{
	linklist s;
	
	s=stack_create();

	stack_push(s,10);
	stack_push(s,20);
	stack_push(s,30);
	stack_push(s,40);
	stack_push(s,50);
	stack_push(s,60);
	
#if 0
	while(!stack_empty(s))
	{
		printf("%d ",stack_pop(s));
	}
	putchar(10);
#endif
//	stack_clear(s);
	stack_free(s);
	return 0;
}
