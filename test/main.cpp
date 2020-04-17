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

     cout << "fin de déclaration" << endl;

     //TEST GET_ENTREPRISE
     // Entreprise *entre = get_entreprise(5, Entreprises);
     // if (entre)
     //      entre->printInfo();
     // else
     // {
     //      cout<<"Aie";
     //      return 0;
     // }

     // //TEST GET_EMPLOYER_DE_LENTREPRISE
     // vector<Employer> employer_de_lent = get_employers_de_entreprise(1, Employers);
     // affichage_vecteur_employer(employer_de_lent);

     //TEST GET_EMPLOYER
     // Employer *empl = get_employers(5 ,Employers);
     //  if (empl)
     //      empl->printInfo();
     // else
     // {
     //      cout<<"Aie ça existe ap" <<endl ;
     //      return 0;
     // }

     //TEST GET CHOMEUR
     // Chomeur *chom = get_chomeur(2 ,Chomeurs);
     //  if (chom)
     //      chom->printInfo();
     // else
     // {
     //      cout<<"Aie ça existe ap" <<endl ;
     //      return 0;
     // }

     // //TEST GET_POSTE
     //      Poste *post = get_poste(5 ,Postes);
     //       if (post)
     //           post->printInfo();
     //      else
     //      {
     //           cout<<"Aie ça existe ap" <<endl ;
     //           return 0;
     //      }


     //TEST RECHERCHEPAR_COMP
     // vector<Poste> postes_recherche = recherche_par_comp("C",Postes);
     // affichage_vecteur_Poste(postes_recherche);

     // //TEST RECHERCHE_COMP_CP
     // vector<Poste> postes_recherche = recherche_par_comp_CP("C","75009",Postes,Entreprises);
     // affichage_vecteur_Poste(postes_recherche);

     return 0;
}
