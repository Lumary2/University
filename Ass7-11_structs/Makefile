CC=gcc
CFLAGS=-I.
ifiles: I_FileStructure.o main.o
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.c I_FileStructure.h
	$(CC) $(CFLAGS) -c main.c
I_FileStructure.o: I_FileStructure.c I_FileStructure.h
	$(CC) $(CFLAGS) -c I_FileStructure.c