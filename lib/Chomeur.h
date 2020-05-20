#ifndef DEF_CHOMEUR
#define DEF_CHOMEUR

#include <iostream>
#include <string>
#include <vector>

#include "Personne.h"

class Chomeur : public Personne
{
public:
    Chomeur(int id, std::string nom, std::string prenom, std::string mail, std::string code, std::vector<std::string> const &skill);
    ~Chomeur();

private:
};

void affichage_vecteur_chomeur(std::vector<Chomeur> chom);

#endif
