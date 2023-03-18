CC = gcc
CFLAGS = -g -std=c89 -Wpedantic -Wall -Wextra -Werror

tanc_objs_files = ../tanc.o
src_files := $(shell find . -name '*.c')
src_out_files := $(src_files:.c=.out)

all: $(src_out_files)
.PHONY: all

%.out: %.c $(tanc_objs_files)
	@$(CC) $(CFLAGS) $< $(tanc_objs_files) -o $@
	
clean:
	@-rm -f *.out
