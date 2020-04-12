#ifndef DEF_EMPLOYER
#define DEF_EMPLOYER

#include <iostream>
#include <string>
#include <vector>


#include "Personne.h"

class Employer : public Personne
{
    public:
    
    Employer(int id, std::string nom, std::string prenom, std::string mail, int code, std::vector<std::string> const& skill);
    int getIdEntreprise() const;
    void setIdEntreprise(int newid);
    void printEmployeur() const;


    private:
    int _idEntreprise;
};

#endif
