#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include <string>


class Personne
{
    public:

    Personne();
    Personne(std::string nom,std::string prenom,std::string mail, int code, std::vector<string>& skill);
    Personne(Personne const &personne);
    ~Personne();
    
    string getNom() const;
    string getPrenom() const;
    string getMail() const;
    int getCode() const;
    vector<string> getSkill() const
    
    private:

    string nom;
    string prenom;
    string mail;
    int code
    vector<string> skill(5);
};

#endif
