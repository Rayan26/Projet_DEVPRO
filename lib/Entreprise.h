#ifndef DEF_ENTREPRISE
#define DEF_ENTREPRISE

#include <iostream>
#include <string>
#include <vector>
#include "Poste.h"

class Entreprise
{
public:
    Entreprise(int ID, std::string nom, int code, std::string mail);
    Entreprise(Entreprise const &entreprise);
    ~Entreprise();

    int getId() const;
    std::string getNom() const;
    std::string getMail() const;
    int getCode() const;
    std::vector<Poste> getJobs();
    void setId(int newid);
    void setNom(std::string newnom);
    void setMail(std::string newmail);
    void setCode(int newcode);
    void printInfo() const;

    void addJob(int Id,std::string const newjob);
    void deleteJob(Poste poste);
    void addEmploye(int Id_employe);
    void deleteEmploye(int Id_employe);

private:
    int _id;
    std::string _nom;
    std::string _mail;
    int _code;

    std::vector<Poste> _Jobs;
    std::vector<int> _idEmployer;
};

#endif
