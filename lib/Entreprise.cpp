#include "Entreprise.h"

using namespace std;

Entreprise::Entreprise()
{
}

Entreprise::Entreprise(int ID, string nom, string code, string mail) : _id(ID), _nom(nom), _mail(mail), _code(code)
{
}

Entreprise::Entreprise(const Entreprise &entreprise) : _id(entreprise.getId()), _nom(entreprise.getNom()), _mail(entreprise.getMail()), _code(entreprise.getCode()), _idEmployer(entreprise.get_employers_entreprise()), _idJobs(entreprise.getJobs())
{
}

Entreprise::~Entreprise()
{
}

int Entreprise::getId() const
{
	return this->_id;
}

string Entreprise::getNom() const
{
	return this->_nom;
}

string Entreprise::getMail() const
{
	return this->_mail;
}

string Entreprise::getCode() const
{
	return this->_code;
}

vector<int> Entreprise::getJobs() const
{
	vector<int> jobs;

	for (size_t i = 0; i < _idJobs.size(); i++)
	{
		jobs.push_back(_idJobs[i]);
	}
	return jobs;
}

void Entreprise::setId(int newid)
{
	this->_id = newid;
}

void Entreprise::setNom(std::string newnom)
{
	this->_nom = newnom;
}

void Entreprise::setMail(std::string newmail)
{
	this->_mail = newmail;
}

void Entreprise::setCode(std::string newcode)
{
	this->_code = newcode;
}

void Entreprise::printInfo() const
{

	cout << "" << endl;
	cout << "Entreprise : " << _nom << endl;
	cout << "Mail : " << _mail << endl;
	cout << "Code Postal : " << _code << endl;

	cout << "Liste des Employés de l'entreprise :" << endl;
	for (size_t i(1); i <= _idEmployer.size(); ++i)
	{
		cout << "ID de l'employé n°" << i << " : " << _idEmployer[i - 1] << endl;
	}

	cout << "Liste des Postes à Pourvoir par l'entreprise : " << endl;
	for (size_t i(1); i <= _idJobs.size(); ++i)
	{
		cout << "ID du Poste : " << _idJobs[i - 1] << endl;
	}
}

void affichage_vecteur_entreprise(vector<Entreprise> entre)
{
	for (int i = 0; i < (int)entre.size(); i++)
	{
		entre[i].printInfo();
	}
}

void Entreprise::addJob(int id)
{
	_idJobs.push_back(id);
}

void Entreprise::deleteJob(int id)
{
	for (size_t i = 0; i < _idJobs.size(); i++)
	{
		if (_idJobs[i] == id)
		{
			_idJobs.erase(_idJobs.begin() + i);
		}
	}
}

void Entreprise::addEmploye(int Id_employe)
{
	this->_idEmployer.push_back(Id_employe);
}

void Entreprise::deleteEmploye(int Id_employe)
{
	for (size_t i = 0; i < _idEmployer.size(); i++)
	{
		if (_idEmployer[i] == Id_employe)
		{
			_idEmployer.erase(_idEmployer.begin() + i);
		}
	}
}

vector<int> Entreprise::get_employers_entreprise() const
{
	vector<int> empl;
	for (size_t i = 0; i < _idEmployer.size(); i++)
	{
		empl.push_back(_idEmployer[i]);
	}
	return empl;
}
