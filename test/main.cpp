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



using namespace std;


int main()
{
/*
    //TEST FONCTION AFFICHAGE INFORMATION
    vector<string> competence(1,"C++");
    Personne rayan("Nouveau","Chomeur","kallabr@gmail.com",13011,competence);
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
    affichage_menu_principal();
    
    return 0;
}
