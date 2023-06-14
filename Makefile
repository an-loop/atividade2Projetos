all:
	make aplicacao teste

aplicacao: 
	mkdir -p build
	gcc -c -I"/usr/include/" matrizes.c -o build/matrizes.o
	mkdir -p build
	gcc main.c build/matrizes.o -L"/usr/lib/x86_64-linux-gnu/" -lgsl -lm -o build/aplicacao

teste:	aplicacao
	./build/aplicacao

doc: 
	mkdir -p doc
	doxygen Doxyfile

clean: 
	rm -rf doc build