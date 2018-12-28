#include "seqlist.h"

int main(int argc, const char *argv[])
{
	int i=0;

	seqlist_t *L=NULL;
	L = create_seqlist();
	for(i=0; i<=60; i+=10)
		insert_seqlist(L,i,0);
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);

	puts("=============================================================");
	puts("search data = 3:");
	printf("data = 3 pos is %d\n", search_seqlist(L,3));
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);

	puts("=============================================================");
	puts("delete data = 3:");
	delete_seqlist(L, search_seqlist(L, 3));
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);

	puts("=============================================================");
	puts("change data[2] = 99:");
	change_seqlist(L,99,2);
	printf("seqlist L length is %d\n", get_length_seqlist(L));
	show_seqlist(L);

	puts("=============================================================");
	
	printf("delete: %d\n", L->data[2]);
	delete_seqlist(L, 2);
	show_seqlist(L);

	printf("delete: %d\n", L->data[2]);
	delete_seqlist(L, 2);
	show_seqlist(L);

	L = clear_seqlist(L);
	printf("%d\n", is_empty_seqlist(L));
	L = clear_seqlist(L);
	//show_seqlist(L);

	return 0;
}
