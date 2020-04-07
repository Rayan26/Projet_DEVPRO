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



using namespace std;


int main()
{
    //TEST FONCTION AFFICHAGE INFORMATION
    vector<string> competence(1,"C++");
    Personne rayan("Kallab","Rayan","kallabr@gmail.com",13011,competence);
    rayan.printInfo();

    //TEST FONCTION AJOUT COMPETENCE
    string java("Java");
    rayan.addCompetence(java);
    rayan.printInfo();

    //TEST CHANGEMENT DE CODE
    int newCode = 13009;
    rayan.setCode(newCode);
    rayan.printInfo();
    
    return 0;
}
