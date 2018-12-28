CC = gcc
CFLAGS = -Wall -g -O0

hash_search: hash_search.c hash.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	$(RM) hash_search .*.sw?