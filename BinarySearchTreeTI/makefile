


CC = g++
CFLAGS= -c -Wall
AL_LIBS = -lm

all: postfix

postfix: main.o bst.o 
	$(CC) main.o bst.o -o bst

main.o: main.c bst.h
	$(CC) $(CFLAGS) main.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c

clean:
	rm -rf *o bst

