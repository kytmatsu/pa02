# An Extremely basic Makefile that I made based off of the professors Makefile
# kytmatsu
# Kyle Matsumoto
CC = gcc
CFLAGS = -g -std=c99


graph02:	graph02.o intList.o
		${CC} -o graph02 ${CFLAGS} graph02.o intList.o

graph02.o:	graph02.c intList.h
		${CC} -c ${CFLAGS} graph02.c

intList.o:	intList.c intList.h
		${CC} -c ${CFLAGS} intList.c
