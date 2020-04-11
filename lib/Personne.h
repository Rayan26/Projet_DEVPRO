#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include <string>
#include <vector>
#include "Entreprise.h"
#include "Poste.h"

#define MAX_SKILL 4

class Personne
{
    public:

    Personne(int id, std::string nom,std::string prenom,std::string mail, int code,std::vector<std::string> const& skill);
    Personne(Personne const &personne);
    ~Personne();
    
    int getIdPersonne() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getMail() const;
    std::vector<std::string> getSkill() const;
    int getCode() const;
    void setId(int newid);
    void setNom(std::string newnom);
    void setPrenom(std::string newprenom);
    void setMail(std::string newmail);
    void setCode(int newcode);
    void addCompetence(std::string const newcompetence);
    void printInfo() const;
    

    

    private:

    int _id;
    std::string _nom;
    std::string _prenom;
    std::string _mail;
    int _code;
    std::vector<std::string> _skill;
};

#endif
