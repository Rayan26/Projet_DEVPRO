
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
   int i=0; //on saute la première ligne

   if(fichier )
   {  
      
      string ligne; 

      while(getline(fichier, ligne)) 
      {  
         stringstream ss(ligne);
         while(getline(ss,info,',') && i>0)
        {
            cout << info << endl;
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

