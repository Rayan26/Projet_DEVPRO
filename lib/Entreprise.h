#ifndef DEF_ENTREPRISE
#define DEF_ENTREPRISE

#include <iostream>
#include <string>
#include <vector>



class Entreprise
{
public:
    Entreprise();
    Entreprise(int ID, std::string nom, std::string code, std::string mail);
    Entreprise(Entreprise const &entreprise);
    ~Entreprise();


    /*
     * Accesseurs des composantes d'entreprises
     */
    int getId() const;
    std::string getNom() const;
    std::string getMail() const;
    std::string getCode() const;
    std::vector<int> getJobs();
    
    /*
     * Modificateurs des composantes d'entreprises
     */
    void setId(int newid);
    void setNom(std::string newnom);
    void setMail(std::string newmail);
    void setCode(std::string newcode);
    
    // Affichage des informations de l'entreprises
    void printInfo() const;
    

    /*
     * Ajout d'un nouveau poste à la listes des postes à pourvoir par l'entreprises,
     * Ajout d'un nouvel employé dans la liste des employés l'entreprises
     */
    void addJob(int Id,std::string const newjob);
    void addEmploye(int Id_employe);

    /*
     * Supression d'un postes dans la listes des postes à pourvoir par l'entreprises,
     * Suppression d'un employé  dans la liste des employés de l'entreprises
     */
    void deleteJob(int idPoste);
    void deleteEmploye(int Id_employe);



private:
    int _id;
    std::string _nom;
    std::string _mail;
    std::string _code;

    std::vector<int> _idJobs;
    std::vector<int> _idEmployer;
};
 

/*
 * Affiche le vecteur de toutes les entreprises créées
 */
void affichage_vecteur_entreprise(std::vector<Entreprise> entre);

#endif
