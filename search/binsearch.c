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
		mid = (low + high) / 2;			//�ҵ��м�λ��
		if(key == a[mid])
			return mid;					//���ҳɹ�������mid
		else if(key < a[mid])
			high = mid-1;				//���key < midλ�ü�¼��key������high = mid-1
		else							//���key > midλ�ü�¼��key������low = mid+1
			low = mid+1;
	}
	return -1; //err					//����ʧ�ܣ�����-1
}