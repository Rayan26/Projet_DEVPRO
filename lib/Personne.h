#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include <string>
#include <vector>

class Personne
{
    public:

    Personne() : _skill(5) {};
    Personne(std::string nom,std::string prenom,std::string mail, int code, std::vector<std::string>& skill);
    Personne(Personne const &personne);
    ~Personne();
    
   
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getMail() const;
    int getCode() const;
    std::vector<std::string> getSkill() const;
    void addCompetence(std::string const newcompetence);

    private:

    std::string _nom;
    std::string _prenom;
    std::string _mail;
    int _code;
    std::vector<std::string> _skill;
};

#endif
