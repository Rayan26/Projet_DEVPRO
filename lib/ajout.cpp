#include "ajout.h"

using namespace std;

void addEmployer(const Employer &empl, std::vector<Employer> &employers, vector<Chomeur> &chomeurs)
{
	for (int i = 0; i < (int)employers.size(); i++)
	{
		if (empl.getIdPersonne() == employers[i].getIdPersonne())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	for (int i = 0; i < (int)chomeurs.size(); i++)
	{
		if (empl.getIdPersonne() == chomeurs[i].getIdPersonne())
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
void addChomeur(const Chomeur &chom, std::vector<Chomeur> &chomeurs, vector<Employer> &employers)
{
	for (int i = 0; i < (int)chomeurs.size(); i++)
	{
		if (chom.getIdPersonne() == chomeurs[i].getIdPersonne())
		{
			cout << "ID existe déja dans la base de donnée" << endl;
			return;
		}
	}

	for (int i = 0; i < (int)employers.size(); i++)
	{
		if (chom.getIdPersonne() == employers[i].getIdPersonne())
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

void delEmployer(vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises, int id)
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
		MajCSVChomeur(chomeurs);
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

void delChomeur(vector<Chomeur> &chomeurs, vector<Employer> &employers, int id)
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
	}

	MajCSVChomeur(chomeurs);
	MajCSVEmployer(employers);
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

void transitionEmployer_Vers_Chomeur(int idEmployer, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises)
{
	Employer *empl = get_employers(idEmployer, employers);

	Chomeur *chom = new Chomeur(empl->getIdPersonne(), empl->getNom(), empl->getPrenom(), empl->getMail(), empl->getCode(), empl->getSkill());

	for (size_t i = 0; i < empl->get_Anciens_collegues().size(); i++)
	{
		chom->addAncienCollegue(empl->get_Anciens_collegues()[i]);
	}
	for (size_t i = 0; i < empl->get_collegues().size(); i++)
	{
		chom->addAncienCollegue(empl->get_collegues()[i]);
	}

	delEmployer(employers, chomeurs, entreprises, idEmployer);
	addChomeur(*chom, chomeurs, employers);
}

void transitionChomeur_Vers_Employer(int idChomeur, int idEntreprises, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises)
{
	Chomeur *chom = get_chomeur(idChomeur, chomeurs);

	Employer *empl = new Employer(idChomeur, chom->getNom(), chom->getPrenom(), chom->getMail(), chom->getCode(), chom->getSkill());

	for (size_t i = 0; i < chom->get_Anciens_collegues().size(); i++)
	{
		empl->addAncienCollegue(chom->get_Anciens_collegues()[i]);
	}

	vector<Employer> collegues = get_employers_de_entreprise(idEntreprises, employers);
	for (size_t i = 0; i < collegues.size(); i++)
	{
		empl->addCollegue(collegues[i].getIdPersonne());
	}

	Entreprise *entre = get_entreprise(idEntreprises, entreprises);
	entre->addEmploye(idChomeur);
	empl->setIdEntreprise(idEntreprises);

	delChomeur(chomeurs, employers, idChomeur);
	addEmployer(*empl, employers, chomeurs);
}

int rechercheIdDispo_Personne(vector<Employer> &employers , vector<Chomeur> &chomeurs)
{
	int id = 1;
	for (size_t i = 0; i < chomeurs.size(); i++)
	{
		if (chomeurs[i].getIdPersonne() >= id)
		{
			id = chomeurs[i].getIdPersonne();
		}
	}
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

bool verif_Mail(string mailAVerif ,vector<Employer>& employers, vector<Chomeur>& chomeurs, vector<Entreprise>& entreprises)
{
		for (size_t i = 0; i < chomeurs.size(); i++)
	{
		if (chomeurs[i].getMail() == mailAVerif)
		{
			return false;
		}
	}

	for (size_t i = 0; i < employers.size(); i++)
	{
		if (employers[i].getMail() == mailAVerif)
		{
			return false;
		}
	}

	for (size_t i = 0; i < entreprises.size(); i++)
	{
		if (entreprises[i].getMail() == mailAVerif)
		{
			return false;
		}
	}

	return true;
}

bool verif_NomPersonne(string nomAVerif, string prenomAVerif,vector<Employer>& employers, vector<Chomeur>& chomeurs)
{
	for (size_t i = 0; i < chomeurs.size(); i++) //verifie que le nom existe.
	{

		if (chomeurs[i].getNom() == nomAVerif && chomeurs[i].getPrenom() == prenomAVerif)
		{
			return false;
		}
	}

	for (size_t i = 0; i < employers.size(); i++) //verifie que si le nom existe.
	{

		if (employers[i].getNom() == nomAVerif && employers[i].getPrenom() == prenomAVerif)
		{

			return false;
		}
	}

	return true;

}

bool verif_NomEntreprise(string nomAVerif, vector<Entreprise>& entreprises)
{
	for (size_t i = 0; i < entreprises.size(); i++)
	{
		if (entreprises[i].getNom() == nomAVerif)
		{
			return false;
		}
	}

	return true;

}

