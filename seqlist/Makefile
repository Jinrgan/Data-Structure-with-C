CC = gcc						#使用C语言编译器		
CFLAGS = -O0 -g -Wall			#编译器编译时，不进行优化；使用gdb调试；显示所有警告

test: homework2.c seqlist.c
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:clean
clean:
	rm -rf test
