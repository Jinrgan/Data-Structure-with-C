#include "balltimer.h"

int main()
{
	int i = 0;
	
	seq_pqueue q;
	q = init1_seqqueue();
	
	for(i = 1; i <= 27; i++)
		in_seqqueue(i, q);
	show_seqqueue(q);
	
	sqstack * min, * five_min, * hour;
	min = stack_create(4);
	five_min = stack_create(11);
	hour = stack_create(11);
	
	int tm_hour = 0;
	while(1)
	{
		if(!stack_full(min))
		{
			stack_push(min, out_seqqueue(q));
			continue;
		}
		popall_to_queue(min, q);
		//stack_push(five_min, out_seqqueue(q));
		if(!stack_full(five_min))
		{
			stack_push(five_min, out_seqqueue(q));
			continue;
		}
		popall_to_queue(five_min, q);
		//stack_push(hour, out_seqqueue(q));
		if(!stack_full(hour))
		{
			stack_push(hour, out_seqqueue(q));
			continue;
		}
		tm_hour += 12;
		popall_to_queue(hour, q);
		in_seqqueue(out_seqqueue(q), q);
		if(is_full_seqqueue(q) && is_sorted_seqqueue(q))
		{
			printf("%d\n", tm_hour);
			return 0;
		}
		
	}
	
	return 0;
}