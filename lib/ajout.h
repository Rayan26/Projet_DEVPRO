#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Parse.h"
#include "Service.h"

using namespace std;

/*
 *  Fonctions permettant de verifier si l'objet existe dans la base de données, 
 *  puis l'ajoute au Fichier CSV en appelant addObjetCSV
 */
void addEmployer(const Employer &empl, std::vector<Employer> &employers);
void addEntreprise(const Entreprise &entre, std::vector<Entreprise> &entreprises);
void addChomeur(const Chomeur &chom, std::vector<Chomeur> &chomeurs);
void addPoste(const Poste &post, std::vector<Poste> &postes);

/*
 *  Fonctions permettant de supprimer l'objet de la base de données, 
 *  en  supprimant toute les dépendance de l'objet
 *  puis en rééditant le fichier CSV
 */
void delEmployer(vector<Employer> &employers, vector<Entreprise> &entreprises, int id);
void delEntreprise(vector<Entreprise> &entreprises, int id);
void delChomeur(vector<Chomeur> &chomeurs, int id);
void delPoste(vector<Poste> &postes, vector<Entreprise> &entreprises, int id);