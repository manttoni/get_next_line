FOO?=1

all:
	cc -g -D BUFFER_SIZE=$(FOO) gnl3/*.c gnl3/*.h && valgrind ./a.out gnl3/files/*
