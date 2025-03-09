CC=gcc
CFLAGS=-Wall
LDLIBS=-lm

all: main

main: main.o palindrom.o
        $(CC) $(CFLAGS) -o main main.o palindrom.o $(LDLIBS)

main.o: main.c funs.h
        $(CC) $(CFLAGS) -c main.c

palindrom.o: palindrom.c
        $(CC) $(CFLAGS) -c palindrom.c