CC = gcc
CFLAGS =  -g -Wall

test:test.o sqstack.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm  test *.o
