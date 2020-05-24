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
     vector<Entreprise> Entreprises = Create_Entreprise();
     vector<Employer> Employers = Create_Employer();
     vector<Chomeur> Chomeurs = Create_Chomeur();
     vector<Poste> Postes = Create_Poste();

     //TEST ADDOBJET
     Chomeur chomtest;
     chomtest.setId(55);
     addChomeur(chomtest, Chomeurs, Employers);

     bool isin = false;
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 55)
               isin = true;
     }
     assert(isin);

     isin = false;
     Chomeur chomtest2;
     chomtest2.setId(9); // On teste si il est possible de creer deux personne avec le même id
     chomtest2.setNom("aaaaaa");
     addChomeur(chomtest2, Chomeurs, Employers);
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getNom() == "aaaaaa")
               isin = true;
     }
     assert(!isin);

     delChomeur(Chomeurs, Employers, 55);
     isin = false;
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 55)
               isin = true;
     }
     assert(!isin); // On teste si le chomeur a bien été supprimé

     //TEST CHANGEMENT DE CODE
     Personne rayan;
     string newCode = "13009";
     rayan.setCode(newCode);

     assert(rayan.getCode() == newCode);

     // TEST FONCTION PERSONNE.SETIDENTREPRISE
     Employer julien;
     julien.setIdEntreprise(3);
     assert(julien.getIdEntreprise() == 3);

     Poste dev;
     dev.setIdEntreprise(3);
     assert(dev.getIdEntreprise() == 3);

     //TEST GET_OBJET

     //ENTRE
     Entreprise addentre;
     addentre.setId(1000);

     addEntreprise(addentre, Entreprises);

     Entreprise *entre = get_entreprise(1000, Entreprises);
     assert(entre);
     Entreprise *entre2 = get_entreprise(70, Entreprises);
     assert(entre2 == NULL);

     delEntreprise(Entreprises, Employers, 1000);

     //EMPL
     Employer addempl;
     addempl.setId(1000);

     addEmployer(addempl, Employers, Chomeurs);

     Employer *empl = get_employers(1000, Employers);
     assert(empl);
     Employer *empl2 = get_employers(70, Employers);
     assert(empl2 == NULL);

     delEmployer(Employers, Chomeurs, Entreprises, 1000);

     //CHOM
     Chomeur addchom;
     addchom.setId(1000);
     addChomeur(addchom, Chomeurs, Employers);

     Chomeur *chom = get_chomeur(1000, Chomeurs);
     assert(chom);
     Chomeur *chom2 = get_chomeur(70, Chomeurs);
     assert(chom2 == NULL);

     delChomeur(Chomeurs, Employers, 1000);

     //POST
     Poste addpost;
     addpost.setId(1000);
     addpost.setIdEntreprise(1);
     addPoste(addpost, Postes);

     Poste *poste = get_poste(1000, Postes);
     assert(poste);
     Poste *poste2 = get_poste(70, Postes);
     assert(poste2 == NULL);

     delPoste(Postes,Entreprises,1000);


     // //TEST GET_EMPLOYER_DE_LENTREPRISE
     addentre.addEmploye(3);
     addentre.addEmploye(7);
     addEntreprise(addentre,Entreprises);

     vector<Employer> employer_de_lent = get_employers_de_entreprise(1000, Employers);
     vector<Employer> test;
     test.push_back(*get_employers(3, Employers));
     test.push_back(*get_employers(7, Employers));
     for (size_t i = 0; i < employer_de_lent.size(); i++)
     {
          assert(employer_de_lent[i].getIdPersonne() == test[i].getIdPersonne());
     }

     delEntreprise(Entreprises,Employers,1000);
     addentre.deleteEmploye(3);
     addentre.deleteEmploye(7);
     addEntreprise(addentre,Entreprises);

     vector<Employer> employer_de_lent2 = get_employers_de_entreprise(70, Employers);
     assert(employer_de_lent2.size() == 0);

     delEntreprise(Entreprises,Employers,1000);

     //TEST RECHERCHE_PAR_COMP
     vector<Poste> postes_recherche = recherche_par_comp("C", Postes);
     vector<Poste> test2;
     test2.push_back(*get_poste(2, Postes));
     test2.push_back(*get_poste(5, Postes));
     for (size_t i = 0; i < postes_recherche.size(); i++)
     {
          assert(postes_recherche[i].getId() == test2[i].getId());
     }

     vector<Poste> poste_recherche2 = recherche_par_comp("zz", Postes);
     assert(poste_recherche2.size() == 0);

     //TEST RECHERCHE_PAR_COMP_CP
     vector<Poste> postes_recherche3 = recherche_par_comp_CP("C", "13005", Postes, Entreprises);
     vector<Poste> test3;
     test3.push_back(*get_poste(2, Postes));
     for (size_t i = 0; i < postes_recherche3.size(); i++)
     {
          assert(postes_recherche3[i].getId() == test3[i].getId());
     }

     vector<Poste> poste_recherche4 = recherche_par_comp_CP("C", "12345", Postes, Entreprises);
     assert(poste_recherche4.size() == 0);

     // TEST RECHERCHE_EMPL_PAR_COMP
     vector<Chomeur> chom_recherche = recherche_chomeur_par_comp("gag", Chomeurs);
     vector<Chomeur> test4;
     test4.push_back(*get_chomeur(9, Chomeurs));
     for (size_t i = 0; i < chom_recherche.size(); i++)
     {
          assert(chom_recherche[i].getIdPersonne() == test4[i].getIdPersonne());
     }

     vector<Chomeur> chom_recherche2 = recherche_chomeur_par_comp("zz", Chomeurs);
     assert(chom_recherche2.size() == 0);

     // TEST RECHERCHE_EMPL_PAR_COMP_CP
     vector<Chomeur> chom_recherche3 = recherche_chomeur_par_comp_CP("gag", "13009", Chomeurs);
     vector<Chomeur> test5;
     test5.push_back(*get_chomeur(9, Chomeurs));
     for (size_t i = 0; i < chom_recherche3.size(); i++)
     {
          assert(chom_recherche3[i].getIdPersonne() == test5[i].getIdPersonne());
     }

     vector<Chomeur> chom_recherche4 = recherche_chomeur_par_comp_CP("gag", "12345", Chomeurs);
     assert(chom_recherche4.size() == 0);

     //TEST ADDEMPLOYERCSV && TEST COLLEGUE

     // ajout_employer_entreprise(Michel, 1, Entreprises);
     // vector<Employer> employers_entreprise = get_employers_de_entreprise(1, Employers);
     // affichage_vecteur_employer(employers_entreprise);

     //TEST ADDCHOMEURCSV & ADDANCIENCOLLEGUE
     //Employer Michel(6, "Michel", "Dumas", "michel@gmail.com", "13011", competence);
     // Michel.addAncienCollegue(2);
     // addChomeur(Michel,Chomeurs);

     // vector<Employer> employers_entreprise = get_employers_de_entreprise(1,Employers);
     // affichage_vecteur_employer(employers_entreprise);
     //addEmployer(Michel, Employers, Chomeurs);

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
     // Entreprise *entre2 = get_entreprise(2, Entreprises);
     // entre2->printInfo();
     // delEmployer(Employers, Chomeurs, Entreprises, 1);
     // entre2->printInfo();

     //////////////////// TESTER DELPOSTE ///////////////////////////
     // vector<int> jobs = entre2->getJobs();
     //delPoste(Postes, Entreprises, 2);

     // //TEST RECHERCHE ID DISPO
     // cout<<rechercheIdDispo_Chomeur(Chomeurs)<<endl;
     // cout<<rechercheIdDispo_Employer(Employers)<<endl;
     // cout<<rechercheIdDispo_Entreprise(Entreprises)<<endl;
     // cout<<rechercheIdDispo_Poste(Postes)<<endl;

     //transitionEmployer_Vers_Chomeur(4, Employers, Chomeurs, Entreprises);
     //transitionChomeur_Vers_Employer(4, 2, Employers, Chomeurs, Entreprises);
     // affichage_vecteur_employer(recherche_employer_par_comp("comedie", Employers));
     //affichage_vecteur_employer(recherche_employer_par_comp_CP("comedie", "77700", Employers));

     // affichage_menu_principal();

     return 0;
}
