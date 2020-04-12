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
    
    vector<string> competence_julien(1,"Python");
    Chomeur julien("Raige-Verger", "Julien", "julien.raige@gmail.com", 06600, competence_julien);
    julien.printInfo();
*/  
   // affichage_menu_principal();

   
    cout << "Génération des personnes sans-emplois ..." << endl << endl;
    vector<Chomeur> Chomeurs = Create_Chomeur(); 
    cout << " " << endl;

    cout << "Génération des employés ..." << endl << endl;
    vector<Employer> Employers = Create_Employer();  
    cout << " " << endl;
    return 0;
}
