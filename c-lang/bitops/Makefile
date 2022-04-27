CC = gcc
CFLAGS = -O1 -g -Wall -Werror -Idudect -I.

.PHONY: main clean
objects := $(patsubst %.c,%.o,$(wildcard *c))
main : $(objects)
	cc -o main ${CFLAGS} $(objects)

clean : 
	@echo "Clean..."
	-rm *.o main
