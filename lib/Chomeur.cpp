#include "Chomeur.h"

using namespace std;

Chomeur::Chomeur(int id, string nom, string prenom, string mail, string code, vector<string> const &skill) : Personne(id, nom, prenom, mail, code, skill)
{
}

Chomeur::~Chomeur()
{
}

void affichage_vecteur_chomeur(vector<Chomeur> chom)
{
    for (int i = 0; i < (int)chom.size(); i++)
    {
        chom[i].printInfo();
    }
}
