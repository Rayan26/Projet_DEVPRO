cc := gcc

.DEFAULT_GOAL := check

.PHONY: clean check test

# Efface tout les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux.
build:
	mkdir -p build

build/Personne.o: lib/Personne.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Personne.cpp -I ./lib -o build/Personne.o

build/libPersonne.a: build/Personne.o | build/
	ar crs build/libPersonne.a build/Personne.o 

build/test.o: test/main.cpp | build/
	$(cc) -Wall -pedantic -g -c test/main.cpp -I ./lib -o build/test.o

build/test: build/test.o build/libPersonne.a | build/
	$(cc) build/test.o -Lbuild/ -lPersonne -o build/test

# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli
test: build/test

# Lance le programme de test.
check: build/test
	build/test