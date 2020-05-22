
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
                  try
                  {
                     new_Chomeur.addCompetence(comp);
                  }
                  catch (logic_error &)
                  {
                  }
               }
               ++j;
               break;
            case 6:
               while (getline(zz, comp, ';'))
               {
                  try
                  {
                     new_Chomeur.addAncienCollegue(stoi(comp));
                  }
                  catch (logic_error &)
                  {
                  }
               }
               ++j;
               break;
            default:
               break;
            }
         }

         if (i != 0)
         {

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
                  try
                  {
                     new_Employer.addCollegue(stoi(comp));
                  }
                  catch (logic_error &)
                  {
                  }
               }
               ++j;
               break;
            case 7:
               while (getline(zz, comp, ';'))
               {
                  try
                  {
                     new_Employer.addAncienCollegue(stoi(comp));
                  }
                  catch (logic_error &)
                  {
                  }
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

void association_poste_entreprise(vector<Poste> &postes, vector<Entreprise> &entreprises)
{
   for (size_t i = 0; i < postes.size(); i++)
   {
      Entreprise *entre;
      entre = get_entreprise(postes[i].getIdEntreprise(), entreprises);
      entre->addJob(postes[i].getId());
   }
}

void association_employer_entreprise(vector<Employer> &employers, vector<Entreprise> &entreprises)
{
   for (size_t i = 0; i < employers.size(); i++)
   {
      Entreprise *entre;
      entre = get_entreprise(employers[i].getIdEntreprise(), entreprises);
      entre->addEmploye(employers[i].getIdPersonne());
   }
}

void addEmployerCSV(const Employer &empl, vector<Employer> &employers)
{

   ofstream fichier("CSV/employer.csv", ios::app);
   if (fichier)
   {
      fichier << "\n"
              << empl.getIdPersonne() << ',' << empl.getNom() << ',' << empl.getPrenom() << ',' << empl.getMail() << ',' << empl.getCode() << ',';

      vector<string> skills;

      skills = empl.getSkill();

      if (skills.size() != 0)
      {

         fichier << skills[0];
         for (size_t i = 1; i < skills.size(); i++)
         {
            fichier << ';' << skills[i];
         }
      }

      fichier << ",";

      vector<int> collegue = empl.get_collegues();

      if ((collegue.size() > 0))
      {
         if (collegue[0] != empl.getIdPersonne())
         {
            fichier << collegue[0];
         }
         for (size_t i = 1; i < collegue.size(); i++)
         {
            if (collegue[i] != empl.getIdPersonne())
            {
               fichier << ';' << collegue[i];
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
      
      fichier << ',' << empl.getIdEntreprise();
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
      if (skills.size() != 0)
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
