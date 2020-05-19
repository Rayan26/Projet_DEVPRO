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

void delEmployer(vector<Employer> &employers, vector<Entreprise> &entreprises, int id)
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
			cout << "Cet ID ne correspond à aucun employé";
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
			for (size_t j = 0; j < (entreprises[i].get_employers_entreprise()).size(); j++)
			{
				if ((entreprises[i].get_employers_entreprise())[j] == id)
				{
					entreprises[i].deleteEmploye(id);
				}
			}
		}
		MajCSVEmployer(employers);
	}
}

void delEntreprise(vector<Entreprise> &entreprises, vector<Employer> &employers, int id)
{
	if (id > 0)
	{
		vector<Employer> empl = get_employers_de_entreprise(id, employers);

		if (empl.size() == 0)
		{

			int x = 0;
			for (size_t i = 0; i < entreprises.size(); i++)
			{
				if (entreprises[i].getId() == id)
				{
					entreprises.erase(entreprises.begin() + i);
					x = 1;
				}
			}
			if (x == 0)
			{
				cout << "Cet ID ne correspond à aucune entreprise";
				exit(0);
			}
			MajCSVEntreprise(entreprises);
		}
		else
		{
			cout << "L'entreprise possède encore des employers, impossible de la supprimer \n";
		}
	}
}

void delChomeur(vector<Chomeur> &chomeurs, int id)
{
	if (id > 0)
	{
		int x = 0;
		for (size_t i = 0; i < chomeurs.size(); i++)
		{
			if (chomeurs[i].getIdPersonne() == id)
			{
				chomeurs.erase(chomeurs.begin() + i);
				x = 1;
			}
		}
		if (x == 0)
		{
			cout << "Cet ID ne correspond à aucun chomeur";
			exit(0);
		}

		for (size_t i = 0; i < chomeurs.size(); i++)
		{
			for (size_t j = 0; j < (chomeurs[i].get_Anciens_collegues()).size(); j++)
			{
				if (chomeurs[i].get_Anciens_collegues()[j] == id)
				{
					chomeurs[i].erase_ancien_collegue(id);
				}
			}
		}
		MajCSVChomeur(chomeurs);
	}
}

void delPoste(vector<Poste> &postes, vector<Entreprise> &entreprises, int id)
{
	if (id > 0)
	{
		int x = 0;

		Entreprise *entre = get_entreprise((get_poste(id, postes))->getIdEntreprise(), entreprises);
		entre->deleteJob(id);

		for (size_t i = 0; i < postes.size(); i++)
		{
			if (postes[i].getId() == id)
			{
				postes.erase(postes.begin() + i);
				x = 1;
			}
		}

		if (x == 0)
		{
			cout << "Cet ID ne correspond à aucun poste";
			exit(0);
		}

		entre->deleteJob(id);

		MajCSVPoste(postes);
	}
}

void transitionEmployer_Vers_Chomeur(int idEmployer, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise>& entreprises)
{
	Employer *empl = get_employers(idEmployer, employers);
	
	delEmployer(employers,entreprises,idEmployer);
	

	int id_dispo = rechercheIdDispo_Chomeur(chomeurs);
	Chomeur *chom = new Chomeur(id_dispo,empl->getNom(),empl->getPrenom(),empl->getMail(),empl->getCode(),empl->getSkill());
	
	// for (size_t i = 0; i < empl.get_Anciens_collegues().size(); i++)
	// {
	// 	chom.addAncienCollegue(empl.get_Anciens_collegues()[i]);
	// }
	// for (size_t i = 0; i < empl.get_collegues().size(); i++)
	// {
	// 	chom.addAncienCollegue(empl.get_collegues()[i]);
	// }
	

	addChomeur(chom,chomeurs);

}

void transitionChomeur_Vers_Employer(int idChomeur, int idEntreprises, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises);

int rechercheIdDispo_Chomeur(vector<Chomeur> &chomeurs)
{
	int id = 1;
	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		if (chomeurs[i].getIdPersonne() >= id)
		{
			id = chomeurs[i].getIdPersonne();
		}
	}

	return id + 1;
}

int rechercheIdDispo_Employer(vector<Employer> &employers)
{
	int id = 1;
	for (size_t i = 0; i < employers.size(); i++)
	{
		if (employers[i].getIdPersonne() >= id)
		{
			id = employers[i].getIdPersonne();
		}
	}

	return id + 1;
}

int rechercheIdDispo_Entreprise(vector<Entreprise> &entreprises)
{
	int id = 1;
	for (size_t i = 0; i < entreprises.size(); i++)
	{
		if (entreprises[i].getId() >= id)
		{
			id = entreprises[i].getId();
		}
	}

	return id + 1;
}

int rechercheIdDispo_Poste(vector<Poste> &postes)
{
	int id = 1;
	for (size_t i = 0; i < postes.size(); i++)
	{
		if (postes[i].getId() >= id)
		{
			id = postes[i].getId();
		}
	}

	return id + 1;
}
