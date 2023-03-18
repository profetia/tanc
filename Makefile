CC = gcc
CFLAGS = -g -std=c89 -Wpedantic -Wall -Wextra -Werror

tanc_objs_files = tanc.o

all: $(tanc_objs_files) 
.PHONY: all

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@-rm -f *.o

