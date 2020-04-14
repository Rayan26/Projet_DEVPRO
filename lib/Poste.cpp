#include "Poste.h"

using namespace std;

Poste::Poste(int id, std::string Titre, int idEntreprise): _id(id), _Titre(Titre),_idEntreprise(idEntreprise)
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

int Poste::getIdEntreprise() const
{
	return this->_idEntreprise;
}

void Poste::setId(int newId)
{
	this->_id = newId;
}

void Poste::setTitre(string newTitre)
{
	this->_Titre = newTitre;
}

void Poste::setIdEntreprise(int newId)
{
	this->_idEntreprise = newId;
}

void Poste::addCompetence(string const newcompetence)
{
	this->_Competences.push_back(newcompetence);
}

void Poste::printInfo() const
{ 
	cout <<""<< endl;
    cout << "ID du poste : " << _id << endl;
    cout << "Titre du poste : " << _Titre << endl;
    
    
cout << " Compétence requise pour ce poste : "<< endl;
    for(int i(1); i <= _Competences.size(); ++i)
   {   
    cout << "  " << _Competences[i-1] << endl;
   }

   cout << "ID de l'entreprise chez qui le poste est à pourvoir : " << _idEntreprise << endl;
}
