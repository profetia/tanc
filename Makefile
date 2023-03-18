CC = gcc
CFLAGS = -g -std=c89 -Wpedantic -Wall -Wextra -Werror

tanc_objs_files = tanc.o

all: $(tanc_objs_files) test
.PHONY: all

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

test: $(tanc_objs_files)
	@$(MAKE) -C test

clean:
	@-rm -f *.o
	@$(MAKE) -C test clean
