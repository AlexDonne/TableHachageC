CC=clang
CFLAGS=-Wall -Wextra -std=c99 -g
LDFLAGS=-lm

all: hachage

.PHONY: clean
clean:
		rm -rf hachage *.o *~
