#ifndef __BALLTIMER_H__
#define __BALLTIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 28
typedef int datatype;

typedef struct node{
	datatype *data;
	int maxlen;
	int top;
}sqstack;

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

extern sqstack* stack_create(int len);
extern int stack_empty(sqstack* s);
extern int stack_full(sqstack* s);
extern int stack_push(sqstack* s,datatype value);
extern datatype stack_pop(sqstack* s);

extern seq_pqueue init1_seqqueue(void);
extern bool is_full_seqqueue(seq_pqueue q);
extern bool is_empty_seqqueue(seq_pqueue q);
extern bool in_seqqueue(datatype data,seq_pqueue q);
extern int  out_seqqueue(seq_pqueue q);
extern void show_seqqueue(seq_pqueue q);
extern bool is_sorted_seqqueue(seq_pqueue q);
extern void popall_to_queue(sqstack *s, seq_pqueue q);

#endif