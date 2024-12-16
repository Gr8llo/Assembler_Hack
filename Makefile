
#main: main.o somma.o
#	gcc -o main main.o somma.o
#main.o: main.c somma.h
#	gcc -c main.c
##somma.o: somma.c somma.h
##	gcc -c somma.c
#clean:
#	rm *.o main

main: main.o setup.o
	gcc -o main main.o

main.o: main.c setup.h
	gcc -c main.c

setup.o: setup.c setup.h
	gcc -c setup.c

clean:
	rm *.o main