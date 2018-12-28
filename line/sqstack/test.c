#include "sqstack.h"

int main(int argc, const char *argv[])
{
	sqstack *s;
	int n=5;

	s=stack_create(n);

	stack_push(s,10);
	stack_push(s,20);
	stack_push(s,30);
	stack_push(s,40);
	stack_push(s,50);
	stack_push(s,60);
	
	while(!stack_empty(s))
	{
		printf("%d ",stack_pop(s));
	}
	putchar(10);

	stack_clear(s);
	stack_free(s);

	return 0;
}
