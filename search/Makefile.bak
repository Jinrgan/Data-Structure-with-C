CC = gcc
CFLAGS = -o0 -g -Wall 

SRC=seqsearch.c
OBJS=seqsearch

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -rf $(OBJS)
