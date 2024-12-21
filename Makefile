main: main.o setup.o assembler.o
	gcc -o main main.o setup.o assembler.o

main.o: main.c setup.h assembler.h
	gcc -c main.c

setup.o: setup.c setup.h
	gcc -c setup.c

assembler.o: assembler.c assembler.h
	gcc -c assembler.c

clean:
	rm *.o *.hack main