#include "seqlist.h"

int main()
{
	int i = 0;
	seqlist_t *L = NULL;
	L = create_seqlist();
	
	for(; i <= 70; i += 10)
	{
		insert_seqlist(L, i, 0);
	}

	show_seqlist(L);
	printf("=======================================\n");

	reserve_seqlist(L);
	show_seqlist(L);

	return 0;
}
