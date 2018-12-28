#include "sqstack.h"

seq_pqueue init1_seqqueue(void)
{
	seq_pqueue q;
	q=(seq_pqueue)malloc(sizeof(seq_queue));
	if(q==NULL)
	{
		perror("malloc");
		exit(-1);
	}
	q->front=q->rear=MAXSIZE-1;

	return q;
}

void init_seqqueue(seq_pqueue *Q)
{
	*Q=(seq_pqueue)malloc(sizeof(seq_queue));
	if((*Q)==NULL)
	{
		perror("malloc");
		exit(-1);
	}
	(*Q)->front=(*Q)->rear=MAXSIZE-1;
	
	return;
}
//判断队列是否满
bool is_full_seqqueue(seq_pqueue q)
{
	if((q->rear+1)%MAXSIZE == q->front)
		return true;
	else
		return false;
}
//入对
bool in_seqqueue(datatype data,seq_pqueue q)
{
	//判断队列是否满
	if(is_full_seqqueue(q)){
		printf("队列已满!\n");
		return false;
	}

	//入对
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=data;
	return true;
}
bool is_empty_seqqueue(seq_pqueue q)
{
	if(q->rear == q->front)
		return true;
	else
		return false;
}
//出队
bool out_seqqueue(seq_pqueue q,datatype *D)
{
	//判断队列是否空
	if(is_empty_seqqueue(q)){
		printf("队列已空!\n");
		return false;
	}

	//出队
	q->front=(q->front+1)%MAXSIZE;
	*D=q->data[q->front];

	return true;
}

void show_seqqueue(seq_pqueue q)
{
	int i;
	if(is_empty_seqqueue(q))
		return;
	//非空时，从对头打印到队尾
	for(i=(q->front+1)%MAXSIZE; i!=(q->rear+1)%MAXSIZE; i=(i+1)%MAXSIZE)
	{
		printf("%d\t",q->data[i]);
	}
	printf("\n");
}

bool is_sorted_seqqueue(seq_pqueue q)
{
	seq_pqueue p = q;
	int i = (p->front+1)%MAXSIZE;
	if(is_empty_seqqueue(p))
		return false;
	
	while(i != (p->rear)%MAXSIZE)
	{
		if(p->data[i] > p->data[i+1])
		{
			return 0;
		}
		i=(i+1)%MAXSIZE;
	}
	
	return true;
}