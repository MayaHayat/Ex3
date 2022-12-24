CC = gcc
AR = ar -rcs
FLAGS = -Wall

#Creating out o files:
isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

#Creating all
all: isort txtfind

clean: 
	rm txtfind isort .o*