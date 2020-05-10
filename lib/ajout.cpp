#include "ajout.h"

using namespace std;

void addEmployer(const Employer &empl, std::vector<Employer> &employers)
{
	for (int i = 0; i < (int)employers.size(); i++)
	{
		if (empl.getIdPersonne() == employers[i].getIdPersonne())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	addEmployerCSV(empl, employers);

	employers.push_back(empl);
}

void addEntreprise(const Entreprise &entre, std::vector<Entreprise> &entreprises)
{
	for (int i = 0; i < (int)entreprises.size(); i++)
	{
		if (entre.getId() == entreprises[i].getId())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	addEntrepriseCSV(entre, entreprises);

	entreprises.push_back(entre);
}
void addChomeur(const Chomeur &chom, std::vector<Chomeur> &chomeurs)
{
	for (int i = 0; i < (int)chomeurs.size(); i++)
	{
		if (chom.getIdPersonne() == chomeurs[i].getIdPersonne())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	addChomeurCSV(chom, chomeurs);

	chomeurs.push_back(chom);
}

void addPoste(const Poste &post, std::vector<Poste> &postes)
{
	for (int i = 0; i < (int)postes.size(); i++)
	{
		if (post.getId() == postes[i].getId())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	addPosteCSV(post, postes);

	postes.push_back(post);
}

void delEmployer(vector<Employer> &employers,vector<Entreprise> &entreprises, int id)
{
	if (id > 0)
	{
		int x = 0;
		for (size_t i = 0; i < employers.size(); i++)
		{
			if (employers[i].getIdPersonne() == id)
			{
				employers.erase(employers.begin() + i);
				x = 1;
			}
		}
		if (x == 0)
		{
			cout << "Cet ID ne correspond à aucun employé" ;
			exit(0);
		}

		for (size_t i = 0; i < employers.size(); i++)
		{
			for (size_t j = 0; j < (employers[i].get_collegues()).size(); j++)
			{
				if (employers[i].get_collegues()[j] == id)
				{
					employers[i].erase_collegue(id);
				}
			}

			for (size_t j = 0; j < (employers[i].get_Anciens_collegues()).size(); j++)
			{
				if (employers[i].get_Anciens_collegues()[j] == id)
				{
					employers[i].erase_ancien_collegue(id);
				}
			}

		}
		for (size_t i = 0; i < entreprises.size(); i++)
		{
			for (size_t j = 0; j < (get_employers_de_entreprise(entreprises[i].getId(),employers)).size(); j++)
			{
				if ((get_employers_de_entreprise(entreprises[i].getId(),employers))[j].getIdPersonne() == id)
				{
					entreprises[i].deleteEmploye(id);
				}
			}
			
		}
		
	}
}

void delEntreprise(vector<Entreprise> &entreprises, int id);
void delChomeur(vector<Chomeur> &chomeurs, int id);
void delPoste(vector<Poste> &postes, int id);