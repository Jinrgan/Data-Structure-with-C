CC = gcc
CFLAGS = -o0 -g -Wall 

SRC=binsearch.c
OBJS=binsearch

$(OBJS):$(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -rf $(OBJS)
