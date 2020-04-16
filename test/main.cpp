#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>
#include "Personne.h"
#include "Entreprise.h"
#include "Poste.h"
#include "Chomeur.h"
#include "Employer.h"
#include "menu.h"
#include "Parse.h"
#include "Service.h"

using namespace std;

int main()
{
    /*
    //TEST FONCTION AFFICHAGE INFORMATION
    vector<string> competence(1,"C++");
    Personne rayan(1,"Nouveau","Chomeur","kallabr@gmail.com",13011,competence);
    rayan.printInfo();

    //TEST FONCTION AJOUT COMPETENCE
    string java("Java");
    rayan.addCompetence(java);
    rayan.printInfo();

    //TEST CHANGEMENT DE CODE
    int newCode = 13009;
    rayan.setCode(newCode);
    rayan.printInfo();
*/
/*    
    vector<string> competence_julien(1,"Python");
    Chomeur julien(3,"Raige-Verger", "Julien", "julien.raige@gmail.com", "06600", competence_julien);
    julien.printInfo();

    julien.setIdEntreprise(3) ;

    affichage_menu_principal();
*/
    cout << "Génération des personnes sans-emplois ..." << endl
         << endl;
    vector<Chomeur> Chomeurs = Create_Chomeur();
    cout << " " << endl;

    cout << "Génération des employés ..." << endl
         << endl;
    vector<Employer> Employers = Create_Employer();
    cout << " " << endl;

    cout << "Génération des entreprises ..." << endl
         << endl;
    vector<Entreprise> Entreprises = Create_Entreprise();
    cout << " " << endl;

    cout << "Génération des postes à pourvoir ..." << endl
         << endl;
    vector<Poste> Postes = Create_Poste();
    
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
// problème pointeur : marche si on définit entre en objet directement, mais dans ce cas ça ne marche plus pour le NULL (si l'entreprise n'existe pas) -> dilemme cornelien
     Entreprise * entre = get_entreprise(1, Entreprises);
     (*entre).printInfo();
     cout << "ID de entre : " << endl ;
     cout << (*entre).getId() << endl ;

     Entreprise etr = *entre ;
     etr.printInfo();
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
   

/*
     vector <Employer> zboub = get_employers_de_entreprise(1, Employers);
     for(int i = 0 ; i < zboub.size(); i++)
     {
          zboub[i].printInfo();
     }
     cout << "hello world" << endl ;

*/
    return 0;
}
