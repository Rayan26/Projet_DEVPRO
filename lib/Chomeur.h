#ifndef DEF_CHOMEUR
#define DEF_CHOMEUR

#include <iostream>
#include <string>
#include <vector>
#include "Employer.h"

#include "Personne.h"



class Chomeur : public Personne
{
    public:
    
    Chomeur(std::string nom, std::string prenom, std::string mail, int code, std::vector<std::string> const& skill);

    ~Chomeur();
    
    private:

};

#endif
