#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "menu.h"

#include "Personne.h"
#include "Entreprise.h"
#include "Poste.h"
#include "Chomeur.h"
#include "Employer.h"
#include "menu.h"
#include "Parse.h"
#include "Service.h"
#include "ajout.h"

vector<Chomeur> Chomeurs;
vector<Employer> Employers;
vector<Entreprise> Entreprises;
vector<Poste> Postes;

int idUtilisateur;

void affichage_menu_principal()
{	
	cout << "Génération des personnes sans-emplois ..." << endl
          << endl;
     Chomeurs = Create_Chomeur();
     cout << " " << endl;

     cout << "Génération des employés ..." << endl
          << endl;
     Employers = Create_Employer();
     cout << " " << endl;

     cout << "Génération des entreprises ..." << endl
          << endl;
     Entreprises = Create_Entreprise();
     cout << " " << endl;

     cout << "Génération des postes à pourvoir ..." << endl
          << endl;
     Postes = Create_Poste();

     association_poste_entreprise(Postes, Entreprises);
     association_employer_entreprise(Employers, Entreprises);

    cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl << "* Menu principal *" << endl << endl
    << "Vous êtes :" << endl << "1. Une entreprise" << endl << "2. Un employé" << endl << "3. A la recherche d'un emploi" << endl << endl << 
	"Votre choix ('q' pour quitter) : ";
	
	onInputPrincipal();

}

int onInputPrincipal()
{
	char input ;
	
	cin >> input ;
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
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
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

	return 1 ;
}

int onInputEmployer()
{
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
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

	return 1 ;
}


int onInputChomeur()
{
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
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

	return 1 ;
}

int onInputIntEntreprise()
{
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
	{
		affichage_menu_entreprise();
	}

	else if (input == '1')
	{
		creer_profil_entreprise();
	}
    
	else if (input == '2') 
	{
		supprimer_poste();
	}

	else if(input == '3')
	{
		rechercher_demandeur_emploi();
	}

	return 1 ;
}

int onInputIntChomeur()
{
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
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

	else if(input == '3')
	{
		supprimer_profil_chomeur();
	}

	return 1 ;
}

int onInputIntEmployer()
{
	char input ;
	
	cin >> input ;
	if (input == 'q')
	{
		exit(0);
	}

	if(input == 'p')
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
	
	else if(input == '3')
	{
		supprimer_profil_employer();
	}

	return 1 ;
}


void affichage_menu_entreprise()
{
    cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu entreprise *" <<  endl << endl << "Vous voulez :" << endl ;
    cout << "1. Créer le profil de votre entreprise" << endl << "2. Identifier votre entreprise à l'aide de votre ID" << endl << endl << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";

	onInputEntreprise();
}

void affichage_menu_chomeur()
{
    cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu recherche d'emploi *" <<  endl << endl << "Vous voulez :" << endl ;
    cout << "1. Créer votre profil" << endl << "2. Identifiez-vous" << endl << endl << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";
	onInputChomeur();
}

void affichage_menu_employer()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu employé *" <<  endl << endl << "Vous voulez :" << endl ;
    cout << "1. Créer votre profil" << endl << "2. Identifiez-vous" << endl << endl << "Votre choix ('q' pour quitter, 'p' pour revenir au menu précédent) :";
	onInputEmployer();
}


void creer_profil_entreprise()
{	
	Entreprise newEnterprise;
	char input[50];
	char yn;

	int maxid = 0;

	cout << " • Création d'un nouveau profil entreprise • " << endl << endl;
	
		//NOM ET ID
NE: 	cout << " Nom de l'entreprise : " << endl;
	    cin >> input ;
		
		string newNom = input; //convertion en string sinon erreur lors le la comparaison des infos retourner par les getter

		for (size_t i = 0; i < Entreprises.size(); i++) //verifie que si le nom existe.
       {	
		   	
	   		if(Entreprises[i].getNom() == newNom)
			   {
				cout << " * Ce nom d'entreprise est dejas prit ! *"<< endl ;
		   		goto NE;
				   }
	   }

		for (size_t i = 0; i < Entreprises.size(); i++) //trouve un id inéxistant.
       {
	   		if(Entreprises[i].getId() > maxid)
			   	{
		   		maxid = Entreprises[i].getId();
	   			}
		}
		
		maxid = maxid + 1; // on prend l'id maximum pour etre sur qu'il n'éxiste pas.
		newEnterprise.setId(maxid);
		newEnterprise.setNom(newNom);

		//MAIL
ME:		cout << " Mail de l'entreprise : " << endl;
	    cin >> input ;
		string newMail = input; 

		for (size_t i = 0; i < Entreprises.size(); i++) //trouve un id inéxistant.
       {	
		    
	   		if(Entreprises[i].getMail() == newMail)
			   {
		   		cout << " * Ce mail est dejas prit ! *"<< endl ;
		   		goto ME;
	   			}
		}
		
		newEnterprise.setMail(newMail);

		cout << " Code postal de l'entreprise : " << endl;
	    cin >> input ;
		string newCode = input; 
		//ajouter verification d'un int de 5 chiffres
		newEnterprise.setCode(newCode);

		cout << " Récapitulatif de votre inscription : " << endl << endl;
		newEnterprise.printInfo();
		cout << endl << " Confirmez votre inscription ? (y/n) : " << endl;
		cin >> yn ;
		if (yn == 'y')
		{
		  cout << " Ajout du compte à la base de données ...... " << endl << endl;
		  addEntreprise(newEnterprise,Entreprises);

		}else if(yn == 'n'){
			affichage_menu_entreprise();
		}else{
			cout << " Veuillez entrez y pour oui et n pour non. " << endl << endl;
		}

		
	idUtilisateur = newEnterprise.getId();

	affichage_menu_intermediaire_entreprise();
}

void creer_profil_chomeur()
{
    affichage_menu_intermediaire_chomeur();
}

void creer_profil_employer()
{
    affichage_menu_intermediaire_employer();
}


void identification_entreprise()
{	
	cout << " • Veuillez saisir l'identifiant de votre entreprise : " << endl << endl << " ==> Identifiant : ";

	string input ;
	
	cin >> input ;

	int id = stoi(input);

	for (size_t i = 0; i < Entreprises.size(); i++)
   {
	   if(Entreprises[i].getId() == id){

		   string nom = Entreprises[i].getNom();

		   cout << "*** • Vous etes désormais connecter • ***" << endl << endl ;
		   cout << " • Bienvenue sur votre compte " << nom << " • " << endl ;
		   
		   idUtilisateur = id;
		   affichage_menu_intermediaire_entreprise();
	   }
   }

	cout << " • Id inéxistant dans les entreprises • "<< endl ;
	affichage_menu_entreprise();

}

void identification_chomeur()
{
cout << " • Veuillez saisir votre identifiant : " << endl << endl << " ==> Identifiant : " ;

	string input ;
	
	cin >> input ;

	int id = stoi(input);

	for (size_t i = 0; i < Chomeurs.size(); i++)
   {
	   if(Chomeurs[i].getIdPersonne() == id){

		   string nom = Chomeurs[i].getNom();
		   string prenom = Chomeurs[i].getPrenom();

		   cout << "*** • Vous etes désormais connecter • ***" << endl << endl ;
		   cout << " • Bienvenue Monsieur/Madame " << nom << " " << prenom << " • "  << endl ;
		   idUtilisateur = id;

		   affichage_menu_intermediaire_chomeur();
	   }
   }

	cout << " • Id inéxistant chez les sans emplois • "<< endl ;

	affichage_menu_chomeur();
}

void identification_employer()
{
	cout << " • Veuillez saisir votre identifiant • " << endl << endl << " ==> Identifiant : ";

	string input ;
	
	cin >> input ;

	int id = stoi(input);

	for (size_t i = 0; i < Employers.size(); i++)
   {
	   if(Employers[i].getIdPersonne() == id){

		   string nom = Employers[i].getNom();
		   string prenom = Employers[i].getPrenom();

		   cout << "*** • Vous etes désormais connecter • ***" << endl << endl ;
		   cout << " • Bienvenue Monsieur/Madame " << nom << " " << prenom << " • "  << endl ;
		   
		   idUtilisateur = id;
		   affichage_menu_intermediaire_employer();
	   }
   }

	cout << " • Id inéxistant chez les employés • "<< endl ;
	affichage_menu_employer();
}

void affichage_menu_intermediaire_entreprise()
{
    cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu entreprise *" <<  endl << endl << "Vous voulez :" << endl ;
    cout << "1. Créer le profil d'un poste à pourvoir" << endl <<
     "2. Supprimer le profil d'un poste maintenant pourvu " << endl << 
     "3. Faire une recherche parmi les chercheurs d'emploi " << endl ;
    cout << endl << "Votre choix ('q' pour quitter, 'p' pour menu précédent)" ;
	onInputIntEntreprise();
}

void affichage_menu_intermediaire_chomeur()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu chercheur d'emploi *" <<  endl << endl << "Vous voulez :" << endl  ;
    cout << "1. Modifier son profil" << endl <<
     "2. Faire une transition vers employé" << endl << 
     "3. Supprimer son profil" << endl <<
     "4. Faire une recherche de poste à pourvoir";
    cout << endl << "Votre choix ('q' pour quitter, 'p' pour menu précédent)" ;
	onInputIntChomeur();
}

void affichage_menu_intermediaire_employer()
{
	cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl <<  "* Menu employé *" <<  endl << endl << "Vous voulez :" << endl  ;
    cout << "1. Modifier son profil" << endl <<
     "2. Faire une transition vers chercheur d'emploi" << endl << 
     "3. Supprimer son profil" << endl <<
     "4. Faire une recherche de poste à pourvoir";
    cout << endl << "Votre choix ('q' pour quitter, 'p' pour menu précédent)" ;
	onInputIntEmployer();
}

void modification_profil_chomeur()
{
	affichage_menu_intermediaire_chomeur();
}

void modification_profil_employer()
{
	affichage_menu_intermediaire_employer();
}


void transition_chercheur_emploi()
{
	affichage_menu_intermediaire_employer();
}

void transition_employer()
{
	affichage_menu_intermediaire_chomeur();
}

void supprimer_profil_chomeur()
{
	affichage_menu_principal();
}

void supprimer_profil_employer()
{
	affichage_menu_principal();
}

void creer_poste()
{
	affichage_menu_intermediaire_entreprise();
}

void supprimer_poste()
{
	affichage_menu_intermediaire_entreprise();
}

void rechercher_demandeur_emploi()
{
	affichage_menu_intermediaire_entreprise();
}

