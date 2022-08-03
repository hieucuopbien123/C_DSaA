CC=gcc
TARGET=main
OBJ=main.o	hello.o
DEPS=hello.h

$(TARGET): $(OBJ)
	$(CC)	-o	$@	$(OBJ)
%.o: %.c	(DEPS)
	$(CC)	-c	$<
clean:
	rm	$(TARGET)	$(OBJ)