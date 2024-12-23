main: main.o setup.o assembler.o symbol.o
	gcc -o main main.o setup.o assembler.o symbol.o
	@echo "e[32mcompilazioen completata"

main.o: main.c libraries/setup.h libraries/assembler.h
	gcc -c main.c

setup.o: libraries/setup.c libraries/setup.h
	gcc -c libraries/setup.c

assembler.o: libraries/assembler.c libraries/assembler.h
	gcc -c libraries/assembler.c

symbol.o: libraries/symbol.c libraries/symbol.h
	gcc -c libraries/symbol.c

#@start the command without printing output on terminal
# -f to force remove

clean:
	@rm -f *.o *.hack *.txt main
	@echo "\e[32mfile temporanei rimossi"