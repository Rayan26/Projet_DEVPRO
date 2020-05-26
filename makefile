cc := g++

.DEFAULT_GOAL := test

# Efface tout les fichiers temporaires et les produits finaux.
clean:
	rm -rf build
# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux.
build/:
	mkdir -p build

build/Poste.o: lib/Poste.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Poste.cpp -I ./lib -o build/Poste.o

build/Entreprise.o: lib/Entreprise.cpp | build/
	$(cc) -Wall -pedantic  -Werror -g -c lib/Entreprise.cpp -I ./lib -o build/Entreprise.o

build/Personne.o: lib/Personne.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Personne.cpp -I ./lib -o build/Personne.o

build/Chomeur.o: lib/Chomeur.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Chomeur.cpp -I ./lib -o build/Chomeur.o

build/Employer.o: lib/Employer.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Employer.cpp -I ./lib -o build/Employer.o

build/Parse.o: lib/Parse.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Parse.cpp -I ./lib -o build/Parse.o

build/Service.o: lib/Service.cpp |build/
	$(cc) -Wall -pedantic -Werror -g -c lib/Service.cpp -I ./lib -o build/Service.o

build/menu.o: lib/menu.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/menu.cpp -I ./lib -o build/menu.o

build/ajout.o: lib/ajout.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c lib/ajout.cpp -I ./lib -o build/ajout.o

build/test.o: test/main.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c test/main.cpp -I ./lib -o build/test.o

build/main.o: run/main.cpp | build/
	$(cc) -Wall -pedantic -Werror -g -c run/main.cpp -I ./lib -o build/main.o

build/test: build/test.o build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o build/Parse.o build/Service.o build/menu.o build/ajout.o | build/
	$(cc) -o build/test build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o build/Parse.o build/Service.o build/menu.o build/ajout.o build/test.o 

build/main: build/main.o build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o build/Parse.o build/Service.o build/menu.o build/ajout.o | build/
	$(cc) -o build/main build/Poste.o build/Entreprise.o build/Personne.o build/Chomeur.o build/Employer.o build/Parse.o build/Service.o build/menu.o build/ajout.o build/main.o 


# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli
test: build/test

run: build/main

all: test

check: test
	build/test
