CC=g++
CFLAGS=-I.

editor: editor.o main.o SString.o TextList.o LineNode.o 
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.cpp editor.h SString.h TextList.h LineNode.h
	$(CC) $(CFLAGS) -c main.cpp
editor.o: editor.cpp editor.h
	$(CC) $(CFLAGS) -c editor.cpp
SString.o: SString.cpp SString.h
	$(CC) $(CFLAGS) -c SString.cpp
TextList.o: TextList.cpp TextList.h
	$(CC) $(CFLAGS) -c TextList.cpp
LineNode.o: LineNode.cpp LineNode.h
	$(CC) $(CFLAGS) -c LineNode.cpp