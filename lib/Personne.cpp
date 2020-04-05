#include "Personne.h"


using namespace std;



Personne::Personne(string nom, string prenom, string mail, int code, vector<string>& skill) : _nom(nom), _prenom(prenom), _mail(mail), _code(code)
{

}

Personne::Personne(const Personne &personne) : _nom(personne.getNom()), _prenom(personne.getPrenom()), _mail(personne.getMail()), _code(personne.getCode())
{

}

Personne::~Personne()
{

}

string Personne::getNom() const
{
    return this->_nom;
}

string Personne::getPrenom() const
{
    return this->_prenom;
}

string Personne::getMail() const
{
    return this->_mail;
}

int Personne::getCode() const
{
    return this->_code;
}

vector<string> Personne::getSkill() const
{
    return this->_skill;
}

void Personne::addCompetence(string const newcompetence)
{   
    this->_skill.push_back(newcompetence);
}

