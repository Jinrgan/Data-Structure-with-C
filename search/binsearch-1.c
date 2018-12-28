#include <stdio.h>

#define N 12

int binsearch(int *a, int key);
int main(void)
{
	int a[N] = {3,12,18,20,32,55,60,68,80,86,90,100};
	int i, key;
	char ch;

	while(1){
		printf("pls input key:");
		scanf("%d", &key);
		i = binsearch(a, key);
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

int binsearch(int *a, int key)
{
	int low, high, mid;
	
	low = a[0];
	high = N-1;
	while(low <= high){
		mid = (low + high) / 2;			//找到中间位置
		if(key == a[mid])
			return mid;					//查找成功，返回mid
		else if(key < a[mid])
			high = mid-1;				//如果key < mid位置记录的key，则让high = mid-1
		else							//如果key > mid位置记录的key，则让low = mid+1
			low = mid+1;
	}
	return -1; //err					//查找失败，返回-1
}