#include "Personne.h"


using namespace std;


Personne::Personne() : nom("sans nom"), prenom("sans prenom"), mail("sans mail"),code(0),skill(vector<char> skill(5,"aucune"))
{

}

Personne::Personne(string nom, string prenom, string mail, int code, std::vector<string>& skill) : nom(nom), prenom(prenom), mail(mail), code(code),skill(skill)
{

}

Personne::Personne(const Personne &personne) : nom(personne.getNom), prenom(personne.getPrenom), mail(personne.getMail),code(personne.getCode),skill(personne.getSkill)
{

}

Personne::~Personne()
{

}

string Personne::getNom() const
{
    return this->nom;
}

string Personne::getPrenom() const
{
    return this->prenom;
}

string Personne::getMail() const
{
    return this->mail;
}

int Personne::getCode() const
{
    return this->code
}

string Personne::getSkill() const
{
    return this->skill;
}