all:
		make aplicacao teste

aplicacao: src/matrizes/matrizes.c src/matrizes/main.c
		gcc -o build/matrizes.o -c  src/matrizes/matrizes.c -W -Wall -pedantic
		gcc -o build/main.o -c  src/matrizes/main.c -W -Wall -pedantic          
		gcc -o build/matrizes src/matrizes/matrizes.c src/matrizes/main.c

teste:	aplicacao
		./matrizes

doc: 
		doxygen doc/Doxyfile

clean: 
		rm -f matrizes src/matrizes.o src/main.o