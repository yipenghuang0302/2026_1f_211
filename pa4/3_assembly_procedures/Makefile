OUTPUT=3_recursion
CC=gcc
CFLAGS=-O3 -Wall -Werror -std=c99
ASM = 3_recusion.s

%.s: %.c
	$(CC) $(CFLAGS) -g -S -fno-inline -fno-if-conversion $^ -o $@

$(OUTPUT): $(OUTPUT).s
	$(CC) $(CFLAGS) $^ -o $@

all: $(OUTPUT)

clean:
	rm -f *.s *.o $(OUTPUT)
