LIBS = -I../include
CFLAGS = -g -std=c89 -Wpedantic -Wall -Wextra -Werror -rdynamic

clean:
	rm -f *.out

%.out: %.c
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

.PHONY: clean

all: $(patsubst %.c, %.out, $(wildcard *.c))
