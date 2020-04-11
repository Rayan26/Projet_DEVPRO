
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



#include "Chomeur.h"
using namespace std; 



vector<Chomeur> Create_Chomeur()
{   
   vector<Chomeur> Chomeurs;
   string info;
   ifstream fichier("CSV/chomeur.csv");
   int i=0; //numero ligne

   if(fichier )
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         int j=0; //numero colonne
         vector<string> competence(1,"C++"); 
         Chomeur new_Chomeur(1,"Nouveau","Chomeur","kallabr@gmail.com",13011,competence);


         while(getline(ss,info,',') && i>0) // i>0 pour sauter la première ligne
        {  
           
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
                  new_Chomeur.setCode(stoi(info));
                  ++j;
                     break;
                  default:
                     break;
               }
               
        }
        new_Chomeur.printInfo();
        ++i;
      }
      
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return Chomeurs;
}

