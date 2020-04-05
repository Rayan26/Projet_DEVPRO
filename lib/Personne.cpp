#include "Personne.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;



Personne::Personne(string nom, string prenom, string mail, int code,string* skill) : _nom(nom), _prenom(prenom), _mail(mail), _code(code),_skill(skill)
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

string* Personne::getSkill() const
{   
    
    return _skill;
}

void Personne::addCompetence(string const newcompetence)
{   
    return;
}

void Personne::printInfo() const
{   
    cout <<""<< endl;
    cout << "Monsieur : " << _nom <<"  "<< _prenom << endl;
    cout << "Mail : " << _mail << endl;
    cout << "Code Postal : " << _code << endl;

    for(int i(0); i <= MAX_SKILL; ++i)
   {   
    
     cout << "Compétence : " << _skill[i] << endl;
   }
    
}
