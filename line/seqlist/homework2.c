#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

int main(int argc, const char *argv[])
{
	int i=0;

	seqlist_t *L1=NULL,*L2=NULL;
	L1 = create_seqlist();
	for(i=0; i<=4; i++)
		insert_seqlist(L1, i, 0);	
	printf("seqlist L1 length is %d\n", get_length_seqlist(L1));
	show_seqlist(L1);
	L2 = create_seqlist();
	for(i=5; i>=0; i--)
		insert_seqlist(L2, i, 0);
	printf("seqlist L2 length is %d\n", get_length_seqlist(L2));
	show_seqlist(L2);

	puts("=============================================================");
	puts("combine L1 and L2:");
	for(i=0; i <= L2->last; i++)
		insert_seqlist(L1, L2->data[i], L1->last + 1);
	printf("seqlist L1 length is %d\n", get_length_seqlist(L1));
	show_seqlist(L1);
	

	clear_seqlist(L1);
	clear_seqlist(L2);
	return 0;
}
