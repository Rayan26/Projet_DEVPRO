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

    int getId() const;
    std::string getNom() const;
    std::string getMail() const;
    std::string getCode() const;
    std::vector<int> getJobs();
    void setId(int newid);
    void setNom(std::string newnom);
    void setMail(std::string newmail);
    void setCode(std::string newcode);
    void printInfo() const;
    
    void addJob(int Id,std::string const newjob);
    void deleteJob(int idPoste);

    void addEmploye(int Id_employe);
    void deleteEmploye(int Id_employe);



private:
    int _id;
    std::string _nom;
    std::string _mail;
    std::string _code;

    std::vector<int> _idJobs;
    std::vector<int> _idEmployer;
};

void affichage_vecteur_entreprise(std::vector<Entreprise> entre);

#endif
