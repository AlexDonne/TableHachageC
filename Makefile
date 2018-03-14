CC=clang
CFLAGS=-std=c99 -Wall -Wextra -g -ln
LDFLAGS=
EXEC=annuaire
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

mon_executable: $(OBJ) $(CC) -o $@ $^ $(LDFLAGS)

main.o: hachage.h

%.o: %.c $(CC) -o $@ -c $< $(CFLAGS)

clean: rm -f *.o

mrproper: clean m -f $(EXEC)
