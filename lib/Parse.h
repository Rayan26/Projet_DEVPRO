#ifndef DEF_PARSE
#define DEF_PARSE


#include <iostream>
#include <string>
#include <vector>
#include "Service.h"


std::vector<Chomeur> Create_Chomeur();
std::vector<Employer> Create_Employer();
std::vector<Entreprise> Create_Entreprise();
std::vector<Poste> Create_Poste();
void addEmployerCSV(const Employer &empl, std::vector<Employer> &employers);
void addEntrepriseCSV(Entreprise entre);


#endif