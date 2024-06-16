include platform.mk

CC=gcc
CFLAGS=-Wall -g -Iinclude
TARGET=test

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

.PHONY: all clean



all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<



clean:
	rm -f $(OBJ) $(TARGET)
