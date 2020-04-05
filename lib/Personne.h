#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include <string>
#include <vector>
#define MAX_SKILL 10

class Personne
{
    public:

    Personne();
    Personne(std::string nom,std::string prenom,std::string mail, int code,std::string* skill);
    Personne(Personne const &personne);
    ~Personne();
    
    
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getMail() const;
    int getCode() const;
    std::string* getSkill() const;
    void addCompetence(std::string const newcompetence);
    void printInfo() const;

    private:

    std::string _nom;
    std::string _prenom;
    std::string _mail;
    int _code;
    std::string* _skill;
};

#endif
