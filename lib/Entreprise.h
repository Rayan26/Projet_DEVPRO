#ifndef DEF_ENTREPRISE
#define DEF_ENTREPRISE

#include <iostream>
#include <string>
#include <vector>
#include "Poste.h"



class Entreprise
{
    public:

    Entreprise();
    Entreprise(int id,std::string nom,int code,std::string mail,std::vector<Poste> Jobs);
    Entreprise(Entreprise const &entreprise);
    ~Entreprise();
    
    int getId() const;
    std::string getNom() const;
    std::string getMail() const;
    int getCode() const;
    std::vector<Poste> getJobs();
    void addJob(std::string const newjob);
    void deleteJob(Poste poste);
    void printEntreprise() const;
   

    

    private:

    std::string _nom;
    int _code;
    std::string _mail;
    
    std::vector<Poste> _Jobs;
};

#endif
