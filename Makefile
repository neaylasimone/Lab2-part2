# Signals lab Makefile
CC = gcc
CFLAGS = -Wall -g

all: signal1 signal2 timer

signal1: signal1.c
	$(CC) $(CFLAGS) signal1.c -o signal1

signal2: signal2.c
	$(CC) $(CFLAGS) signal2.c -o signal2

timer: timer.c
	$(CC) $(CFLAGS) timer.c -o timer

clean:
	rm -f signal1 signal2 timer

.PHONY: all clean
