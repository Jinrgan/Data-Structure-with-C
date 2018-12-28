CC = gcc
CFLAGS =  -g -Wall

test:balltm_test.c balltimer.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm  test *.o
