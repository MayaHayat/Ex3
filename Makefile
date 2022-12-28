CC = gcc
AR = ar -rcs
FLAGS = -Wall

#Creating all
all: isort txtfind

#Creating out o files:
isort: isort.o
	$(CC) $(FLAGS) -o isort isort.c

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c


clean: 
	rm -f *.o txtfind isort 

.PHONY: clean all