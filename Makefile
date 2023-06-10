all:
		make aplicacao teste

aplicacao: src/matrizes/main.c
		gcc -o build/main src/matrizes/main.c -I/usr/include/ -L/usr/lib/x86_64-linux-gnu/ -lgsl -lgslcblas -lm

teste:	aplicacao
		build/main

doc: 
		doxygen doc/Doxyfile

clean: 
		rm -f main build/main