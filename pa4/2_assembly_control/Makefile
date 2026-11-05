OUTPUT=3_branch
CC=gcc
CFLAGS=-O3 -Wall -Werror -std=c99
ASM = 3_branch.s

%.s: %.c
	$(CC) $(CFLAGS) -S $^ -o $@

$(OUTPUT): $(OUTPUT).s
	$(CC) $(CFLAGS) $^ -o $@

all: $(OUTPUT)

clean:
	rm -f *.s *.o $(OUTPUT)
