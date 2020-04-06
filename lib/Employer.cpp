#include "Employer.h"


using namespace std;

Employer::Employer(const Personne &personne,Entreprise entreprise) _nom(personne.getNom()), _prenom(personne.getPrenom()), _mail(personne.getMail()), _code(personne.getCode()), _enterprise(entreprise)
{
 
}

Chomeur Employer::transition()
{
    Chomeur chomeur();
    //TODO
    return chomeur;
}
