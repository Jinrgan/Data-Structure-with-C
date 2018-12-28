CC = gcc
CFLAGS = -o0 -g -Wall 

SRC=btree.c test.c linkstack.c linkqueue.c
OBJS=test

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -rf $(OBJS)
