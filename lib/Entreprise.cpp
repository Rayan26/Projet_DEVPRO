#include "Entreprise.h"

using namespace std;

Entreprise::Entreprise(std::string nom, int code, std::string mail) : _nom(nom), _code(code) ,_mail(mail)
{
}

Entreprise::Entreprise(Entreprise const &entreprise)
{
}

string Entreprise::getNom() const
{
	return this->_nom;
}

string Entreprise::getMail() const
{
	return this->_mail;
}

int Entreprise::getCode() const
{
	return this->_code;
}

vector<Poste> getJobs()
{

}

void Entreprise::addJob(std::string const newjob)
{
}

void Entreprise::deleteJob(Poste poste)
{
}

void Entreprise::printEntreprise() const
{
}
