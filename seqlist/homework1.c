#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

int main(int argc, const char *argv[])
{
	int i=0,j=0;

	seqlist_t *L=NULL;
	L = create_seqlist();
	for(i=0; i<=4; i++)
		insert_seqlist(L,i,0);
	for(i=4; i>=0; i--)
		insert_seqlist(L,i,0);
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);

	puts("=============================================================");
	puts("delete repeat data :");
	for(i=0; i <= L->last; i++)
	{
		for(j = i+1; j <= L->last; j++)
		{
			if(L->data[i] == L->data[j])
				delete_seqlist(L, j);
		};
	};
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);
	

	clear_seqlist(L);
	return 0;
}
