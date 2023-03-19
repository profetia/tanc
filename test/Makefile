CC = gcc
CFLAGS = -g -std=c89 -Wpedantic -Wall -Wextra -Werror

src_files := $(shell find . -name '*.c')
src_out_files := $(src_files:.c=.out)

all: $(src_out_files)
.PHONY: all

%.out: %.c
	@$(CC) $(CFLAGS) $< -o $@
	
clean:
	@-rm -f *.out
