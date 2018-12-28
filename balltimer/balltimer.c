#include "balltimer.h"

sqstack* stack_create(int len)
{
	sqstack *s;

	if((s=(sqstack *)malloc(sizeof(sqstack)))==NULL)
	{
		puts("malloc failed");
		return NULL;
	}
	if((s->data=(datatype *)malloc(len*sizeof(datatype)))==NULL)
		
	{
		puts("malloc failed");
		return NULL;
	}
	s->maxlen=len;
	s->top=-1;

	return s;
}

int stack_empty(sqstack* s)
{
	return (s->top==-1 ? 1:0);
}

int stack_full(sqstack* s)
{
	return (s->top==(s->maxlen-1) ? 1:0);
}

int stack_push(sqstack* s,datatype value)
{
	if(s->top==s->maxlen-1){
		puts("stack is full");
		return -1;
	}

	s->data[s->top+1]=value;
	s->top++;

	return 1;
}

datatype stack_pop(sqstack* s)
{
	s->top--;
	return s->data[s->top+1];
}

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

bool is_full_seqqueue(seq_pqueue q)
{
	if((q->rear+1)%MAXSIZE == q->front)
		return true;
	else
		return false;
}

bool is_empty_seqqueue(seq_pqueue q)
{
	if(q->rear == q->front)
		return true;
	else
		return false;
}

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

int out_seqqueue(seq_pqueue q)
{
	datatype d;
	//判断队列是否空
	if(is_empty_seqqueue(q)){
		printf("队列已空!\n");
		return -1;
	}

	//出队
	q->front = (q->front+1)%MAXSIZE;
	d = q->data[q->front];

	return d;
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
			return false;
		}
		i=(i+1)%MAXSIZE;
	}
	
	return true;
}

void popall_to_queue(sqstack *s, seq_pqueue q)
{
	while(!stack_empty(s))
		in_seqqueue(stack_pop(s), q);
}