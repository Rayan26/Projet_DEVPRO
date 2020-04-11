#include "Personne.h"



using namespace std;



Personne::Personne(int id, string nom, string prenom, string mail, int code, vector<string> const& skill) : _nom(nom), _prenom(prenom), _mail(mail), _code(code),_skill(skill)
{

}

Personne::Personne(const Personne &personne) : _id(personne.getIdPersonne()), _nom(personne.getNom()), _prenom(personne.getPrenom()), _mail(personne.getMail()), _code(personne.getCode())
{

}

Personne::~Personne()
{

}

int Personne::getIdPersonne() const
{
    return this->_id;   
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

void Personne::setId(int newid)
{
    this->_id = newid;
}

void Personne::setNom(string newnom)
{
    this->_nom = newnom;
}

void Personne::setPrenom(string newprenom)
{
    this->_prenom = newprenom;
}

void Personne::setMail(string newmail)
{
    this->_mail = newmail;
}

void Personne::setCode(int newcode)
{
    this->_code = newcode;
}

void Personne::addCompetence(string const newcompetence)
{   
    this->_skill.push_back(newcompetence);
}

void Personne::printInfo() const
{   
    cout <<""<< endl;
    cout << "ID : " << _id <<"  "<< _prenom << endl;
    cout << "Monsieur : " << _nom <<"  "<< _prenom << endl;
    cout << "Mail : " << _mail << endl;
    cout << "Code Postal : " << _code << endl;

    for(int i(1); i <= _skill.size(); ++i)
   {   
    cout << "Compétence " << i << " : " << _skill[i-1] << endl;
   }
    
}


