#ifndef DEF_POSTE
#define DEF_POSTE

#include <iostream>
#include <string>
#include <vector>

class Poste
{
public:
    Poste();
    Poste(int id, std::string Titre, int idEntreprise);
    Poste(const Poste &poste);
    ~Poste();

    /*
     * Accesseurs des caractéristiques de Poste
     */
    int getId() const;
    std::string getTitre() const;
    int getIdEntreprise() const;
    std::string getMail() const;
    std::vector<std::string> get_competences() const;

    /*
     * Modificateurs caracteristiques Poste
     */
    void setId(int newId);
    void setTitre(std::string newTitre);
    void setIdEntreprise(int newId);
    void addCompetence(std::string newcomp);

    // Affiche les infos de Poste
    void printInfo() const;

private:
    int _id;
    std::string _Titre;
    int _idEntreprise;
    std::vector<std::string> _Competences;
};

/*
 *  Affiche le vecteur de toutes les Postes existant dans la BDD dynamique
 */

#endif
