CC = gcc
CFLAGS = -Wall -Werror -g

all: resolver

resolver: resolver.o
	$(CC) $(CFLAGS) -o resolver resolver.o

resolver.o: resolver.c
	$(CC) $(CFLAGS) -c resolver.c

clean:
	rm -f resolver *.o