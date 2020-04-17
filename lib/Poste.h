#ifndef DEF_POSTE
#define DEF_POSTE

#include <iostream>
#include <string>
#include <vector>


class Poste
{
    public:

    Poste(int id, std::string Titre,int idEntreprise);
    ~Poste();
    
    int getId() const;
    std::string getTitre() const;
    int getIdEntreprise() const;
    std::string getMail() const;
    void setId(int newId); 
    void setTitre(std::string newTitre);
    void setIdEntreprise(int newId);
    void addCompetence(std::string newcomp);
    void printInfo() const;
    std::vector<std::string> get_competences()const;
    private:

    int _id;
    std::string _Titre;
    int _idEntreprise; 
    std::vector<std::string> _Competences; 
};

void affichage_vecteur_Poste(std::vector<Poste> empl);
#endif

