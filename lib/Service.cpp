#include "Service.h"

using namespace std;

Entreprise *get_entreprise(int id, vector<Entreprise> entreprises)
{
	if (id > entreprises.size() || id < 0)
		return NULL ;
	for (size_t i = 0; i < entreprises.size(); i++)
	{
		//entreprises[i].printInfo();
		if (id == entreprises[i].getId())
			return &entreprises[i];
	}
	return NULL ;
}

Employer* get_employers(int id, vector<Employer> employers)
{
	if (id > employers.size() || id < 0)
		return NULL ;
	for (size_t i = 0; i < employers.size(); i++)
	{
		if (id == employers[i].getIdPersonne())
		{
			return &employers[i];
		}
	}
	return NULL;
}
Chomeur* get_chomeur(int id, vector<Chomeur> chomeurs)
{
	if (id > chomeurs.size() || id < 0)
		return NULL ;
	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		if (id == chomeurs[i].getIdPersonne())
		{
			return &chomeurs[i];
		}
	}
	return NULL;
}

Poste* get_poste(int id, vector<Poste> postes)
{
	if (id > postes.size() || id < 0)
		return NULL ;
	for (size_t i = 0; i < postes.size(); i++)
	{
		if (id == postes[i].getId())
		{
			return &postes[i];
		}
	}
	return NULL;
}

vector<Employer> get_employers_de_entreprise(int id_entr, vector<Employer> employers)
{
	vector<Employer> employers_entreprise;

	for (size_t i = 0; i < employers.size(); i++)
	{
		if (employers[i].getIdEntreprise() == id_entr)
		{
			employers_entreprise.push_back(employers[i]);
		}
	}
	return employers_entreprise;
}

vector<Poste> recherche_par_comp(string competence_recherche, string CP, vector<Poste> postes, vector<Entreprise> entreprises)
{
	vector<Poste> liste_poste_correspondants;

	for (size_t i = 0; i < postes.size(); i++)
	{
		for (size_t j = 0; j < postes[i].get_competences().size(); j++)
		{
			if (competence_recherche.compare(postes[i].get_competences()[j]) == 0)
			{
				Entreprise cible = *get_entreprise(postes[i].getIdEntreprise(),entreprises);
				if (cible.getCode() == CP)
					liste_poste_correspondants.push_back(postes[i]);
			}
		}
	}
	return liste_poste_correspondants;
}
