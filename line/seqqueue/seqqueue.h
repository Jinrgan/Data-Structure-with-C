#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 27
typedef int datatype;

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

extern seq_pqueue init1_seqqueue(void);
extern void init_seqqueue(seq_pqueue *Q);
extern bool is_full_seqqueue(seq_pqueue q);
extern bool is_empty_seqqueue(seq_pqueue q);
extern bool in_seqqueue(datatype data,seq_pqueue q);
extern int  out_seqqueue(seq_pqueue q);
extern void show_seqqueue(seq_pqueue q);
extern bool is_sorted_seqqueue(seq_pqueue q);

#endif
