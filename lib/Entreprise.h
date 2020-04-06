#ifndef DEF_ENTREPRISE
#define DEF_ENTREPRISE

#include <iostream>
#include <string>
#include <vector>
#include "Poste.h"
#include "Chomeur.h"


class Entreprise
{
    public:

    Entreprise();
    Entreprise(std::string nom,int code,std::string mail,std::vector<Poste> Jobs);
    Entreprise(Entreprise const &entreprise);
    ~Entreprise();
    
    
    std::string getNom() const;
    std::string getMail() const;
    int getCode() const;
    std::vector<Poste> getJobs() const;
    void addJob(std::string const newjob);
    void deleteJob(Poste poste);
    void printEntreprise() const;
   

    Chomeur searchBySkill(std::vector<std::string> skill);
    Chomeur searchJobByCodeSkill(std::vector<std::string> skill, int code);
    

    private:

    std::string _nom;
    int _code;
    std::string _mail;
    
    std::vector<Poste> _Jobs;
};

#endif
