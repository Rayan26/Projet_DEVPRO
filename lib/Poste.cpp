#include "Poste.h"

using namespace std;

Poste::Poste()
{
}

Poste::Poste(int id, std::string Titre, int idEntreprise) : _id(id), _Titre(Titre), _idEntreprise(idEntreprise)
{
}

Poste::Poste(const Poste &poste) : _id(poste.getId()), _Titre(poste.getTitre()), _idEntreprise(poste.getIdEntreprise()), _Competences(poste.get_competences())
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
std::vector<std::string> Poste::get_competences() const
{
	return this->_Competences;
}
void Poste::addCompetence(string const newcompetence)
{
	this->_Competences.push_back(newcompetence);
}

void Poste::printInfo() const
{
	cout << "" << endl;
	cout << "ID du poste : " << _id << endl;
	cout << "Titre du poste : " << _Titre << endl;

	cout << " Compétence requise pour ce poste : " << endl;
	for (size_t i(1); i <= _Competences.size(); ++i)
	{
		cout << "  " << _Competences[i - 1] << endl;
	}

}

void affichage_vecteur_Poste(vector<Poste> post)
{
	for (int i = 0; i < (int)post.size(); i++)
	{
		post[i].printInfo();
	}
}
