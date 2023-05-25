all:
		aplicacao teste doc

aplicacao:
		gcc -o teste.o -c teste.c -W -Wall -pedantic
		gcc -o main.o -c main.c -W -Wall -pedantic

matrizes.o: 
		gcc ./src/matrizes.c -c -o ./obj/matrizes.o

teste:	teste.o matrizes.o
		gcc ./obj/main.o -o test

doc: 
		doxygen Doxyfile


clean: 
		rm -rf main.o
		rm -rf matrizes.o