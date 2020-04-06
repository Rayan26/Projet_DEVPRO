#ifndef DEF_CHOMEUR
#define DEF_CHOMEUR

#include <iostream>
#include <string>
#include <vector>
#include <Personne.h>
#include <Employer.h>

class Chomeur: public Personne
{
    public:
    Chomeur();
    Chomeur(Personne const &personne);
    ~Chomeur();
    Employer transition();
    
    private:

};

#endif
