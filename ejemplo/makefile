CC = gcc
INCLUDES = -I
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -L../src

ejemplo: main

main: main.o liblDictionary.a # the lib
	gcc -lm -o ejemplo main.o -L../src -lDictionary

main.o: main.c
	gcc -O -c main.c

Dictionary.o: Dictionary.c Dictionary.h
	gcc -O -c Dictionary.c

Stack.o: Stack.c Stack.h
	gcc -O -c Stack.c

Text.o: Text.c Text.h
	gcc -O -c Text.c

liblDictionary.a: Dictionary.o Stack.o Text.o
	ar rcs liblDictionary.a Dictionary.o Stack.o Text.o

libs: liblDictionary.a

clean:
	rm -f main  *.o *.a *.gch