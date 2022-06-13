CC = gcc
CFLAGS = -O1 -g -Wall -Werror -I.

# Control the build verbosity
ifeq ("$(VERBOSE)","0")
    Q :=
    VECHO = @true
else
    Q := @
    VECHO = @printf
endif

.PHONY: main clean
objects := $(patsubst %.c,%.o,$(wildcard *c))
main : $(objects)
	$(VECHO) "  CC\t$@\n"
	$(Q) $(CC) -o main ${CFLAGS} $(objects)

clean : 
	@echo "Clean..."
	-rm *.o main
