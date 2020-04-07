#ifndef DEF_POSTE
#define DEF_POSTE

#include <iostream>
#include <string>
#include <vector>


class Poste
{
    public:

    Poste();
    Poste(std::string nom,std::string entreprise,std::string mail_entreprise,int code);
    ~Poste();
    
    
    std::string getTitre() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    int getCode() const;
    void printPoste() const;
   
    private:

    std::string _Titre;
    std::string _Entreprise;
    std::string _Mail_Entreprise;
    int _code_Entreprise; 
    
};

#endif
