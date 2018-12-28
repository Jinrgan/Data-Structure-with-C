#include "hash.h"

int main(int argc, const char *argv[])
{
	hash_tp hp;
	int m,i,key;
	char ch;

	int a[]={23,34,14,38,46,16,68,15,7,31,26};
	//1、根据记录个数得到hash表的长度
	m=(int)ceil(N/0.75);
	//2、初始化hash表空间
	init_hash(&hp,m);
	//3、创建hash表
	create_hash(hp,a);
	//4、hash表查找
	while(1)
	{
		printf("please input key:");
		scanf("%d",&key);
		i=hash_search(hp,key);
		if(i==-1)
			puts("search error!");
		else
			printf("search %d at %d\n",key,i);
		printf("continue?(Y/y):");
		while(getchar()!='\n');
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
			continue;
		else
			break;
	}

	return 0;
}
