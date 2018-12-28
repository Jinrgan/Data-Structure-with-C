CC = gcc
CFLAGS = -O0 -g -Wall

SRC=seqqueue.c test.c
OBJS=test

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -rf $(OBJS) *.o
