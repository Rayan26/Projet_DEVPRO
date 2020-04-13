#ifndef DEF_ENTREPRISE
#define DEF_ENTREPRISE

#include <iostream>
#include <string>
#include <vector>



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
    std::vector<int> getJobs();
    void setId(int newid);
    void setNom(std::string newnom);
    void setMail(std::string newmail);
    void setCode(int newcode);
    void printInfo() const;

    void addJob(int Id,std::string const newjob);
    void deleteJob(int idPoste);
    void addEmploye(int Id_employe);
    void deleteEmploye(int Id_employe);

private:
    int _id;
    std::string _nom;
    std::string _mail;
    int _code;

    std::vector<int> _idJobs;
    std::vector<int> _idEmployer;
};

#endif
