
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
   int i=0; //numero ligne

   if(fichier)
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         
         string info;
         int j=0; //numero colonne
         vector<string> competence(0); 
         Chomeur new_Chomeur(1," "," "," "," ",competence);


         while(getline(ss,info,',') && i>0) // i>0 pour sauter la première ligne
        {  
           stringstream zz(info);
           string comp;
            switch ( j )
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
                  while(getline(zz,comp,';')) 
                  {  
                     new_Chomeur.addCompetence(comp);
                  }
                  ++j;
                     break;
                  case 6:
                  while(getline(zz,comp,';')) 
                  {  
                     new_Chomeur.addCollegue(stoi(info));
                  }
                  ++j;
                     break;
                  default:
                     break;
               }
               
        }

         if( i != 0 )
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
   int i=0; //numero ligne

   if(fichier)
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         
         string info;
         int j=0; //numero colonne
         vector<string> competence(0); 
         Employer new_Employer(1," "," "," "," ",competence);


         while(getline(ss,info,',') && i>0) // i>0 pour sauter la première ligne
        {  
           stringstream zz(info);
           string comp;
            switch ( j )
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
                  while(getline(zz,comp,';')) 
                  {  
                     new_Employer.addCompetence(comp);
                  }
                  ++j;
                     break;
                  case 6:
                  while(getline(zz,comp,';')) 
                  {  
                     new_Employer.addCollegue(stoi(comp));
                  }
                  ++j;
                     break;
                  case 7:
                  new_Employer.setIdEntreprise(stoi(info));
                  ++j;
                     break;
                  default:
                     break;
               }
               
        }

        if( i != 0 )
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
   int i=0; //numero ligne

   if(fichier)
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         
         string info;
         int j=0; //numero colonne
         Entreprise new_Entreprise(1," "," "," ");


         while(getline(ss,info,',') && i>0) // i>0 pour sauter la première ligne
        {  
           
            switch ( j )
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

        if( i != 0 )
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
   int i=0; //numero ligne

   if(fichier)
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         
         string info;
         int j=0; //numero colonne
         Poste new_Poste(1," ",0);


         while(getline(ss,info,',') && i>0) // i>0 pour sauter la première ligne
        {  
            stringstream zz(info);
            string comp;
            switch ( j )
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
                 while(getline(zz,comp,';')) 
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

        if( i != 0 )
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
   for (int i = 0; i < (int)employers.size(); i++)
   {
     if(empl.getIdPersonne() == employers[i].getIdPersonne())
     {
         cout << "ID existe déjas dans la base de donnée" << endl;
         return; 
     }
   }

   for (int i = 0; i < (int)employers.size(); i++)
   {
     if(empl.getNom() == employers[i].getNom() && empl.getPrenom() == employers[i].getPrenom())
     {
         cout << "Employer existe déjas dans la base de donnée" << endl;
         return; 
     }
   }

   ofstream fichier("CSV/employer.csv",ios::app);
   if(fichier)
   {  
      fichier << "\n" << empl.getIdPersonne() << ',' << empl.getNom() << ',' << empl.getPrenom() << ',' << empl.getMail() << ',' << empl.getCode() << ',' ;

      vector <string> skills = empl.getSkill();
      fichier << skills[0];
      for(size_t i = 1 ; i<skills.size(); i++)
      {
         fichier << ';' << skills[i];
      }

      fichier << ',' ;


      int entre = empl.getIdEntreprise();
      vector <Employer> employers_entreprise = get_employers_de_entreprise(entre,employers);
      if(employers_entreprise[0].getIdPersonne() != empl.getIdPersonne())
      {
         fichier << employers_entreprise[0].getIdPersonne();
      }
      for(size_t i = 1 ; i<employers_entreprise.size(); i++)
      {
         if(employers_entreprise[i].getIdPersonne() != empl.getIdPersonne())
         {
            fichier << ';' << employers_entreprise[i].getIdPersonne() ;
         }
      }
      fichier << ',';

      fichier << entre ;
   }

   employers.push_back(empl);
}

void addEntrepriseCSV(Entreprise entre)
{

}

