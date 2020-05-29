#include "Service.h"
#include "Employer.h"
#include <cassert>

using namespace std;

Entreprise *get_entreprise(int id, vector<Entreprise> &entreprises)
{
	if (id < 0)
		return NULL;
	for (size_t i = 0; i < entreprises.size(); i++)
	{
		//entreprises[i].printInfo();
		if (id == entreprises[i].getId())
			return &entreprises[i];
	}
	return NULL;
}

Employer *get_employers(int id, vector<Employer> &employers)
{
	if (id < 0)
		return NULL;
	for (size_t i = 0; i < employers.size(); i++)
	{
		if (id == employers[i].getIdPersonne())
		{
			return &employers[i];
		}
	}
	return NULL;
}
Chomeur *get_chomeur(int id, vector<Chomeur> &chomeurs)
{
	if (id < 0)
		return NULL;
	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		if (id == chomeurs[i].getIdPersonne())
		{
			return &chomeurs[i];
		}
	}
	return NULL;
}

Poste *get_poste(int id, vector<Poste> &postes)
{
	if (id < 0)
		return NULL;
	for (size_t i = 0; i < postes.size(); i++)
	{
		if (id == postes[i].getId())
		{
			return &postes[i];
		}
	}
	return NULL;
}

vector<Employer> get_employers_de_entreprise(int id_entr, vector<Employer> &employers)
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

vector<Poste> recherche_par_comp(string competence_recherche, vector<Poste> postes)
{
	vector<Poste> liste_poste_correspondants;

	for (size_t i = 0; i < postes.size(); i++)
	{
		for (size_t j = 0; j < postes[i].get_competences().size(); j++)
		{
			if (competence_recherche.compare(postes[i].get_competences()[j]) == 0)
			{
				liste_poste_correspondants.push_back(postes[i]);
			}
		}
	}
	return liste_poste_correspondants;
}

vector<Poste> recherche_par_comp_CP(string competence_recherche, string CP, vector<Poste> postes, vector<Entreprise> entreprises)
{
	vector<Poste> liste_poste_correspondants;

	for (size_t i = 0; i < postes.size(); i++)
	{
		for (size_t j = 0; j < postes[i].get_competences().size(); j++)
		{
			if (competence_recherche.compare(postes[i].get_competences()[j]) == 0)
			{
				Entreprise *cible = get_entreprise(postes[i].getIdEntreprise(), entreprises);
				if (cible->getCode() == CP)
					liste_poste_correspondants.push_back(postes[i]);
			}
		}
	}
	return liste_poste_correspondants;
}

vector<Chomeur> recherche_chomeur_par_comp(string competence_recherche, vector<Chomeur> &chomeurs)
{
	vector<Chomeur> liste_chomeur_correspondant;

	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		for (size_t j = 0; j < chomeurs[i].getSkill().size(); j++)
		{
			if (competence_recherche.compare(chomeurs[i].getSkill()[j]) == 0)
			{
				liste_chomeur_correspondant.push_back(chomeurs[i]);
			}
		}
	}
	return liste_chomeur_correspondant;
}

vector<Chomeur> recherche_chomeur_par_comp_CP(string competence_recherche, string CP, vector<Chomeur> &chomeurs)
{
	vector<Chomeur> liste_chomeur_correspondant;

	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		for (size_t j = 0; j < chomeurs[i].getSkill().size(); j++)
		{
			if (competence_recherche.compare(chomeurs[i].getSkill()[j]) == 0)
			{
				if (chomeurs[i].getCode() == CP)
				{
					liste_chomeur_correspondant.push_back(chomeurs[i]);
				}
			}
		}
	}
	return liste_chomeur_correspondant;
}

void ajout_employer_entreprise(Employer &empl, int id_entreprise, vector<Entreprise> &entreprises)
{
	empl.setIdEntreprise(id_entreprise);
	Entreprise *entre = get_entreprise(id_entreprise, entreprises);
	assert(entre);
	entre->addEmploye(empl.getIdPersonne());
}

void affichage_vecteur_Poste(vector<Poste> post, vector<Entreprise> entres)
{
	for (int i = 0; i < (int)post.size(); i++)
	{
		post[i].printInfo();
		Entreprise *entre = get_entreprise(post[i].getIdEntreprise(), entres);
		cout << "Entreprise : " << entre->getNom() << "\n \n";
	}
}

void recherche_ancien_collegue_entreprise(vector<int> ancien_collegues, vector<Employer> Employers, vector<Entreprise> Entreprises, string nom_entreprise)
{
	int id_entreprise;
	bool verif = false;
	for (size_t i = 0; i < Entreprises.size(); i++)
	{
		if (Entreprises[i].getNom() == nom_entreprise)
		{
			verif = true;
			id_entreprise = Entreprises[i].getId();
		}
	}

	if (verif == false)
	{
		cout << "L'entreprise en question n'existe pas \n";
	}

	else
	{
		for (size_t i = 0; i < ancien_collegues.size(); i++)
		{
			Employer *empl = get_employers(ancien_collegues[i], Employers);
			if (empl != NULL)
			{
				if (empl->getIdEntreprise() == id_entreprise)
				{
					empl->printInfo();
				}
			}
		}
	}
}

void recherche_ancien_collegue_competence(vector<int> ancien_collegues, vector<Employer> Employers, vector<Chomeur> Chomeurs, string competence)
{
	vector<string> competences;

	for (size_t i = 0; i < ancien_collegues.size(); i++)
	{
		Employer *empl = get_employers(ancien_collegues[i], Employers);
		if (empl != NULL)
		{
			competences = empl->getSkill();
			for (size_t i = 0; i < competences.size(); i++)
			{
				if (competences[i] == competence)
				{
					empl->printInfo();
				}
			}
		}

		Chomeur *chom = get_chomeur(ancien_collegues[i], Chomeurs);
		if (chom != NULL)
		{
			competences = chom->getSkill();
			for (size_t i = 0; i < competences.size(); i++)
			{
				if (competences[i] == competence)
				{
					chom->printInfo();
				}
			}
		}
	}
}