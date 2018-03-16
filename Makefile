CC=clang
CFLAGS=-Wall -Wextra -std=c99 -g
LDFLAGS=-lm


all: prog


prog: hachage.o annuaire.o
	$(CC) hachage.o annuaire.o -o prog

hachage.o: hachage.c hachage.h
	$(CC) $(CFLAGS) -c hachage.c -o hachage.o

annuaire.o: annuaire.c hachage.h
	$(CC) $(CFLAGS) -c annuaire.c -o annuaire.o

.PHONY : clean

clean:
	rm -f *.o
