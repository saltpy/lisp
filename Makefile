CC=gcc
CFLAGS=-c -Wall

build: clean
	$(CC) lisp.c -o lisp

test: clean
	$(CC) -g test.c -o test
	./test

clean:
	rm -rf *.o
	rm -rf test
	rm -rf lisp
