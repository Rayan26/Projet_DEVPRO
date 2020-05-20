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
void addEmployer(const Employer &empl, std::vector<Employer> &employers, vector<Chomeur> &chomeurs);
void addEntreprise(const Entreprise &entre, std::vector<Entreprise> &entreprises);
void addChomeur(const Chomeur &chom, std::vector<Chomeur> &chomeurs, vector<Employer> &employers);
void addPoste(const Poste &post, std::vector<Poste> &postes);

/*
 *  Fonctions permettant de supprimer l'objet de la base de données, 
 *  en  supprimant toute les dépendance de l'objet
 *  puis en rééditant le fichier CSV
 */
void delEmployer(vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises, int id);
void delEntreprise(vector<Entreprise> &entreprises, vector<Employer> &employers, int id);
void delChomeur(vector<Chomeur> &chomeurs, vector<Employer> &employers, int id);
void delPoste(vector<Poste> &postes, vector<Entreprise> &entreprises, int id);

/*
 * Fonction permettant la transition de Chomeur vers Employé et vice-versa
 */

void transitionEmployer_Vers_Chomeur(int idEmployer, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises);
void transitionChomeur_Vers_Employer(int idChomeur, int idEntreprises, vector<Employer> &employers, vector<Chomeur> &chomeurs, vector<Entreprise> &entreprises);

/*
 * Fonctions permettant de rechercher un id disponible
 */
int rechercheIdDispo_Employer(vector<Employer> &employers, vector<Chomeur> &chomeurs);
int rechercheIdDispo_Chomeur(vector<Chomeur> &chomeurs, vector<Employer> &employers);
int rechercheIdDispo_Entreprise(vector<Entreprise> &entreprises);
int rechercheIdDispo_Poste(vector<Poste> &postes);