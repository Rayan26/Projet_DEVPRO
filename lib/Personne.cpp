#include "Personne.h"



using namespace std;



Personne::Personne(string nom, string prenom, string mail, int code, vector<string> const& skill) : _nom(nom), _prenom(prenom), _mail(mail), _code(code),_skill(skill)
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

void Personne::printInfo() const
{   
    cout <<""<< endl;
    cout << "Monsieur : " << _nom <<"  "<< _prenom << endl;
    cout << "Mail : " << _mail << endl;
    cout << "Code Postal : " << _code << endl;

    for(int i(1); i <= _skill.size(); ++i)
   {   
    cout << "Compétence " << i << " : " << _skill[i-1] << endl;
   }
    
}

void Personne::setCode(int newcode)
{
    this->_code = newcode;
}
