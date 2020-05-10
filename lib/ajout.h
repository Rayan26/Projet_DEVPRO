#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Parse.h"
#include "Service.h"


using namespace std;

void addEmployer(const Employer &empl, std::vector<Employer> &employers);
void addEntreprise(const Entreprise &entre, std::vector<Entreprise>&entreprises);
void addChomeur(const Chomeur &chom, std::vector<Chomeur> &chomeurs);
void addPoste(const Poste &post,std::vector<Poste> &postes);



void delEmployer(vector<Employer> &employers,vector<Entreprise> &entreprises,int id);
void delEntreprise(vector<Entreprise> &entreprises,int id);
void delChomeur(vector<Chomeur> &chomeurs,int id);
void delPoste(vector<Poste> &postes,int id);
