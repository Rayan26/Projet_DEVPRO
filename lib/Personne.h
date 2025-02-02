#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include <string>
#include <vector>

#define MAX_SKILL 4

class Personne
{
public:
    Personne();
    Personne(int id, std::string nom, std::string prenom, std::string mail, std::string code, std::vector<std::string> const &skill);
    Personne(Personne const &personne);
    ~Personne();

    /*
     * Accesseurs caracteristiques Personnes 
     */
    int getIdPersonne() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getMail() const;
    std::vector<std::string> getSkill() const;
    std::string getCode() const;
    std::vector<int> get_collegues() const;
    std::vector<int> get_Anciens_collegues() const;

    /*
     * Modificateurs caracteristiques Personnes 
     */
    void setId(int newid);
    void setNom(std::string newnom);
    void setPrenom(std::string newprenom);
    void setMail(std::string newmail);
    void setCode(std::string newcode);

    void addCompetence(std::string newcompetence);
    void addCollegue(int const newcollegue);
    void addAncienCollegue(int const Anciencollegue);

    // Affiche les caractéristique de la personnes
    void printInfo() const;

    /*
     * Modificateurs des vecteurs dans le cas de la suppression d'un autre profil dans la base de donnée
     */
    void erase_collegue(int id);
    void erase_ancien_collegue(int id);

private:
    int _id;
    std::string _nom;
    std::string _prenom;
    std::string _mail;
    std::string _code;
    std::vector<std::string> _skill;
    std::vector<int> _IdCollegue;
    std::vector<int> _IdAncienCollegue;
};

#endif
