#include "Employer.h"


using namespace std;



Employer::Employer(int id, string nom, string prenom, string mail, int code, vector<string> const& skill) : Personne(id,nom, prenom, mail, code, skill)
{

} 

int Employer::getIdEntreprise() const
{
  return this->_idEntreprise;
}

void Employer::setIdEntreprise(int newid)
{
    this->_idEntreprise = newid;
}

void Employer::printEmployeur() const
{
    
    cout << "ID Entreprise : " << _idEntreprise << endl;

}