#include "seqqueue.h"

int main(int argc, const char *argv[])
{
	int i = 0;
	seq_pqueue q;
	init_seqqueue (&q);
	
	for(i=0; i < 27; i++)
	{
		in_seqqueue(i, q);
	}
	
	printf("%d\n", is_sorted_seqqueue(q));
	
	return 0;
}