#include <iostream>
#include <string>
using namespace std;

#include "menu.h"


int onInputPrincipal()
{
	int i = 0 ;
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
		creer_poste();
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

void affichage_menu_principal()
{
    cout << "*** Bienvenu sur LuminIn, le site des pros ***" << endl << endl << "* Menu principal *" << endl << endl
    << "Vous êtes :" << endl << "1. Une entreprise" << endl << "2. Un employé" << endl << "3. A la recherche d'un emploi" << endl << endl << 
	"Votre choix ('q' pour quitter) : ";
	
	onInputPrincipal();

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
    affichage_menu_intermediaire_entreprise();
}

void identification_chomeur()
{

	affichage_menu_intermediaire_chomeur();
}

void identification_employer()
{
	affichage_menu_intermediaire_employer();
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