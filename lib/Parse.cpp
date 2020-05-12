
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Parse.h"
#include "Service.h"
using namespace std;

vector<Chomeur> Create_Chomeur()
{
   vector<Chomeur> Chomeurs;

   ifstream fichier("CSV/chomeur.csv");
   int i = 0; //numero ligne

   if (fichier)
   {

      string ligne;

      while (getline(fichier, ligne))
      {
         stringstream ss(ligne);

         string info;
         int j = 0; //numero colonne
         vector<string> competence(0);
         Chomeur new_Chomeur(1, " ", " ", " ", " ", competence);

         while (getline(ss, info, ',') && i > 0) // i>0 pour sauter la première ligne
         {
            stringstream zz(info);
            string comp;
            switch (j)
            {
            case 0:
               new_Chomeur.setId(stoi(info));
               ++j;
               break;
            case 1:
               new_Chomeur.setNom(info);
               ++j;
               break;
            case 2:
               new_Chomeur.setPrenom(info);
               ++j;
               break;
            case 3:
               new_Chomeur.setMail(info);
               ++j;
               break;
            case 4:
               new_Chomeur.setCode(info);
               ++j;
               break;
            case 5:
               while (getline(zz, comp, ';'))
               {
                  new_Chomeur.addCompetence(comp);
               }
               ++j;
               break;
            case 6:
               while (getline(zz, comp, ';'))
               {
                  new_Chomeur.addAncienCollegue(stoi(info));
               }
               ++j;
               break;
            default:
               break;
            }
         }

         if (i != 0)
         {
            //   new_Chomeur.printInfo();
            Chomeurs.push_back(new_Chomeur);
         }
         ++i;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return Chomeurs;
}

vector<Employer> Create_Employer()
{
   vector<Employer> Employers;

   ifstream fichier("CSV/employer.csv");
   int i = 0; //numero ligne

   if (fichier)
   {

      string ligne;

      while (getline(fichier, ligne))
      {
         stringstream ss(ligne);

         string info;
         int j = 0; //numero colonne
         vector<string> competence(0);
         Employer new_Employer(1, " ", " ", " ", " ", competence);

         while (getline(ss, info, ',') && i > 0) // i>0 pour sauter la première ligne
         {
            stringstream zz(info);
            string comp;
            switch (j)
            {
            case 0:
               new_Employer.setId(stoi(info));
               ++j;
               break;
            case 1:
               new_Employer.setNom(info);
               ++j;
               break;
            case 2:
               new_Employer.setPrenom(info);
               ++j;
               break;
            case 3:
               new_Employer.setMail(info);
               ++j;
               break;
            case 4:
               new_Employer.setCode(info);
               ++j;
               break;
            case 5:
               while (getline(zz, comp, ';'))
               {
                  new_Employer.addCompetence(comp);
               }
               ++j;
               break;
            case 6:
               while (getline(zz, comp, ';'))
               {
                  new_Employer.addCollegue(stoi(comp));
               }
               ++j;
               break;
            case 7:
               while (getline(zz, comp, ';'))
               {
                  new_Employer.addAncienCollegue(stoi(comp));
               }
               ++j;
               break;
            case 8:
               new_Employer.setIdEntreprise(stoi(info));
               ++j;
               break;
            default:
               break;
            }
         }

         if (i != 0)
         {
            //   new_Employer.printInfo();
            //   new_Employer.printEmployeur();
            Employers.push_back(new_Employer);
         }

         ++i;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return Employers;
}

vector<Entreprise> Create_Entreprise()
{
   vector<Entreprise> Entreprises;

   ifstream fichier("CSV/entreprise.csv");
   int i = 0; //numero ligne

   if (fichier)
   {

      string ligne;

      while (getline(fichier, ligne))
      {
         stringstream ss(ligne);

         string info;
         int j = 0; //numero colonne
         Entreprise new_Entreprise(1, " ", " ", " ");

         while (getline(ss, info, ',') && i > 0) // i>0 pour sauter la première ligne
         {

            switch (j)
            {
            case 0:
               new_Entreprise.setId(stoi(info));
               ++j;
               break;
            case 1:
               new_Entreprise.setNom(info);
               ++j;
               break;
            case 2:
               new_Entreprise.setCode(info);
               ++j;
               break;
            case 3:
               new_Entreprise.setMail(info);
               ++j;
               break;

            default:
               break;
            }
         }

         if (i != 0)
         {
            //   new_Entreprise.printInfo();
            Entreprises.push_back(new_Entreprise);
         }

         ++i;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return Entreprises;
}

vector<Poste> Create_Poste()
{
   vector<Poste> Postes;

   ifstream fichier("CSV/poste.csv");
   int i = 0; //numero ligne

   if (fichier)
   {

      string ligne;

      while (getline(fichier, ligne))
      {
         stringstream ss(ligne);

         string info;
         int j = 0; //numero colonne
         Poste new_Poste(1, " ", 0);

         while (getline(ss, info, ',') && i > 0) // i>0 pour sauter la première ligne
         {
            stringstream zz(info);
            string comp;
            switch (j)
            {
            case 0:
               new_Poste.setId(stoi(info));
               ++j;
               break;
            case 1:
               new_Poste.setTitre(info);
               ++j;
               break;
            case 2:
               while (getline(zz, comp, ';'))
               {
                  new_Poste.addCompetence(comp);
               }
               ++j;
               break;
            case 3:
               new_Poste.setIdEntreprise(stoi(info));
               ++j;
               break;

            default:
               break;
            }
         }

         if (i != 0)
         {
            //   new_Poste.printInfo();
            Postes.push_back(new_Poste);
         }

         ++i;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return Postes;
}

void addEmployerCSV(const Employer &empl, vector<Employer> &employers)
{

   ofstream fichier("CSV/employer.csv", ios::app);
   if (fichier)
   {
      fichier << "\n"
              << empl.getIdPersonne() << ',' << empl.getNom() << ',' << empl.getPrenom() << ',' << empl.getMail() << ',' << empl.getCode() << ',';

      vector<string> skills = empl.getSkill();
      if (skills.size()!=0)
      {

         fichier << skills[0];
         for (size_t i = 1; i < skills.size(); i++)
         {
            fichier << ';' << skills[i];
         }
      }
      int entre = empl.getIdEntreprise();
      vector<Employer> employers_entreprise = get_employers_de_entreprise(entre, employers);

      if ((employers_entreprise.size() > 0))
      {
         if (employers_entreprise[0].getIdPersonne() != empl.getIdPersonne())
         {
            fichier << employers_entreprise[0].getIdPersonne();
         }
         for (size_t i = 1; i < employers_entreprise.size(); i++)
         {
            if (employers_entreprise[i].getIdPersonne() != empl.getIdPersonne())
            {
               fichier << ';' << employers_entreprise[i].getIdPersonne();
            }
         }
      }

      fichier << ',';
      if ((empl.get_Anciens_collegues().size() > 0))
      {
         if (empl.get_Anciens_collegues()[0] != empl.getIdPersonne())
         {
            fichier << empl.get_Anciens_collegues()[0];
         }
         for (size_t i = 1; i < (empl.get_Anciens_collegues()).size(); i++)
         {
            if (empl.get_Anciens_collegues()[i] != empl.getIdPersonne())
            {
               fichier << ';' << empl.get_Anciens_collegues()[i];
            }
         }
      }

      fichier << ',' << entre;
   }
}

void addChomeurCSV(const Chomeur &chom, vector<Chomeur> &chomeurs)
{

   ofstream fichier("CSV/chomeur.csv", ios::app);
   if (fichier)
   {
      fichier << "\n"
              << chom.getIdPersonne() << ',' << chom.getNom() << ',' << chom.getPrenom() << ',' << chom.getMail() << ',' << chom.getCode() << ',';

      vector<string> skills = chom.getSkill();
      if (skills.size()!=0)
      {

         fichier << skills[0];
         for (size_t i = 1; i < skills.size(); i++)
         {
            fichier << ';' << skills[i];
         }
      }

      fichier << ',';

      if ((chom.get_Anciens_collegues().size() > 0))
      {

         if (chom.get_Anciens_collegues()[0] != chom.getIdPersonne())
         {
            fichier << chom.get_Anciens_collegues()[0];
         }
         for (size_t i = 1; i < (chom.get_Anciens_collegues()).size(); i++)
         {
            if (chom.get_Anciens_collegues()[i] != chom.getIdPersonne())
            {
               fichier << ';' << chom.get_Anciens_collegues()[i];
            }
         }
      }
   }
}

void addEntrepriseCSV(const Entreprise &entre, std::vector<Entreprise> &entreprises)
{

   ofstream fichier("CSV/entreprise.csv", ios::app);
   if (fichier)
   {
      fichier << "\n"
              << entre.getId() << ',' << entre.getNom() << ',' << entre.getCode() << ',' << entre.getMail();
   }
}

void addPosteCSV(const Poste &post, std::vector<Poste> &postes)
{

   ofstream fichier("CSV/poste.csv", ios::app);
   if (fichier)
   {
      fichier << "\n"
              << post.getId() << ',' << post.getTitre() << ',';

      vector<string> skills = post.get_competences();
      fichier << skills[0];
      for (size_t i = 1; i < skills.size(); i++)
      {
         fichier << ';' << skills[i];
      }

      fichier << ',';
      fichier << post.getIdEntreprise();
   }
}

void delEmployerCSV(int ID)
{
   fstream fichier("CSV/employer.csv");
   if (fichier)
   {
      string ligne;
      int x = 0;
      int i = 1;
      int j;
      getline(fichier, ligne);
      do
      {
         fichier >> j;
         i++;
         if (j == ID)
         {
            cout << "Employé trouvé \n";
            break;
         }
      } while (getline(fichier, ligne) && i > 0);

      //suppression ligne
      fichier.seekg(0, ios::beg);
      ofstream temp("./CSV/temp.csv"); // temp file for input of every student except the one user wants to delete

      int z = 0;
      while (getline(fichier, ligne))
      {
         z++;
         if (z != i)
         {
            temp << ligne << endl;
         }
         else
         {
            x = 1;
         }
      }

      if (x == 0)
      { // x était défini à 0 au début, donc si ça n'a pas changé, il n'y a eu aucune modif
         cout << "Il n'y a pas d'employé avec cette ID" << endl;
      }
      else
      {                   // x n'est pas égal à 0, donc ça a bien changé
         fichier.clear(); // clear eof and fail bits
         fichier.seekg(0, ios::beg);
         fichier.close();
         temp.close();
         remove("./CSV/employer.csv");
         rename("./CSV/temp.csv", "./CSV/employer.csv");
         cout << "Les infos de l'employé ont été supprimées" << endl;
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void delEntrepriseCSV(int ID)
{
   fstream fichier("CSV/entreprise.csv");
   if (fichier)
   {
      string ligne;
      int x = 0;
      int i = 1;
      int j;
      getline(fichier, ligne);
      do
      {
         fichier >> j;
         cout << "j = " << j << "\n";
         i++;
         if (j == ID)
         {
            cout << "Entreprise trouvée \n";
            break;
         }
      } while (getline(fichier, ligne) && i > 0);

      //suppression ligne
      fichier.seekg(0, ios::beg);
      ofstream temp("./CSV/temp.csv"); // temp file for input of every student except the one user wants to delete

      int z = 0;
      while (getline(fichier, ligne))
      {
         z++;
         if (z != i)
         {
            temp << ligne << endl;
         }
         else
         {
            x = 1;
         }
      }

      if (x == 0)
      { // x était défini à 0 au début, donc si ça n'a pas changé, il n'y a eu aucune modif
         cout << "Il n'y a pas d'entreprise avec cette ID" << endl;
      }
      else
      {                   // x n'est pas égal à 0, donc ça a bien changé
         fichier.clear(); // clear eof and fail bits
         fichier.seekg(0, ios::beg);
         fichier.close();
         temp.close();
         remove("./CSV/entreprise.csv");
         rename("./CSV/temp.csv", "./CSV/entreprise.csv");
         cout << "Les infos de l'entreprise ont été supprimées" << endl;
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void delChomeurCSV(int ID)
{
   fstream fichier("CSV/chomeur.csv");
   if (fichier)
   {
      string ligne;
      int x = 0;
      int i = 1;
      int j;
      getline(fichier, ligne);
      do
      {
         fichier >> j;
         cout << "j = " << j << "\n";
         i++;
         if (j == ID)
         {
            cout << "Chomeur trouvé \n";
            break;
         }
      } while (getline(fichier, ligne) && i > 0);

      //suppression ligne
      fichier.seekg(0, ios::beg);
      ofstream temp("./CSV/temp.csv"); // temp file for input of every student except the one user wants to delete

      int z = 0;
      while (getline(fichier, ligne))
      {
         z++;
         if (z != i)
         {
            temp << ligne << endl;
         }
         else
         {
            x = 1;
         }
      }

      if (x == 0)
      { // x était défini à 0 au début, donc si ça n'a pas changé, il n'y a eu aucune modif
         cout << "Il n'y a pas de chomeur avec cette ID" << endl;
      }
      else
      {                   // x n'est pas égal à 0, donc ça a bien changé
         fichier.clear(); // clear eof and fail bits
         fichier.seekg(0, ios::beg);
         fichier.close();
         temp.close();
         remove("./CSV/chomeur.csv");
         rename("./CSV/temp.csv", "./CSV/chomeur.csv");
         cout << "Les infos du chomeur ont été supprimées" << endl;
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void delPosteCSV(int ID)
{
   fstream fichier("CSV/poste.csv");
   if (fichier)
   {
      string ligne;
      int x = 0;
      int i = 1;
      int j;
      getline(fichier, ligne);
      do
      {
         fichier >> j;
         cout << "j = " << j << "\n";
         i++;
         if (j == ID)
         {
            cout << "Poste trouvé \n";
            break;
         }
      } while (getline(fichier, ligne) && i > 0);

      //suppression ligne
      fichier.seekg(0, ios::beg);
      ofstream temp("./CSV/temp.csv"); // temp file for input of every student except the one user wants to delete

      int z = 0;
      while (getline(fichier, ligne))
      {
         z++;
         if (z != i)
         {
            temp << ligne << endl;
         }
         else
         {
            x = 1;
         }
      }

      if (x == 0)
      { // x était défini à 0 au début, donc si ça n'a pas changé, il n'y a eu aucune modif
         cout << "Il n'y a pas de poste avec cette ID" << endl;
      }
      else
      {                   // x n'est pas égal à 0, donc ça a bien changé
         fichier.clear(); // clear eof and fail bits
         fichier.seekg(0, ios::beg);
         fichier.close();
         temp.close();
         remove("./CSV/poste.csv");
         rename("./CSV/temp.csv", "./CSV/poste.csv");
         cout << "Les infos du poste ont été supprimées" << endl;
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void MajCSVEmployer(std::vector<Employer> &employers)
{
   fstream fichier("CSV/employer.csv");
   if (fichier)
   {
      ofstream temp("./CSV/temp.csv");
      string premiere_ligne;
      getline(fichier, premiere_ligne);

      temp << premiere_ligne;

      temp.seekp(0, ios::beg);
      fichier.close();
      temp.close();

      remove("./CSV/employer.csv");
      rename("./CSV/temp.csv", "./CSV/employer.csv");

      for (size_t i = 0; i < employers.size(); i++)
      {
         addEmployerCSV(employers[i], employers);
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void MajCSVEntreprise(std::vector<Entreprise> &entreprises)
{
   fstream fichier("CSV/entreprise.csv");
   if (fichier)
   {
      ofstream temp("./CSV/temp.csv");
      string premiere_ligne;
      getline(fichier, premiere_ligne);

      temp << premiere_ligne;

      temp.seekp(0, ios::beg);
      fichier.close();
      temp.close();

      remove("./CSV/entreprise.csv");
      rename("./CSV/temp.csv", "./CSV/entreprise.csv");

      for (size_t i = 0; i < entreprises.size(); i++)
      {
         addEntrepriseCSV(entreprises[i], entreprises);
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void MajCSVChomeur(std::vector<Chomeur> &chomeurs)
{
   fstream fichier("CSV/chomeur.csv");
   if (fichier)
   {
      ofstream temp("./CSV/temp.csv");
      string premiere_ligne;
      getline(fichier, premiere_ligne);

      temp << premiere_ligne;

      temp.seekp(0, ios::beg);
      fichier.close();
      temp.close();

      remove("./CSV/chomeur.csv");
      rename("./CSV/temp.csv", "./CSV/chomeur.csv");

      for (size_t i = 0; i < chomeurs.size(); i++)
      {
         addChomeurCSV(chomeurs[i], chomeurs);
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}

void MajCSVPoste(std::vector<Poste> &postes)
{
   fstream fichier("CSV/poste.csv");
   if (fichier)
   {
      ofstream temp("./CSV/temp.csv");
      string premiere_ligne;
      getline(fichier, premiere_ligne);

      temp << premiere_ligne;

      temp.seekp(0, ios::beg);
      fichier.close();
      temp.close();

      remove("./CSV/poste.csv");
      rename("./CSV/temp.csv", "./CSV/poste.csv");

      for (size_t i = 0; i < postes.size(); i++)
      {
         addPosteCSV(postes[i], postes);
      }
   }
   else
   {
      cout << "Erreur impossible d'ouvrir le fichier \n";
   }
}