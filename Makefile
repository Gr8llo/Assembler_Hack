main: main.o setup.o
	gcc -o main main.o setup.o

main.o: main.c setup.h
	gcc -c main.c

setup.o: setup.c setup.h
	gcc -c setup.c

clean:
	rm *.o main