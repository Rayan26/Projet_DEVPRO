#ifndef DEF_POSTE
#define DEF_POSTE

#include <iostream>
#include <string>
#include <vector>


class Poste
{
    public:

    
    Poste(int id, std::string Titre,std::string entreprise,std::string mail_entreprise,int code);
    ~Poste();
    
    int getId() const;
    std::string getTitre() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    int getCode() const;
    void setId(int newId); 
    void printPoste() const;
   
    private:

    int _id;
    int _code;
    std::string _Titre;
    std::string _Entreprise;
    std::string _Mail_Entreprise;
    int _code_Entreprise; 
    
};

#endif
