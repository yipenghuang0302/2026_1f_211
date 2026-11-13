OUTPUT=sumArray
CFLAGS=-O3 -Wall -Werror -std=c99
# -Og
# -floop-interchange
# -floop-nest-optimize
LFLAGS=-lm

%: %.c %.h
	gcc $(CFLAGS) -o $@ $< $(LFLAGS)

%: %.c
	gcc $(CFLAGS) -o $@ $< $(LFLAGS)

all: $(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)
