#include "balltimer.h"

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
	
	seq_pqueue(q);
	init_seqqueue(&q);
	
	popall_to_queue(s, q);

	show_seqqueue(q);
	return 0;
}
