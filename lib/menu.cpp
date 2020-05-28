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
	else
	{
		onInputPrincipal();
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
	else
	{
		onInputEntreprise();
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
	else
	{
		onInputEmployer();
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
	else
	{
		onInputChomeur();
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

	else if (input == '4')
	{
		supprimer_profil_entreprise();
	}

	else if (input == '5')
	{
		rechercher_demandeur_emploi();
	}
	else
	{
		onInputIntEntreprise();
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
	else if (input == '4')
	{
		rechercher_poste_a_pourvoir();
	}
	else if (input == '5')
	{
		rechercher_parmi_ancien_collegue();
	}
	else
	{
		onInputIntChomeur();
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
	else if (input == '4')
	{
		rechercher_poste_a_pourvoir();
	}
	else if (input == '5')
	{
		rechercher_parmi_ancien_collegue();
	}
	else
	{
		onInputIntEmployer();
	}

	return 1;
}

/*=========================LES MENUS============================*/

void affichage_menu_principal()
{
	system("clear");
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
	system("clear");
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
	system("clear");
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu recherche d'emploi *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer votre profil" << endl
		 << "2. Identifiez-vous" << endl
		 << endl
		 << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) : ";
	onInputChomeur();
}

void affichage_menu_employer()
{
	system("clear");
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "* Menu employé *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer votre profil" << endl
		 << "2. Identifiez-vous" << endl
		 << endl
		 << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) : ";
	onInputEmployer();
}

void affichage_menu_intermediaire_entreprise()
{
	system("clear");
	Entreprise *entre = get_entreprise(idUtilisateur, Entreprises);
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "•••• Vous êtes actuellement sur le compte de l'entreprise " << entre->getNom() << " ••••\n"
		 << endl
		 << "* Menu entreprise *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Créer le profil d'un poste à pourvoir" << endl
		 << "2. Supprimer le profil d'un poste maintenant pourvu " << endl
		 << "3. Faire une recherche parmi les chercheurs d'emploi " << endl
		 << "4. Supprimer le profil de votre entreprise " << endl
		 << "5. Rechercher le profil d'un chercheur d'emploi " << endl;
	cout << endl
		 << "Votre choix ('q' pour quitter, 'p' pour menu précédent) : ";
	onInputIntEntreprise();
}

void affichage_menu_intermediaire_chomeur()
{
	system("clear");
	Chomeur *chom = get_chomeur(idUtilisateur, Chomeurs);
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl;
	cout << "•••• Bonjour " << chom->getPrenom() << " nous sommes ravis de vous revoir \n\n"
		 << "••••" << endl;
	cout << "* Menu chercheur d'emploi *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Modifier votre profil" << endl
		 << "2. Faire une transition vers employé" << endl
		 << "3. Supprimer son profil" << endl
		 << "4. Faire une recherche de poste à pourvoir" << endl
		 << "5. Rechercher parmi vos anciens collègues" << endl;
	cout << endl
		 << "\nVotre choix ('q' pour quitter, 'p' pour menu précédent) : ";
	onInputIntChomeur();
}

void affichage_menu_intermediaire_employer()
{
	system("clear");
	Employer *empl = get_employers(idUtilisateur, Employers);
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl
		 << endl
		 << "•••• Bonjour " << empl->getPrenom() << " nous sommes ravis de vous revoir "
		 << "••••\n\n"
		 << endl;
	cout << "* Menu employé *" << endl
		 << endl
		 << "Vous voulez :" << endl;
	cout << "1. Modifier votre profil" << endl
		 << "2. Faire une transition vers chercheur d'emploi" << endl
		 << "3. Supprimer son profil" << endl
		 << "4. Faire une recherche de poste à pourvoir" << endl
		 << "5. Rechercher parmi vos anciens collègues" << endl;
	cout << endl
		 << "Votre choix ('q' pour quitter, 'p' pour menu précédent) : ";
	onInputIntEmployer();
}

/*=========================IDENTIFICATION============================*/

void identification_entreprise()
{
	system("clear");
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
	system("clear");
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
	system("clear");
	cout << " • Veuillez saisir votre nom et prenom : " << endl
		 << endl
		 << " ==> Prenom : ";

	string prenomChomeur;
	cin >> prenomChomeur;

	cout << "==> Nom : ";

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
	string input;
	char yn;
	system("clear");

NE:
	cout << " • Création d'un nouveau profil entreprise • " << endl
		 << endl;

	/*=======NOM=====*/
	cout << " Nom de l'entreprise : (pour les noms composés, utiliser des tirets, exemple: 'L'Atelier-Du-Bois') " << endl;
	cin >> input;

	string newNom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	if (verif_NomEntreprise(newNom, Entreprises) == false)
	{
		cout << " * Ce nom est déjà pris ! *" << endl;
		goto NE;
	}
	else
	{
		newEnterprise.setNom(newNom);
	}

	newEnterprise.setId(rechercheIdDispo_Entreprise(Entreprises));
	idUtilisateur = newEnterprise.getId();

	/*=======MAIL=======*/

	string newMail = input;
	system("clear");
ME:
	cout << " Mail de l'entreprise : " << endl;
	cin >> input;
	newMail = input;

	if (verif_Mail(newMail, Employers, Chomeurs, Entreprises) == false)
	{
		cout << " * Ce mail est déjà pris ! *" << endl;
		goto ME;
	}
	else
	{
		newEnterprise.setMail(newMail);
	}

	/*==========Code Postal===========*/
	system("clear");
CODE:
	cout << " Code postal de l'entreprise : " << endl;
	cin >> input;
	int id;
	try
	{
		id = stoi(input);
	}
	catch (logic_error &)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide\n";
		goto CODE;
	}
	if (input.size() != 5)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide (format) \n";
		goto CODE;
	}
	id++;
	newEnterprise.setCode(input);

	/*==========Validation===========*/
	system("clear");

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
	string input;
	char yn;

	system("clear");

	cout << " • Création d'un nouveau profil sans-emploi • " << endl
		 << endl;

	/*==========NOM ET PRENOM===========*/

CN:
	cout << " Votre prénom (pour les noms composés, utiliser des tirets, exemple: 'Marie-Pierre') : " << endl;
	cin >> input;

	string newPrenom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	cout << " Votre nom (pour les noms composés, utiliser des tirets, exemple: 'Martin-Dupont') : : " << endl;
	cin >> input;
	string newNom = input;

	if (verif_NomPersonne(newNom, newPrenom, Employers, Chomeurs) == false)
	{
		cout << " * Ce nom et prénom sont déjà pris ! *" << endl;
		goto CN;
	}
	else
	{
		newChomeur.setNom(newNom);
		newChomeur.setPrenom(newPrenom);
	}

	newChomeur.setId(rechercheIdDispo_Personne(Employers, Chomeurs));
	idUtilisateur = newChomeur.getIdPersonne();

	/*==========Maill===========*/
CE:
	system("clear");
	cout << " Votre mail : " << endl;
	cin >> input;
	string newMail = input;

	if (verif_Mail(newMail, Employers, Chomeurs, Entreprises) == false)
	{
		cout << " * Ce mail est déjà pris ! *" << endl;
		goto CE;
	}
	else
	{
		newChomeur.setMail(newMail);
	}

	/*==========Code Postal===========*/
	system("clear");
CODE1:
	cout << " Code postal : " << endl;
	cin >> input;
	int id;
	try
	{
		id = stoi(input);
	}
	catch (logic_error &)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide\n";
		goto CODE1;
	}
	if (input.size() != 5)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide (format) \n";
		goto CODE1;
	}
	id++;
	newChomeur.setCode(input);

	/*==========Competences===========*/
	system("clear");
NEW:

	cout << " Entrez une compétence : (pour les compétences comportant plusieurs mots, utiliser des tirets, exemple: 'tennis-de-table') : " << endl;
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
		goto NEW;
	}

	/*==========Validation===========*/

NEXT:
	system("clear");
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
	Employer newEmployer;
	string input;
	char yn;

	system("clear");

	cout << " • Création d'un nouveau profil employé • " << endl
		 << endl;

	/*==========NOM ET PRENOM===========*/

CN10:
	cout << " Votre prénom (pour les noms composés, utiliser des tirets, exemple: 'Marie-Pierre') : " << endl;
	cin >> input;

	string newPrenom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	cout << " Votre nom (pour les noms composés, utiliser des tirets, exemple: 'Martin-Dupont') :: " << endl;
	cin >> input;
	string newNom = input;

	if (verif_NomPersonne(newNom, newPrenom, Employers, Chomeurs) == false)
	{
		cout << " * Ce nom et prénom sont déjà pris ! *" << endl;
		goto CN10;
	}
	else
	{
		newEmployer.setNom(newNom);
		newEmployer.setPrenom(newPrenom);
	}

	newEmployer.setId(rechercheIdDispo_Personne(Employers, Chomeurs));
	idUtilisateur = newEmployer.getIdPersonne();

	/*==========Maill===========*/
CE10:
	system("clear");
	cout << " Votre mail : " << endl;
	cin >> input;
	string newMail = input;

	if (verif_Mail(newMail, Employers, Chomeurs, Entreprises) == false)
	{
		cout << " * Ce mail est déjà pris ! *" << endl;
		goto CE10;
	}
	else
	{
		newEmployer.setMail(newMail);
	}

	/*==========Code Postal===========*/
	system("clear");
CODE10:
	cout << " Code postal : " << endl;
	cin >> input;
	int id;
	try
	{
		id = stoi(input);
	}
	catch (logic_error &)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide\n";
		goto CODE10;
	}
	if (input.size() != 5)
	{
		cout << "erreur vous n'avez pas rentré un code postal valide (format) \n";
		goto CODE10;
	}
	id++;
	newEmployer.setCode(input);

	/*==========Competences===========*/
	system("clear");
NEW10:

	cout << " Entrez une compétence (pour les compétences composées de plusieurs mots, utiliser des tirets, exemple: 'tennis-de-table') : " << endl;
	cin >> input;
	string newCompetence = input;
	newEmployer.addCompetence(newCompetence);
	cout << endl
		 << " Ajoutez une compétence ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		goto NEW10;
	}
	else if (yn == 'n')
	{
		goto NOM_ENTREPRISE10;
	}
	else
	{
		cout << " Veuillez entrez y pour oui et n pour non. " << endl
			 << endl;
		goto NEW10;
	}

	/*==========Entreprise===========*/
	system("clear");
NOM_ENTREPRISE10:
	cout << "\n\nEntrez le nom de votre entreprise' : \n";
	string nom;
	cin >> nom;

	bool verif = false;
	size_t i;
	int id2;
	for (i = 0; i < Entreprises.size(); i++)
	{
		if (Entreprises[i].getNom() == nom)
		{
			id2 = Entreprises[i].getId();
			Entreprises[i].addEmploye(newEmployer.getIdPersonne());
			newEmployer.setIdEntreprise(id2);
			verif = true;
		}
	}
	if (verif == false)
	{
		cout << " • Nom inexistant dans les entreprises • " << endl;
		goto NOM_ENTREPRISE10;
	}

	/*==========Validation===========*/
	system("clear");

	cout << " Récapitulatif de votre inscription : " << endl
		 << endl;
	newEmployer.printInfo();
	cout << " Vous pourrez modifiez ces informations et ajoutez des anciens collègues après l'inscription" << endl
		 << endl;
	cout << endl
		 << " Confirmez votre inscription ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		cout << " Ajout du compte à la base de données ...... " << endl
			 << endl;
		addEmployer(newEmployer, Employers, Chomeurs);
	}
	else if (yn == 'n')
	{
		affichage_menu_employer();
	}
	else
	{
		cout << " Veuillez entrez y pour oui et n pour non. " << endl
			 << endl;
	}

	affichage_menu_intermediaire_employer();
}

void creer_poste()
{
	Poste newPoste;
	string input;
	char yn;

	system("clear");

	cout << " • Création d'un nouveau poste • " << endl
		 << endl;

	/*==========TITRE===========*/

	cout << " Titre du poste (pour les noms composés, utiliser des tirets, exemple: 'Développeur-Web') : " << endl;
	cin >> input;

	string newTitre = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

	newPoste.setTitre(newTitre);

	/*===========ID=============*/
	newPoste.setId(rechercheIdDispo_Poste(Postes));

	/*==========Competences===========*/
	system("clear");
NEW:

	cout << " Entrez une compétence requise : (pour les compétences comportant plusieurs mots, utiliser des tirets, exemple: 'tennis-de-table') : " << endl;
	cin >> input;
	string newCompetence = input;
	newPoste.addCompetence(newCompetence);
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
		goto NEW;
	}

	/*==========Validation===========*/

NEXT:
	system("clear");
	newPoste.setIdEntreprise(idUtilisateur);
	cout << " Récapitulatif du nouveau poste : " << endl
		 << endl;
	newPoste.printInfo();
	cout << endl
		 << " Confirmez la création du nouveau poste ? (y/n) : " << endl;
	cin >> yn;
	if (yn == 'y')
	{
		cout << " Ajout du poste à la base de données ...... " << endl
			 << endl;
		Entreprise *entre = get_entreprise(idUtilisateur, Entreprises);
		entre->addJob(newPoste.getId());
		addPoste(newPoste, Postes);
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

/*=========================MODIFICATIONS DES PROFILS============================*/

void modification_profil_chomeur()
{
	Chomeur *chom = get_chomeur(idUtilisateur, Chomeurs);
//ajouter modification mail avec verif que nouvo mail existe pas
DEB:
	system("clear");
	cout << "\n\nSelectionner le service demandé\n\n";
	cout << " 1 - Ajouter des compétences \n 2 - Ajouter un(e) ancien(ne) collègue de travail \n 3 - Modifier le code postal \n 4 - Revenir au menu Principal \n ";
	string info;
	cout << "\nVotre Choix : ";
	cin >> info;
	if (info == "1") /*============CHANGE COMPETENCES============*/
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
	else if (info == "2") /*============CHANGE ANCIENS COLLEGUES============*/
	{

	COLL:
		string comp;
		cout << "Entrer le nom et prenom de votre ancien collègue : (Entrez 2 fois q pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;

		if (verif_NomPersonne(newNom, newPrenom, Employers, Chomeurs) == true)
		{
			cout << " * Cette personne n'existe pas ou plus chez nous ! *" << endl;
			goto COLL;
		}
		else
		{

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
	else if (info == "3") /*============CHANGE CODE============*/
	{
		system("clear");
	CODE3:
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
			goto CODE3;
		}
		if (code.size() != 5)
		{
			cout << "erreur vous n'avez pas rentré un code postal valide (format)\n";
			goto CODE3;
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
	system("clear");
	empl->printInfo();
	cout << "\n\nSelectionner le service demandé\n\n";
	cout << " 1 - Ajouter des compétences \n 2 - Ajouter un(e) collègue de travail actuel \n 3 - Ajouter un(e) ancien(ne) collègue de travail \n 4 - Modifier le code postal \n 5 - Changer d'entreprise \n 6 - Revenir au menu Principal \n ";
	string info;
	cout << "\nVotre Choix : ";
	cin >> info;
	if (info == "1") /*============CHANGE COMPETENCES============*/
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
	else if (info == "2") /*============CHANGE COLLEGUES============*/
	{
		string comp;
		cout << "Entrer le nom et prenom de votre collègue : (Entrez 'r' pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;
		if (comp == "r")
		{
			goto DEB1;
		}

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;

		if (verif_NomPersonne(newNom, newPrenom, Employers, Chomeurs) == true)
		{
			cout << " * Cette personne n'existe pas ou plus chez nous ! *" << endl;
			goto DEB1;
		}
		else
		{

			for (size_t i = 0; i < Chomeurs.size(); i++)
			{
				if (Chomeurs[i].getNom() == newNom && Chomeurs[i].getPrenom() == newPrenom)
				{
					cout << " * Cette personne est sans emploi. Un collegue est une personne qui est employé ! *" << endl;
				}
			}

			for (size_t i = 0; i < Employers.size(); i++)
			{
				if (Employers[i].getNom() == newNom && Employers[i].getPrenom() == newPrenom)
				{
					int id = Employers[i].getIdPersonne();
					empl->addAncienCollegue(id);
				}
			}

			goto DEB1;
		}
	}
	else if (info == "3") /*============CHANGE ANCIENS COLLEGUE============*/
	{
		string comp;
		cout << "Entrer le nom et prenom de votre ancien collègue : (Entrez 2 fois q pour revenir en arriere) \n";
		cout << " Son prénom : " << endl;
		cin >> comp;

		string newPrenom = comp; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		cout << " Son nom : " << endl;
		cin >> comp;
		string newNom = comp;

		if (verif_NomPersonne(newNom, newPrenom, Employers, Chomeurs) == true)
		{
			cout << " * Cette personne n'existe pas ou plus chez nous ! *" << endl;
			goto DEB1;
		}
		else
		{

			for (size_t i = 0; i < Chomeurs.size(); i++)
			{
				if (Chomeurs[i].getNom() == newNom && Chomeurs[i].getPrenom() == newPrenom)
				{
					int id = Chomeurs[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					empl->addAncienCollegue(id);
				}
			}

			for (size_t i = 0; i < Employers.size(); i++)
			{
				if (Employers[i].getNom() == newNom && Employers[i].getPrenom() == newPrenom)
				{
					int id = Employers[i].getIdPersonne(); //on prend son id pour lajouter a la liste du nouveau profil
					empl->addAncienCollegue(id);
				}
			}

			goto DEB1;
		}
	}

	else if (info == "4") /*============CHANGE CODE============*/
	{
		cout << "\n\nEntrez le nouveau code postal : (Entrez r pour revenir en arriere) \n";
		string code;
		cin >> code;

		int id;
		try
		{
			id = stoi(code);
		}
		catch (logic_error &)
		{
			cout << "Erreur vous n'avez pas rentré un code postal valide\n";
			goto DEB1;
		}
		id++;
		empl->setCode(code);
		goto DEB1;
	}
	else if (info == "5") /*============CHANGE ENTREPRISE============*/
	{
	NOM_ENTREPRISE:
		cout << "\n\nEntrez le nom de votre nouvelle entreprise' : (Entrez r pour revenir en arriere) \n";
		string nom;
		cin >> nom;
		bool verif = false;
		size_t i;
		int id;
		for (i = 0; i < Entreprises.size(); i++)
		{
			if (Entreprises[i].getNom() == nom)
			{

				id = Entreprises[i].getId();
				verif = true;
			}
		}
		if (verif == false)
		{
			cout << " • Nom inexistant dans les entreprises • " << endl;
			goto NOM_ENTREPRISE;
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
	system("clear");
NOM_ENTREPRISE2:
	cout << "\n\nEntrez le nom de votre nouvelle entreprise' : (Entrez r pour revenir en arriere) \n";
	string nom;
	cin >> nom;
	if (nom == "r")
	{
		affichage_menu_intermediaire_chomeur();
	}
	bool verif = false;
	size_t i;
	int id;
	for (i = 0; i < Entreprises.size(); i++)
	{
		if (Entreprises[i].getNom() == nom)
		{

			id = Entreprises[i].getId();
			verif = true;
		}
	}
	if (verif == false)
	{
		cout << " • Nom inexistant dans les entreprises • " << endl;
		goto NOM_ENTREPRISE2;
	}

	else
	{
		transitionChomeur_Vers_Employer(idUtilisateur, id, Employers, Chomeurs, Entreprises);
	}

	affichage_menu_intermediaire_employer();
}

void transition_employer()
{

	string info;
DEB3:
	system("clear");
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
DEBSUPPR:
	cout << "Vous allez supprimer votre profil de chercheur d'emploi, êtes vous sûr? (y pour continuer, n pour revenir en arrière) \n";
	string input;
	cin >> input;

	if (input == "y")
	{
		delChomeur(Chomeurs, Employers, idUtilisateur);
	DEBSUPPR2:
		cout << "Profil supprimé, voulez-vous retourner au menu principal? (y pour oui, n pour quitter)\n";
		string input2;
		cin >> input2;
		if (input2 == "y")
		{
			affichage_menu_principal();
		}

		else if (input2 == "n")
		{
			exit(0);
		}
		else
		{
			goto DEBSUPPR2;
		}
	}

	else if (input == "n")
		affichage_menu_intermediaire_chomeur();
	else
	{
		goto DEBSUPPR;
	}
}

void supprimer_profil_employer()
{
DEBSUPPREMPL:
	cout << "Vous allez supprimer votre profil d'employé, êtes vous sûr? (y pour continuer, n pour revenir en arrière) \n";
	string input;
	cin >> input;

	if (input == "y")
	{
		delEmployer(Employers, Chomeurs, Entreprises, idUtilisateur);
	DEBSUPPREMPL2:
		cout << "Profil supprimé, voulez-vous retourner au menu principal? (y pour oui, n pour quitter)\n";
		string input2;
		cin >> input2;
		if (input2 == "y")
		{
			affichage_menu_principal();
		}

		else if (input2 == "n")
		{
			exit(0);
		}
		else
		{
			goto DEBSUPPREMPL2;
		}
	}

	else if (input == "n")
		affichage_menu_intermediaire_employer();
	else
	{
		goto DEBSUPPREMPL;
	}
}

void supprimer_profil_entreprise()
{
DEBSUPPRENTRE:
	cout << "Vous allez supprimer le profil de votre entreprise, êtes vous sûr? (y pour continuer, n pour revenir en arrière) \n";
	string input;
	cin >> input;

	if (input == "y")
	{
		Entreprise *entre = get_entreprise(idUtilisateur, Entreprises);
		vector<int> postes_entre_id = entre->getJobs();

		//avant de supprimer l'entreprise, il faut supprimer tous ses postes à pourvoir
		for (size_t i = 0; i < postes_entre_id.size(); i++)
		{
			delPoste(Postes, Entreprises, postes_entre_id[i]);
		}

		delEntreprise(Entreprises, Employers, idUtilisateur);

	DEBSUPPRENTRE2:
		cout
			<< "Profil supprimé, voulez-vous retourner au menu principal? (y pour oui, n pour quitter)\n";
		string input2;
		cin >> input2;
		if (input2 == "y")
		{
			affichage_menu_principal();
		}

		else if (input2 == "n")
		{
			exit(0);
		}
		else
		{
			goto DEBSUPPRENTRE2;
		}
	}

	else if (input == "n")
		affichage_menu_intermediaire_entreprise();
	else
	{
		goto DEBSUPPRENTRE;
	}
}

void supprimer_poste()
{
DEBSUPPRPOSTE:
	Entreprise *entre = get_entreprise(idUtilisateur, Entreprises);
	vector<int> postes_entre_id = entre->getJobs();
	vector<Poste> postes_entre;

	for (size_t i = 0; i < postes_entre_id.size(); i++)
	{
		postes_entre.push_back(*get_poste(postes_entre_id[i], Postes));
	}

	cout << "\n\nVoici les différents postes de votre entreprise : \n";
	affichage_vecteur_Poste(postes_entre, Entreprises);
	cout << "\nVeuillez rentrer l'ID du poste que vous souhaitez supprimer \n";
	string input_poste;
	cin >> input_poste;

	int input_poste2;
	input_poste2 = stoi(input_poste);
	cout << "Vous allez supprimer le poste n° " << input_poste2 << ", êtes vous sûr? (y pour continuer, n pour revenir en arrière) \n";
	string input;
	cin >> input;

	if (input == "y")
	{
		delPoste(Postes, Entreprises, input_poste2);
	DEBSUPPRPOSTE2:
		cout << "Poste supprimé, voulez-vous retourner au menu principal? (y pour oui, n pour quitter)\n";
		string input2;
		cin >> input2;
		if (input2 == "y")
		{
			affichage_menu_principal();
		}

		else if (input2 == "n")
		{
			exit(0);
		}
		else
		{
			goto DEBSUPPRPOSTE2;
		}
	}

	else if (input == "n")
		affichage_menu_intermediaire_entreprise();
	else
	{
		goto DEBSUPPRPOSTE;
	}
}

/*================================SERVICES=====================================*/

void rechercher_demandeur_emploi()
{
DEBRECHEMPLOI:
	cout << "\nVeuillez préciser votre recherche: uniquement par compétences, ou par compétences et code postal? \n"
		 << " -> 1. Uniquement par Compétences \n"
		 << " -> 2. Par Compétences et Code Postal \n";
	string input;
	cin >> input;

	if (input == "1")
	{
		string comp_chomeur1;
		cout << "\n Quelle compétence recherchez-vous? \n";
		cin >> comp_chomeur1;

		cout << "\n Voici les profils des chercheurs d'emplois correspondant : \n";
		affichage_vecteur_chomeur(recherche_chomeur_par_comp(comp_chomeur1, Chomeurs));

		cout << "\n \n Pour revenir en arrière: entrez 'r', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;
		if (new_input1 == "r")
			goto DEBRECHEMPLOI;
		else if (new_input1 == "q")
			exit(0);
	}

	else if (input == "2")
	{
		string comp_chomeur2;
		string cp;
		cout << "\nQuelle compétence recherchez-vous? \n";
		cin >> comp_chomeur2;
		cout << "\nQuel Code Postal souhaitez-vous considérer? \n";
		cin >> cp;

		cout << "\nVoici les profils des chercheurs d'emplois correspondant : \n";
		affichage_vecteur_chomeur(recherche_chomeur_par_comp_CP(comp_chomeur2, cp, Chomeurs));

		cout << "\n \nPour revenir en arrière: entrez 'r', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;
		if (new_input1 == "r")
			goto DEBRECHEMPLOI;
		else if (new_input1 == "q")
			exit(0);
	}
}

void rechercher_poste_a_pourvoir()
{
DEBRECHPOSTE:
	cout << "\nVeuillez préciser votre recherche de poste: uniquement par compétences, ou par compétences et code postal? \n"
		 << " -> 1. Uniquement par Compétences \n"
		 << " -> 2. Par Compétences et Code Postal \n";
	string input;
	cin >> input;

	if (input == "1")
	{
		string comp_chomeur1;
		cout << "\n Pour quelle compétence souhaitez vous trouver un job? \n";
		cin >> comp_chomeur1;

		cout << "\n Voici les jobs correspondant : \n";
		affichage_vecteur_Poste(recherche_par_comp(comp_chomeur1, Postes), Entreprises);
		if ((recherche_par_comp(comp_chomeur1, Postes), Entreprises).size() == 0)
			cout << "Il n'existe pas de postes correspondants \n\n";

		cout << "\n \n Pour revenir en arrière: entrez 'r', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;
		if (new_input1 == "r")
			goto DEBRECHPOSTE;
		else if (new_input1 == "q")
			exit(0);
	}

	else if (input == "2")
	{
		string comp_chomeur2;
		string cp;
		cout << "\nPour quelle compétence souhaitez vous trouver un job? \n";
		cin >> comp_chomeur2;
		cout << "\nQuel Code Postal souhaitez-vous considérer? \n";
		cin >> cp;

		cout << "\nVoici les postes correspondant : \n";
		affichage_vecteur_Poste(recherche_par_comp_CP(comp_chomeur2, cp, Postes, Entreprises), Entreprises);
		if ((recherche_par_comp_CP(comp_chomeur2, cp, Postes, Entreprises), Entreprises).size() == 0)
			cout << "Il n'existe pas de postes correspondants \n\n";
		cout << "\n \nPour revenir en arrière: entrez 'r', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;
		if (new_input1 == "r")
			goto DEBRECHPOSTE;
		else if (new_input1 == "q")
			exit(0);
	}
}

void rechercher_parmi_ancien_collegue()
{
	system("clear");
DEBRECHANCIENCOLLEGUE:
	cout << "\nVoulez vous chercher vos anciens collègues par entreprise ou par compétence? \n"
		 << " -> 1. Par entreprise \n"
		 << " -> 2. Par compétence \n";
	string input;
	cin >> input;

	Employer *empl;
	Chomeur *chom;
	vector<int> id_ancien_collegues;

	bool verifempl = false;

	for (size_t i = 0; i < Employers.size(); i++)
	{
		if (Employers[i].getIdPersonne() == idUtilisateur)
		{
			verifempl = true;
		}
	}

	if (verifempl == true)
	{
		empl = get_employers(idUtilisateur, Employers);
		id_ancien_collegues = empl->get_Anciens_collegues();
	}

	else
	{
		chom = get_chomeur(idUtilisateur, Chomeurs);
		id_ancien_collegues = chom->get_Anciens_collegues();
	}

	if (input == "1")
	{
		cout << "Veuillez saisir le nom de l'entreprise \n";
		string input_entre;
		cin >> input_entre;
		cout << "Voici la liste de vos anciens collègues correspondant : \n";
		recherche_ancien_collegue_entreprise(id_ancien_collegues, Employers, Entreprises, input_entre);

	DEBDEBDEB:
		cout << "\n \n Pour revenir en arrière: entrez 'r', pour revenir au menu principal, entrez 'p', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;

		if (new_input1 == "r")
			goto DEBRECHANCIENCOLLEGUE;
		else if (new_input1 == "q")
			exit(0);
		else if (new_input1 == "p")
			affichage_menu_principal();
		else
		{
			goto DEBDEBDEB;
		}
	}
	else if (input == "2")
	{
		cout << "Veuillez saisir la compétence recherchée \n";
		string input_comp;
		cin >> input_comp;
		cout << "Voici la liste de vos anciens collègues correspondant : \n";
		recherche_ancien_collegue_competence(id_ancien_collegues, Employers, Chomeurs, input_comp);

	DEBDEBDEB1:
		cout << "\n \n Pour revenir en arrière: entrez 'r', pour revenir au menu principal, entrez 'p', pour quitter : entrez 'q'\n";
		string new_input1;
		cin >> new_input1;

		if (new_input1 == "r")
			goto DEBRECHANCIENCOLLEGUE;
		else if (new_input1 == "q")
			exit(0);
		else if (new_input1 == "p")
			affichage_menu_principal();
		else
		{
			goto DEBDEBDEB1;
		}
	}
}