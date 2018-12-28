#include <stdio.h>

#define N 10

int seqsearch(int *a, int key);
int main(void)
{
	int a[] = {3,5,7,2,9,8,4,3,10,2};
	int i, key;
	char ch;

	while(1){
		printf("pls input key:");
		scanf("%d", &key);
		i = seqsearch(a, key);
		if(i == -1){
			printf("search error!\n");
		}else{
			printf("search %d at %d\n", key, i);
		}
		printf("continue?(Y/y)");
		while(getchar() != '\n');
		scanf("%c", &ch);
		if(ch == 'y' || ch == 'Y')
			continue;
		else
			break;
	}

	return 0;
}

int seqsearch(int *a, int key)
{
	int i;
	
	for(i = N-1; i>=0; i--)
		if(key == a[i])
			return i; //ok
	return i; //err
}