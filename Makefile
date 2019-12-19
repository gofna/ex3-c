CC = gcc
FLAGS = -Wall


all: isort txtfind

isort: isortmain.o isort.o
	$(CC) $(FLAGS) -o isort isortmain.o isort.o
	
txtfind: txtfindmain.o txtfind.o
	$(CC) $(FLAG.oS) -o txtfind txtfindmain.o txtfind.o

txtfindmain.o: txtfindmain.c 
	$(CC) $(FLAG.oS) -c txtfindmain.c
	
isortmain.o: isortmain.c 
	$(CC) $(FLAG.oS) -c isortmain.c 
	
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all 

clean: 
	rm -f *.o  txtfind isort
