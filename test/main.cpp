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
#include "ajout.h"

using namespace std;

int main()
{

     //TEST FONCTION AFFICHAGE INFORMATION
     vector<string> competence(1, "C++");
     /*
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

     association_poste_entreprise(Postes, Entreprises);
     association_employer_entreprise(Employers, Entreprises);

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

     //TEST ADDEMPLOYERCSV && TEST COLLEGUE
     // Employer Michel(5, "Michel", "Dumas", "michel@gmail.com", "13011", competence);
     // ajout_employer_entreprise(Michel, 1, Entreprises);
     // vector<Employer> employers_entreprise = get_employers_de_entreprise(1, Employers);
     //affichage_vecteur_employer(employers_entreprise);
     //addEmployerCSV(Michel,Employers);

     //TEST ADDCHOMEURCSV & ADDANCIENCOLLEGUE
     // Chomeur Michel(6,"Michel","Dumas","michel@gmail.com","13011",competence);
     // Michel.addAncienCollegue(2);
     // addChomeur(Michel,Chomeurs);

     // vector<Employer> employers_entreprise = get_employers_de_entreprise(1,Employers);
     // affichage_vecteur_employer(employers_entreprise);
     // addEmployer(Michel,Employers);

     //TEST ADDENTREPRISECSV
     // Entreprise MichelINC(8,"MichelINC","13009","michelinc@gmail.com");
     // addEntreprise(MichelINC,Entreprises);

     // Entreprise MigchelINC(5, "MicghelINC", "13009", "micghelinc@gmail.com");
     // addEntrepriseCSV(MigchelINC, Entreprises);

     //TEST ADDPOSTECSV
     // Poste developer(5,"developer",5);
     // developer.addCompetence("le style avant tout");
     // developer.addCompetence("c++");
     // addPosteCSV(developer,Postes);

     // delEmployerCSV(12);
     // delChomeurCSV(2);
     // delEntrepriseCSV(1);
     // delPosteCSV(0);

     // affichage_vecteur_employer(Employers);
     // delEmployer(Employers, Entreprises, 3);
     // affichage_vecteur_employer(Employers);
     // affichage_vecteur_employer(get_employers(2,Employers)->get_collegues())
     // affichage_vecteur_employer(get_employers(5,Employers)->get_collegues())

     // for (size_t i = 0; i < get_employers(2, Employers)->get_collegues().size(); i++)
     // {
     //      cout << get_employers(2, Employers)->get_collegues()[i] << endl;
     // }

     // Employer *empl = get_employers(5, Employers);
     // vector<int> collegues_inexistants = empl->get_collegues();
     // if(collegues_inexistants[0])
     //      cout<<"problème";
     // for (int i = 0; i < (int)empl->get_collegues().size(); i++)
     // {
     //      // if (empl->get_collegues[i]!=3)
     //      //      cout<< "c bon";
     // }

     // TEST MajObjetCSV()

     // Entreprise MichelINC(8, "MichelINC", "13009", "michelinc@gmail.com");
     // Entreprises.push_back(MichelINC);
     // MajCSVEntreprise(Entreprises);

     // Poste developer(5,"developer",5);
     // developer.addCompetence("le style avant tout");
     // developer.addCompetence("c++");
     // Postes.push_back(developer);
     // MajCSVPoste(Postes);

     // Chomeur Michel(6,"Michel","Dumas","michel@gmail.com","13011",competence);
     // Chomeurs.push_back(Michel);
     // MajCSVChomeur(Chomeurs);

     // Employer Michel(6, "Michel", "Dumas", "michel@gmail.com", "13011", competence);
     //ajout_employer_entreprise(Michel, 1, Entreprises);
     //Employers.push_back(Michel);
     //MajCSVEmployer(Employers);
     // Michel.addCompetence("humour");

     //Employer *empl1 = get_employers(2, Employers);
     // empl1->addCompetence("humour");
     // vector<string> skills = empl1->getSkill();
     // cout << "skills[0] = " << skills[0] << "\n";

     //delEntreprise(Entreprises, Employers, 2);
     //delChomeur(Chomeurs, 5);
     Entreprise *entre2 = get_entreprise(2, Entreprises);
     entre2->printInfo();
     delEmployer(Employers, Entreprises, 1);
     entre2->printInfo();

     //////////////////// TESTER DELPOSTE ///////////////////////////
     // vector<int> jobs = entre2->getJobs();
     //delPoste(Postes, Entreprises, 2);

     return 0;
}
