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
     bool verif_test;
     Log journal(" Début des test");
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

     delPoste(Postes, Entreprises, 1000);

     // //TEST GET_EMPLOYER_DE_LENTREPRISE
     addentre.addEmploye(3);
     addentre.addEmploye(7);
     addEntreprise(addentre, Entreprises);

     vector<Employer> employer_de_lent = get_employers_de_entreprise(1000, Employers);
     vector<Employer> test;
     test.push_back(*get_employers(3, Employers));
     test.push_back(*get_employers(7, Employers));
     for (size_t i = 0; i < employer_de_lent.size(); i++)
     {
          assert(employer_de_lent[i].getIdPersonne() == test[i].getIdPersonne());
     }

     delEntreprise(Entreprises, Employers, 1000);
     addentre.deleteEmploye(3);
     addentre.deleteEmploye(7);
     addEntreprise(addentre, Entreprises);

     vector<Employer> employer_de_lent2 = get_employers_de_entreprise(70, Employers);
     assert(employer_de_lent2.size() == 0);

     delEntreprise(Entreprises, Employers, 1000);

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

     //TEST ADDEMPLOYERCSV (OK)
     // vector<string> skills_michou;
     // skills_michou.push_back("thermodynamique");
     // Employer Michou = new Employer(500, "Dupont", "Michou", "michou.dupont@gmail.com", "13009", skills_michou);
     // addEmployerCSV(Michou, Employers);

     //TEST ADDCHOMEURCSV (OK)
     // Employer Michel(6, "Michel", "Dumas", "michel@gmail.com", "13011", competence);
     // Michel.addAncienCollegue(2);
     // addChomeur(Michel,Chomeurs);

     //TEST ADDENTREPRISECSV (OK)
     // Entreprise MichelINC(8,"MichelINC","13009","michelinc@gmail.com");
     // addEntreprise(MichelINC,Entreprises);

     // Entreprise MigchelINC(5, "MicghelINC", "13009", "micghelinc@gmail.com");
     // addEntrepriseCSV(MigchelINC, Entreprises);

     // TEST ADDPOSTECSV (OK)
     // Poste developer(5,"developer",5);
     // developer.addCompetence("le style avant tout");
     // developer.addCompetence("c++");
     // addPosteCSV(developer,Postes);

     // TEST ADDANCIENCOLLEGUE
     verif_test = false;
     vector<string> empl_10_skills;
     empl_10_skills.push_back("piano");
     Employer *test_empl_10 = new Employer(20, "test20_nom", "test20_prenom", "test20@gmail.com", "13009", empl_10_skills);
     test_empl_10->addAncienCollegue(1);
     vector<int> ancien_collegue_empl_10 = test_empl_10->get_Anciens_collegues();

     assert(ancien_collegue_empl_10.size() != 0);
     for (size_t i = 0; i < ancien_collegue_empl_10.size(); i++)
     {
          if (ancien_collegue_empl_10[i] == 1)
               verif_test = true;
     }
     assert(verif_test == true);

     // TEST DELCSV (OK)
     /* 
     delEmployerCSV(12);
     delChomeurCSV(2);
     delEntrepriseCSV(1);
     delPosteCSV(0);
     */

     // TEST DEL (employés, chomeurs...)
     // Employé
     verif_test = false;
     addEmployer(*test_empl_10, Employers, Chomeurs);
     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == test_empl_10->getIdPersonne())
               verif_test = true;
     }
     assert(verif_test == true);

     delEmployer(Employers, Chomeurs, Entreprises, test_empl_10->getIdPersonne());
     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == test_empl_10->getIdPersonne())
               verif_test = false;
     }
     assert(verif_test == true);

     // Chomeur
     verif_test = false;
     vector<string> chom_10_skills;
     chom_10_skills.push_back("piano");
     Chomeur *test_chom_10 = new Chomeur(20, "testc20_nom", "testc20_prenom", "testc20@gmail.com", "13009", chom_10_skills);
     addChomeur(*test_chom_10, Chomeurs, Employers);

     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == test_chom_10->getIdPersonne())
               verif_test = true;
     }
     assert(verif_test == true);

     delChomeur(Chomeurs, Employers, test_chom_10->getIdPersonne());
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == test_chom_10->getIdPersonne())
               verif_test = false;
     }
     assert(verif_test == true);

     // Entreprise
     verif_test = false;
     Entreprise *test_entre_10 = new Entreprise(20, "test_entre_20", "33033", "entreprise20@gmail.com");
     addEntreprise(*test_entre_10, Entreprises);

     for (size_t i = 0; i < Entreprises.size(); i++)
     {
          if (Entreprises[i].getId() == test_entre_10->getId())
               verif_test = true;
     }
     assert(verif_test == true);

     delEntreprise(Entreprises, Employers, test_entre_10->getId());
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Entreprises[i].getId() == test_entre_10->getId())
               verif_test = false;
     }
     assert(verif_test == true);

     // Poste
     verif_test = false;
     Poste *test_poste_10 = new Poste(20, "musicien", 2);
     addPoste(*test_poste_10, Postes);

     for (size_t i = 0; i < Postes.size(); i++)
     {
          if (Postes[i].getId() == test_poste_10->getId())
               verif_test = true;
     }
     assert(verif_test == true);

     delPoste(Postes, Entreprises, test_poste_10->getId());
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Postes[i].getId() == test_poste_10->getId())
               verif_test = false;
     }
     assert(verif_test == true);

     // TEST MajObjetCSV() (OK)
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

     // TEST ADDCOMPETENCE
     verif_test = false;
     vector<string> empl_11_skills;
     empl_11_skills.push_back("piano");
     Employer *test_empl_11 = new Employer(20, "test11_nom", "test11_prenom", "test11@gmail.com", "13009", empl_11_skills);
     for (size_t i = 0; i < (test_empl_11->getSkill()).size(); i++)
     {
          if (test_empl_11->getSkill()[i] == "saxophone")
               verif_test = true;
     }
     assert(verif_test == false);

     test_empl_11->addCompetence("saxophone");
     for (size_t i = 0; i < (test_empl_11->getSkill()).size(); i++)
     {
          if (test_empl_11->getSkill()[i] == "saxophone")
               verif_test = true;
     }
     assert(verif_test == true);

     // TEST RECHERCHE ID DISPO
     // Personne
     verif_test = false;
     int id_chom = rechercheIdDispo_Personne(Employers, Chomeurs);
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == id_chom)
               verif_test = true;
     }
     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == id_chom)
               verif_test = true;
     }
     assert(verif_test == false);

     // Entreprise
     int id_entre = rechercheIdDispo_Entreprise(Entreprises);
     for (size_t i = 0; i < Entreprises.size(); i++)
     {
          if (Entreprises[i].getId() == id_entre)
               verif_test = true;
     }
     assert(verif_test == false);

     // Postes
     int id_poste = rechercheIdDispo_Poste(Postes);
     for (size_t i = 0; i < Postes.size(); i++)
     {
          if (Postes[i].getId() == id_poste)
               verif_test = true;
     }
     assert(verif_test == false);

     // TEST TRANSITIONS
     // E -> C
     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == 4)
               verif_test = true;
     }
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 4)
               verif_test = false;
     }
     assert(verif_test == true);

     transitionEmployer_Vers_Chomeur(4, Employers, Chomeurs, Entreprises);

     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == 4)
               verif_test = true;
     }
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 4)
               verif_test = false;
     }
     assert(verif_test == false);

     // C -> E
     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == 4)
               verif_test = true;
     }
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 4)
               verif_test = false;
     }
     assert(verif_test == false);

     transitionChomeur_Vers_Employer(4, 2, Employers, Chomeurs, Entreprises);

     for (size_t i = 0; i < Employers.size(); i++)
     {
          if (Employers[i].getIdPersonne() == 4)
               verif_test = true;
     }
     for (size_t i = 0; i < Chomeurs.size(); i++)
     {
          if (Chomeurs[i].getIdPersonne() == 4)
               verif_test = false;
     }
     assert(verif_test == true);

     //affichage_menu_principal();

     journal.msg("Aucun problème tous les test passent");
     return 0;
}
