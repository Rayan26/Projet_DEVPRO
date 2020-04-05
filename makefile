cc := g++

.DEFAULT_GOAL := check

# Efface tout les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux.
build:
	mkdir -p build

build/Personne.o: lib/Personne.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Personne.cpp -I ./lib -o build/Personne.o

build/main.o: test/main.cpp | build/
	$(cc) -Wall -pedantic -g -c test/main.cpp -I ./lib -o build/main.o

build/test: build/main.o build/Personne.o | build/
	$(cc) -o build/test build/main.o build/Personne.o

# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli
test: build/test

# Lance le programme de test.
check: build/test
	build/test