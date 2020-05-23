#include "Personne.h"

using namespace std;

Personne::Personne()
{
}

Personne::Personne(int id, string nom, string prenom, string mail, string code, vector<string> const &skill) : _id(id), _nom(nom), _prenom(prenom), _mail(mail), _code(code), _skill(skill)
{
}

Personne::Personne(const Personne &personne) : _id(personne.getIdPersonne()), _nom(personne.getNom()), _prenom(personne.getPrenom()), _mail(personne.getMail()), _code(personne.getCode()), _skill(personne.getSkill()), _IdCollegue(personne.get_collegues()), _IdAncienCollegue(personne.get_Anciens_collegues())
{
}

Personne::~Personne()
{
}

int Personne::getIdPersonne() const
{
    return this->_id;
}

string Personne::getNom() const
{
    return this->_nom;
}

string Personne::getPrenom() const
{
    return this->_prenom;
}

string Personne::getMail() const
{
    return this->_mail;
}

string Personne::getCode() const
{
    return this->_code;
}

vector<string> Personne::getSkill() const
{
    return _skill;
}

void Personne::setId(int newid)
{
    this->_id = newid;
}

void Personne::setNom(string newnom)
{
    this->_nom = newnom;
}

void Personne::setPrenom(string newprenom)
{
    this->_prenom = newprenom;
}

void Personne::setMail(string newmail)
{
    this->_mail = newmail;
}

void Personne::setCode(string newcode)
{
    this->_code = newcode;
}

void Personne::addCompetence(string newcompetence)
{
    _skill.push_back(newcompetence);
}

void Personne::addCollegue(int const newcollegue)
{
    int compteur;
    bool verif = false;
    for (size_t i = 0; i < _IdAncienCollegue.size(); i++)
    {
        if (_IdAncienCollegue[i] == newcollegue)
        {
            compteur = i;
            verif = true;
        }
    }
    if (verif == true)
    {
        _IdCollegue.push_back(newcollegue);
        _IdAncienCollegue.erase(_IdAncienCollegue.begin() + compteur);
    }
    else
    {
        this->_IdCollegue.push_back(newcollegue);
    }
}

void Personne::addAncienCollegue(int const Anciencollegue)
{
    bool verif = false;

    for (size_t i = 0; i < _IdCollegue.size(); i++)
    {
        if (_IdCollegue[i] == Anciencollegue)
        {
            verif = true;
        }
    }
    for (size_t i = 0; i < _IdAncienCollegue.size(); i++)
    {
        if (_IdAncienCollegue[i] == Anciencollegue)
        {
            verif = true;
        }
    }
    if (verif == false)
    {
        _IdAncienCollegue.push_back(Anciencollegue);
    }
}

void Personne::printInfo() const
{
    cout << "" << endl;
    cout << "ID de la personne : " << _id << endl;
    cout << "Monsieur : " << _nom << "  " << _prenom << endl;
    cout << "Mail : " << _mail << endl;
    cout << "Code Postal : " << _code << endl;

    for (size_t i(1); i <= _skill.size(); ++i)
    {
        cout << "Compétence " << i << " : " << _skill[i - 1] << endl;
    }

    // for (size_t i(1); i <= _IdCollegue.size(); ++i)
    // {
    //     cout << "ID du collègue n°" << i << " : " << _IdCollegue[i - 1] << endl;
    // }
}

std::vector<int> Personne::get_collegues() const
{
    vector<int> collegues;

    for (size_t i = 0; i < _IdCollegue.size(); i++)
    {
        collegues.push_back(_IdCollegue[i]);
    }
    return collegues;
}

std::vector<int> Personne::get_Anciens_collegues() const
{
    vector<int> Anciens_collegues;

    for (size_t i = 0; i < _IdAncienCollegue.size(); i++)
    {
        Anciens_collegues.push_back(_IdAncienCollegue[i]);
    }
    return Anciens_collegues;
}

void Personne::erase_collegue(int id)
{
    for (size_t i = 0; i < _IdCollegue.size(); i++)
    {
        if (_IdCollegue[i] == id)
        {
            _IdCollegue.erase(_IdCollegue.begin() + i);
        }
    }
}

void Personne::erase_ancien_collegue(int id)
{
    for (size_t i = 0; i < _IdAncienCollegue.size(); i++)
    {
        if (_IdAncienCollegue[i] == id)
        {
            _IdAncienCollegue.erase(_IdAncienCollegue.begin() + i);
        }
    }
}
