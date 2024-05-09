BUF?=1000
FILE?=*

all:
	cc -g -D BUFFER_SIZE=$(BUF) *.c *.h && valgrind ./a.out files/$(FILE)

