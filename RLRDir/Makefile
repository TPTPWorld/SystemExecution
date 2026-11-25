CC = gcc
CFLAGS = -Wall -Wextra --pedantic
CFLAGS += $(shell pkg-config --cflags libsystemd)
CFLAGS += -Wno-unused-parameter
LFLAGS = -lm
LFLAGS += $(shell pkg-config --libs libsystemd)

all: RLR Fibonacci MPFibonacci

RLR: RLR.c
	$(CC) $(CFLAGS) -o $@ $@.c $(LFLAGS)

Fibonacci: Fibonacci.c
	$(CC) $(CFLAGS) -o $@ $@.c $(LFLAGS)

MPFibonacci: MPFibonacci.c
	$(CC) $(CFLAGS) -o $@ $@.c $(LFLAGS)

clean:
	rm -f *.o RLR Fibonacci MPFibonacci
