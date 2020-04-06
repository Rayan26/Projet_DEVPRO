#include "Chomeur.h"



using namespace std;

Chomeur::Chomeur() (const Personne &personne) _nom(personne.getNom()), _prenom(personne.getPrenom()), _mail(personne.getMail()), _code(personne.getCode())
{
 
}

Employer Chomeur::transition()
{
    Employer employer();
    return employer;
}
