#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "menu.h"

vector<Chomeur> Chomeurs;
vector<Employer> Employers;
vector<Entreprise> Entreprises;
vector<Poste> Postes;

int idUtilisateur;



int onInputPrincipal()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	else if (input == '1')
	{
		affichage_menu_entreprise();
	}

	else if (input == '2')
	{
		affichage_menu_employer();
	}

	else if (input == '3')
	{
		affichage_menu_chomeur();
	}
	return 1;
}

int onInputEntreprise()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_principal();
	}

	else if (input == '1')
	{
		creer_profil_entreprise();
	}

	else if (input == '2')
	{
		identification_entreprise();
	}

	return 1;
}

int onInputEmployer()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_principal();
	}

	else if (input == '1')
	{
		creer_profil_employer();
	}

	else if (input == '2')
	{
		identification_employer();
	}

	return 1;
}

int onInputChomeur()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_principal();
	}

	else if (input == '1')
	{
		creer_profil_chomeur();
	}

	else if (input == '2')
	{
		identification_chomeur();
	}

	return 1;
}

int onInputIntEntreprise()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_entreprise();
	}

	else if (input == '1')
	{
		creer_poste();
	}

	else if (input == '2')
	{
		supprimer_poste();
	}

	else if (input == '3')
	{
		rechercher_demandeur_emploi();
	}

	return 1;
}

int onInputIntChomeur()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_chomeur();
	}

	else if (input == '1')
	{
		modification_profil_chomeur();
	}

	else if (input == '2')
	{
		transition_chercheur_emploi();
	}

	else if (input == '3')
	{
		supprimer_profil_chomeur();
	}

	return 1;
}

int onInputIntEmployer()
{
	char input;

	cin >> input;
	if (input == 'q')
	{
		exit(0);
	}

	if (input == 'p')
	{
		affichage_menu_employer();
	}

	else if (input == '1')
	{
		modification_profil_employer();
	}

	else if (input == '2')
	{
		transition_employer();
	}

	else if (input == '3')
	{
		supprimer_profil_employer();
	}

	return 1;
}

/*=========================LES MENUS============================*/

void affichage_menu_principal()
{
	
	Chomeurs = Create_Chomeur();
	
	Employers = Create_Employer();
	
	Entreprises = Create_Entreprise();
	
	Postes = Create_Poste();

	idUtilisateur = 0;

	association_poste_entreprise(Postes, Entreprises);
	association_employer_entreprise(Employers, Entreprises);

	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu principal *" << endl
		 << endl
		 << "Vous êtes :" << endl
		 << "1. Une entreprise" << endl
		 << "2. Un employé" << endl
		 << "3. A la recherche d'un emploi" << endl
		 << endl
		 << "Votre choix ('q' pour quitter) : ";

	onInputPrincipal();
}


void affichage_menu_entreprise()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu entreprise *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer le profil de votre entreprise" << endl
		 << "2. Identifier votre entreprise" << endl
		 << endl
		 << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";

	onInputEntreprise();
}

void affichage_menu_chomeur()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu recherche d'emploi *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer votre profil" << endl
		 << "2. Identifiez-vous" << endl
		 << endl
		 << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";
	onInputChomeur();
}

void affichage_menu_employer()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu employé *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer votre profil" << endl
		 << "2. Identifiez-vous" << endl
		 << endl
		 << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";
	onInputEmployer();
}

void affichage_menu_intermediaire_entreprise()
{

	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu entreprise *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer le profil d'un poste à pourvoir" << endl
		 << "2. Supprimer le profil d'un poste maintenant pourvu " << endl
		 << "3. Faire une recherche parmi les chercheurs d'emploi " << endl;
	cout << endl
		 << "Votre choix ('q' pour quitter, 'p' pour menu précédent)";
	onInputIntEntreprise();
}

void affichage_menu_intermediaire_chomeur()
{	
	string nomUtilisateur = Chomeurs[idUtilisateur].getNom();
	string prenomUtilisateur = Chomeurs[idUtilisateur].getPrenom();

	cout << "•••• Vous etes connecter en tant que " << prenomUtilisateur << nomUtilisateur << "••••" << endl;
	
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu chercheur d'emploi *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Modifier votre profil" << endl
		 << "2. Faire une transition vers employé" << endl
		 << "3. Supprimer son profil" << endl
		 << "4. Faire une recherche de poste à pourvoir";
	cout << endl
		 << "Votre choix ('q' pour quitter, 'p' pour menu précédent)";
	onInputIntChomeur();
}

void affichage_menu_intermediaire_employer()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu employé *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Modifier votre profil" << endl
		 << "2. Faire une transition vers chercheur d'emploi" << endl
		 << "3. Supprimer son profil" << endl
		 << "4. Faire une recherche de poste à pourvoir";
	cout << endl
		 << "Votre choix ('q' pour quitter, 'p' pour menu précédent)";
	onInputIntEmployer();
}

/*=========================IDENTIFICATION============================*/

void identification_entreprise()
{
	cout << " • Veuillez saisir le nom de votre entreprise : " << endl
		 << endl
		 << " ==> Nom : ";

	string nomEntreprise;

	cin >> nomEntreprise;

	

	for (size_t i = 0; i < Entreprises.size(); i++)
	{
		if (Entreprises[i].getNom() == nomEntreprise)
		{

			int id = Entreprises[i].getId();

			cout << " Connexion ...." << endl
				 << endl;
		

			idUtilisateur = id;
			affichage_menu_intermediaire_entreprise();
		}
	}

	cout << " • Nom inexistant dans les entreprises • " << endl;
	affichage_menu_entreprise();
}

void identification_chomeur()
{
	cout << " • Veuillez saisir votre nom et prenom : " << endl
		 << endl
		 << " ==> Prenom : ";

	string prenomChomeur;
	cin >> prenomChomeur;

	cout << "==> Nom :";

	string nomChomeur;
	cin >> nomChomeur;	
	

	for (size_t i = 0; i < Chomeurs.size(); i++)
	{
		if (Chomeurs[i].getNom() == nomChomeur && Chomeurs[i].getPrenom() == prenomChomeur)
		{

			int id = Chomeurs[i].getIdPersonne();
			
			cout << " Connexion ...." << endl
				 << endl;
		

			idUtilisateur = id; //semble ne pas marcher
			affichage_menu_intermediaire_chomeur();
		}
	}
	cout << " • Nom inexistant chez les chomeurs • " << endl;
	affichage_menu_chomeur();
}


void identification_employer()
{
	cout << " • Veuillez saisir votre nom et prenom : " << endl
		 << endl
		 << " ==> Prenom : ";

	string prenomChomeur;
	cin >> prenomChomeur;

	cout << "==> Nom :";

	string nomChomeur;
	cin >> nomChomeur;	
	

	for (size_t i = 0; i < Employers.size(); i++)
	{
		if (Employers[i].getNom() == nomChomeur && Employers[i].getPrenom() == prenomChomeur)
		{

			int id = Employers[i].getIdPersonne();
			
			cout << " Connexion ...." << endl
				 << endl;
		

			idUtilisateur = id; //semble ne pas marcher
			affichage_menu_intermediaire_employer();
		}
	}
	cout << " • Nom inexistant chez les employers • " << endl;
	affichage_menu_employer();
}



/*=========================LES CREATIONS DE PROFIL============================*/

void creer_profil_entreprise()
{
	Entreprise newEnterprise;
	char input[50];
	char yn;

	

	cout << " • Création d'un nouveau profil entreprise • " << endl
		 << endl;

                            /*=======NOM=====*/
NE:
	cout << " Nom de l'entreprise : " << endl;
	cin >> input;

	string newNom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	if (verif_NomEntreprise(newNom,Entreprises) == false)
		{
			cout << " * Ce nom est déjà pris ! *" << endl;
			goto NE;
		}else{
			newEnterprise.setNom(newNom);
		}

	newEnterprise.setId(rechercheIdDispo_Entreprise(Entreprises));
	idUtilisateur = newEnterprise.getId();

                           /*=======MAIL=======*/

	string newMail = input;
ME:
	cout << " Mail de l'entreprise : " << endl;
	cin >> input;
	newMail = input;

	if (verif_Mail(newMail,Employers,Chomeurs,Entreprises) == false)
		{
			cout << " * Ce mail est déjà pris ! *" << endl;
			goto ME;
		}else{
			newEnterprise.setMail(newMail);
		}

                    /*==========Code Postal===========*/
	
	cout << " Code postal de l'entreprise : " << endl;
	cin >> input;
	string newCode = input;
	//ajouter verification d'un int de 5 chiffres
	newEnterprise.setCode(newCode);


	                 /*==========Validation===========*/

	cout << " Récapitulatif de votre inscription : " << endl
		 << endl;
	newEnterprise.printInfo();

	cout << " Vous pourrez modifiez ces informations et ajoutez des postes à pourvoir après l'inscription" << endl
		 << endl;
	cout << endl
		 << " Confirmez votre inscription ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		cout << " Ajout du compte à la base de données ...... " << endl
			 << endl;
		addEntreprise(newEnterprise, Entreprises);
	}
	else if (yn == 'n')
	{
		affichage_menu_entreprise();
	}
	else
	{
		cout << " Veuillez entrez y pour oui et n pour non. " << endl
			 << endl;
	}

	

	affichage_menu_intermediaire_entreprise();
}


void creer_profil_chomeur()
{
	Chomeur newChomeur;
	char input[50];
	char yn;

	cout << " • Création d'un nouveau profil sans-emploi • " << endl
		 << endl;

	             /*==========NOM ET PRENOM===========*/
			
CN:
	cout << " Votre prénom : " << endl;
	cin >> input;

	string newPrenom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	cout << " Votre nom : " << endl;
	cin >> input;
	string newNom = input;

	if (verif_NomPersonne(newNom,newPrenom,Employers,Chomeurs) == false)
		{
			cout << " * Ce nom et prénom sont déjà pris ! *" << endl;
			goto CN;
		}else{
			newChomeur.setNom(newNom);
			newChomeur.setPrenom(newPrenom);
		}

	
	newChomeur.setId(rechercheIdDispo_Personne(Employers,Chomeurs));
	idUtilisateur = newChomeur.getIdPersonne();

	                 /*==========Maill===========*/

	 
CE:
	cout << " Votre mail : " << endl;
	cin >> input;
	string newMail = input;

	if (verif_Mail(newMail,Employers,Chomeurs,Entreprises) == false)
		{
			cout << " * Ce mail est déjà pris ! *" << endl;
			goto 	CE;
		}else{
			newChomeur.setMail(newMail);
		}

		          /*==========Code Postal===========*/

	cout << " Votre code postal : " << endl;
	cin >> input;
	string newCode = input;
	//ajouter verification d'un int de 5 chiffres
	newChomeur.setCode(newCode);

	              /*==========Competences===========*/

NEW:
	cout << " Entrez au moins une compétence : " << endl;
	cin >> input;
	string newCompetence = input;
	newChomeur.addCompetence(newCompetence);
	cout << endl
		 << " Ajoutez une compétence ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		goto NEW;
	}
	else if (yn == 'n')
	{
		goto NEXT;
	}
	else
	{
		cout << " Veuillez entrez y pour oui et n pour non. " << endl
			 << endl;
	}

	               /*==========Validation===========*/

NEXT:
	cout << " Récapitulatif de votre inscription : " << endl
		 << endl;
	newChomeur.printInfo();
	cout << " Vous pourrez modifiez ces informations et ajoutez des anciens collègues après l'inscription" << endl
		 << endl;
	cout << endl
		 << " Confirmez votre inscription ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		cout << " Ajout du compte à la base de données ...... " << endl
			 << endl;
		addChomeur(newChomeur, Chomeurs, Employers);
	}
	else if (yn == 'n')
	{
		affichage_menu_chomeur();
	}
	else
	{
		cout << " Veuillez entrez y pour oui et n pour non. " << endl
			 << endl;
	}

	newChomeur.getIdPersonne();

	affichage_menu_intermediaire_chomeur();
}



void creer_profil_employer()
{

	affichage_menu_intermediaire_employer();
}


void creer_poste()
{
	affichage_menu_intermediaire_entreprise();
}



/*=========================MODIFICATIONS DES PROFILS============================*/


void modification_profil_chomeur()
{
	Chomeur *chom = get_chomeur(idUtilisateur, Chomeurs); 
//ajouter modification mail avec verif que nouvo mail existe pas
DEB:
	cout << "\n\nSelectionner le service demandé\n\n";
	cout << " 1 - Ajouter des compétences \n 2 - Ajouter un(e) ancien(ne) collègue de travail \n 3 - Modifier le code postal \n 4 - Revenir au menu Principal \n ";
	string info;
	cout << "\nVotre Choix :";
	cin >> info;
	if (info == "1")        /*============CHANGE COMPETENCES============*/
	{
		cout << "Quelle compétence voulez vous ajouter : (Entrez r pour revenir en arriere) \n";
		string comp;
		cin >> comp;
		if (comp == "r")
			goto DEB;
		else
		{	
			chom->addCompetence(comp);
			goto DEB;
		}
	}
	else if (info == "2")  /*============CHANGE ANCIENS COLLEGUES============*/
	{

COLL:	string comp;
		cout << "Entrer le nom et prenom de votre ancien collègue : (Entrez 2 fois q pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;
		
		if (verif_NomPersonne(newNom,newPrenom,Employers,Chomeurs) == false)
		{
			cout << " * Cette personne n'éxiste pas ou plus chez nous ! *" << endl;
			goto COLL;

		}else{

			for (size_t i = 0; i < Chomeurs.size(); i++)
			{
				if (Chomeurs[i].getNom() == newNom && Chomeurs[i].getPrenom() == newPrenom)
				{	
					int id = Chomeurs[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					chom->addAncienCollegue(id);

					/*il faut aussi ajoutez ce nouveau chomeur à la liste 
					des anciens collègues de son soit disant nouveau 
					anciens collègue (à transformer en demande d'amis)*/
					Chomeurs[i].addAncienCollegue(chom->getIdPersonne());
				}
			}

			for (size_t i = 0; i < Employers.size(); i++)
			{
				if (Employers[i].getNom() == newNom && Employers[i].getPrenom() == newPrenom)
				{	
					int id = Employers[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					chom->addAncienCollegue(id);
					
					Employers[i].addAncienCollegue(chom->getIdPersonne());
				}
			}

			goto DEB;
		}

	}
	else if (info == "3")   /*============CHANGE CODE============*/
	{
		cout << "Entrez le nouveau code postal : (Entrez r pour revenir en arriere) \n";
		string code;
		cin >> code;

		int id;
		try
		{
			id = stoi(code);
		}
		catch (logic_error &)
		{
			cout << "erreur vous n'avez pas rentré un code postal valide\n";
			goto DEB;
		}
		id++;
		chom->setCode(code);
		goto DEB;
	}
	else if (info == "4")
	{
		MajCSVChomeur(Chomeurs);
		affichage_menu_intermediaire_chomeur();
	}
	else
	{
		goto DEB;
	}
}

void modification_profil_employer()
{
	Employer *empl = get_employers(idUtilisateur, Employers);


DEB1:
	empl->printInfo();
	cout << "\n\nSelectionner le service demandé\n\n";
	//et la transition ??? (Option devenir un sans emploi a mettre ici) 
	cout << " 1 - Ajouter des compétences \n 2 - Ajouter un(e) collègue de travail actuel \n 3 - Ajouter un(e) ancien(ne) collègue de travail \n 4 - Modifier le code postal \n 5 - Changer d'entreprise \n 6 - Revenir au menu Principal \n ";
	string info;
	cout << "\nVotre Choix :";
	cin >> info;
	if (info == "1")    /*============CHANGE COMPETENCES============*/
	{
		cout << "Quelle compétence voulez vous ajouter : (Entrez r pour revenir en arriere) \n";
		string comp;
		cin >> comp;
		if (comp == "r")
			goto DEB1;
		else
		{
			empl->addCompetence(comp);
			goto DEB1;
		}
	}
	else if (info == "2")   /*============CHANGE COLLEGUES============*/
	{
		string comp;
		cout << "Entrer le nom et prenom de votre collègue : (Entrez 2 fois q pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;
		/*if(comp == 'q'){
			goto DEB1;         A COOORRRRIGEER

		}  */

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;

		 if (verif_NomPersonne(newNom,newPrenom,Employers,Chomeurs) == false)
		{
			cout << " * Cette personne n'éxiste pas ou plus chez nous ! *" << endl;
			goto DEB1;

		}else{

			for (size_t i = 0; i < Chomeurs.size(); i++)
			{
				if (Chomeurs[i].getNom() == newNom && Chomeurs[i].getPrenom() == newPrenom)
				{	
					cout << " * Cette personne est sans emploi. Un collegue est une personne qui est employer ! *" << endl;
				}
			}

			for (size_t i = 0; i < Employers.size(); i++)
			{
				if (Employers[i].getNom() == newNom && Employers[i].getPrenom() == newPrenom)
				{	
					int id = Employers[i].getIdPersonne(); 
					empl->addAncienCollegue(id);
					
					Employers[i].addAncienCollegue(empl->getIdPersonne());
				}
			}

			goto DEB1;
		}
	}
	else if (info == "3")   /*============CHANGE ANCIENS COLLEGUE============*/
	{
		string comp;
		cout << "Entrer le nom et prenom de votre ancien collègue : (Entrez 2 fois q pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;
		
		
		if (verif_NomPersonne(newNom,newPrenom,Employers,Chomeurs) == false)
		{
			cout << " * Cette personne n'éxiste pas ou plus chez nous ! *" << endl;
			goto DEB1;

		}else{

			for (size_t i = 0; i < Chomeurs.size(); i++)
			{
				if (Chomeurs[i].getNom() == newNom && Chomeurs[i].getPrenom() == newPrenom)
				{	
					int id = Chomeurs[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					empl->addAncienCollegue(id);

					/*il faut aussi ajoutez ce nouveau chomeur à la liste 
					des anciens collègues de son soit disant nouveau 
					anciens collègue (à transformer en demande d'amis)*/
					Chomeurs[i].addAncienCollegue(empl->getIdPersonne());
				}
			}

			for (size_t i = 0; i < Employers.size(); i++)
			{
				if (Employers[i].getNom() == newNom && Employers[i].getPrenom() == newPrenom)
				{	
					int id = Employers[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					empl->addAncienCollegue(id);
					
					Employers[i].addAncienCollegue(empl->getIdPersonne());
				}
			}

			goto DEB1;
		}
	}

	else if (info == "4")   /*============CHANGE CODE============*/
	{
		cout << "Entrez le nouveau code postal : (Entrez r pour revenir en arriere) \n";
		string code;
		cin >> code;

		int id;
		try
		{
			id = stoi(code);
		}
		catch (logic_error &)
		{
			cout << "erreur vous n'avez pas rentré un code postal valide\n";
			goto DEB1;
		}
		id++;
		empl->setCode(code);
		goto DEB1;
	}
	else if (info == "5")    /*============CHANGE ENTREPRISE============*/
	{
		cout << "Entrez l'id de votre nouvelle entreprise' : (Entrez r pour revenir en arriere) \n";
		string code;
		cin >> code;

		int id;
		try
		{
			id = stoi(code);
		}
		catch (logic_error &)   //AAAA COORIGER : AJOUT AVEC NOM DE LENTREPRISE ET DONC TEST SUR LE NOM ENTRER AVEC VALID_NOMENTREPRISE
		{
			cout << "erreur vous n'avez pas rentré un id d'entreprise valide\n";
			goto DEB1;
		}

		int ancienid = empl->getIdEntreprise();
		Entreprise *ancien_entre = get_entreprise(ancienid, Entreprises);
		ancien_entre->deleteEmploye(idUtilisateur);
	
		ajout_employer_entreprise(*empl, id, Entreprises);

		vector<Employer> ancien_coll = get_employers_de_entreprise(ancien_entre->getId(), Employers);

		for (size_t i = 0; i < ancien_coll.size(); i++)
		{
			for (size_t j = 0; j < empl->get_collegues().size(); j++)
			{
				if (empl->get_collegues()[j] == ancien_coll[i].getIdPersonne())
				{
					empl->erase_collegue(ancien_coll[i].getIdPersonne());
				}
			}
			empl->addAncienCollegue(ancien_coll[i].getIdPersonne());
		}
		goto DEB1;
	}
	else if (info == "6")
	{
		MajCSVEmployer(Employers);
		affichage_menu_intermediaire_employer();
	}
	else
	{
		goto DEB1;
	}
}



void transition_chercheur_emploi()
{
	bool isexist = false;
	string info;
DEB2:
	cout << "Quelle enterprise voulez vous integrer ? ( Entrer r pour revenir au menu précédent )\n";
	cin >> info;
	if (info == "r")
	{
		affichage_menu_intermediaire_chomeur();
	}
	int id;
	try
	{
		id = stoi(info);
	}
	catch (logic_error &)
	{
		cout << "erreur vous n'avez pas rentré un id d'entreprise valide\n";
		goto DEB2;
	}
	for (size_t i = 0; i < Entreprises.size(); i++)
	{
		if (id == Entreprises[i].getId())
		{
			isexist = true;
		}
	}
	if (isexist)
	{
		transitionChomeur_Vers_Employer(idUtilisateur, id, Employers, Chomeurs, Entreprises);
	}
	else
	{
		cout << "L'entreprise que vous voulez integrer n'existe pas dans la base de données\n";
		goto DEB2;
	}

	affichage_menu_intermediaire_employer();
}

void transition_employer()
{

	string info;
DEB3:
	cout << "Etes vous sur ? ( Entrer y pour continuer, n pour revenir au menu précédent )\n";
	cin >> info;
	if (info == "n")
	{	

		affichage_menu_intermediaire_chomeur();
	}
	else if (info == "y")
	{
		transitionEmployer_Vers_Chomeur(idUtilisateur, Employers, Chomeurs, Entreprises);
	}
	else
	{
		goto DEB3;
	}

	affichage_menu_intermediaire_chomeur();
}

/*=========================SUPPRESSION DE PROFILS============================*/

void supprimer_profil_chomeur()
{
	affichage_menu_principal();
}

void supprimer_profil_employer()
{
	affichage_menu_principal();
}

void supprimer_poste()
{
	affichage_menu_intermediaire_entreprise();
}

/*================================SERVICES=====================================*/

void rechercher_demandeur_emploi()
{
	affichage_menu_intermediaire_entreprise();
}
