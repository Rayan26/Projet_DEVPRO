#include "Personne.h"



using namespace std;



Personne::Personne(int id, string nom, string prenom, string mail, string code, vector<string> const& skill) :_id(id), _nom(nom), _prenom(prenom), _mail(mail), _code(code),_skill(skill)
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

string Personne::getCode() const
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

void Personne::setCode(string newcode)
{
    this->_code = newcode;
}

void Personne::addCompetence(string const newcompetence)
{   
    this->_skill.push_back(newcompetence);
}

void Personne::addCollegue(int const newcollegue)
{
    this->_IdCollegue.push_back(newcollegue);
}

void Personne::printInfo() const
{   
    cout <<""<< endl;
    cout << "ID de la personne : " << _id << endl;
    cout << "Monsieur : " << _nom <<"  "<< _prenom << endl;
    cout << "Mail : " << _mail << endl;
    cout << "Code Postal : " << _code << endl;

    for(size_t i(1); i <= _skill.size(); ++i)
   {   
    cout << "Compétence " << i << " : " << _skill[i-1] << endl;
   }

   for(size_t i(1); i <= _IdCollegue.size(); ++i)
   {   
    cout << "ID du collègue n°" << i << " : " << _IdCollegue[i-1] << endl;
   }
    
}


