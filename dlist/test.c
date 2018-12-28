#include "dlist.h"

int main(int argc, const char *argv)
{
	dlistnode * H;

	H = dlist_create();
	dlist_show(H);

	return 0;
}
