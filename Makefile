main: main.o setup.o assembler.o symbol.o
	gcc -o main main.o setup.o assembler.o symbol.o

main.o: main.c libraries/setup.h libraries/assembler.h
	gcc -c main.c

setup.o: libraries/setup.c libraries/setup.h
	gcc -c libraries/setup.c

assembler.o: libraries/assembler.c libraries/assembler.h
	gcc -c libraries/assembler.c

symbol.o: libraries/symbol.c libraries/symbol.h
	gcc -c libraries/symbol.c

clean:
	rm *.o *.hack *.txt main