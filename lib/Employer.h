#ifndef DEF_EMPLOYER
#define DEF_EMPLOYER

#include <iostream>
#include <string>
#include <vector>

#include <Chomeur.h>
#include <Entreprise.h>
#include <Personne.h>

class Employer: public Personne
{
    public:
    Employer();
    Employer(Personne const &personne, Entreprise entreprise);
    ~Employer();
    Chomeur transition();
    
    private:
    Entreprise _enterprise;
};

#endif
