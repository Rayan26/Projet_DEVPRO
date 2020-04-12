#include "Poste.h"

using namespace std;

Poste::Poste(int id, std::string Titre, std::string entreprise, std::string mail_entreprise, int code): _id(id), _Titre(Titre),_Entreprise(entreprise), _Mail_Entreprise(mail_entreprise), _code(code)
{
}

Poste::~Poste()
{

}
int Poste::getId() const
{
	return this->_id;  
}

string Poste::getTitre() const
{
	return this->_Titre;
}

string Poste::getEntreprise() const
{
	return this->_Entreprise;
}

string Poste::getMail() const
{
	return this->_Mail_Entreprise;
}

int Poste::getCode() const
{
	    return this->_code;
}

void Poste::setId(int newId)
{
	this->_id = newId;
}

void Poste::printPoste() const
{
}
