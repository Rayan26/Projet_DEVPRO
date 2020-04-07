cc := g++

.DEFAULT_GOAL := test

# Efface tout les fichiers temporaires et les produits finaux.
clean:
	rm -rf build
# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux.
build/:
	mkdir -p build

build/Poste.o: lib/Poste.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Poste.cpp -I ./lib -o build/Poste.o

build/Entreprise.o: lib/Entreprise.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Entreprise.cpp -I ./lib -o build/Entreprise.o

build/Personne.o: lib/Personne.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Personne.cpp -I ./lib -o build/Personne.o

build/Chomeur.o: lib/Chomeur.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Chomeur.cpp -I ./lib -o build/Chomeur.o

build/Employer.o: lib/Employer.cpp | build/
	$(cc) -Wall -pedantic -g -c lib/Employer.cpp -I ./lib -o build/Employer.o

build/main.o: test/main.cpp | build/
	$(cc) -Wall -pedantic -g -c test/main.cpp -I ./lib -o build/main.o

build/test: build/main.o build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o | build/
	$(cc) -o build/test build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o build/main.o

# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli
test: build/test
