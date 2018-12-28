#include "dlist.h"


dlistnode * dlist_create() {
	dlistnode *H, *p, *r;
	int n;

	if ((H = (dlistnode *)malloc(sizeof(dlistnode))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

	H->prior = H;
	H->next = H;
	H = r;
	
	while (1) {
		printf("please input(-1 exit):");
		scanf("%d", &n);
		if (n ==-1) {
			break;
		}

		if ((p = (dlistnode *)malloc(sizeof(dlistnode))) == NULL) {
			printf("malloc failed\n");
			return NULL;
		}
		p->data = n;

		p->prior = r;
		p->next = r->next;
		r->next = p;
		H->prior = p;
		r = p;

	}

	return H;
}

void dlist_show(dlistnode * H) {
	dlistnode * p;

	p = H->next;

	while (p != H) {
		printf("%d", p->data);
		p = p->next;
	}

	puts("");
}
