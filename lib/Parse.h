#ifndef DEF_PARSE
#define DEF_PARSE


#include <iostream>
#include <string>
#include <vector>
#include "Service.h"

/*
 * Création de la base de données dynamiques 
 * utilisée dans le programme courant à partir des fichiers CSV
 */
std::vector<Chomeur> Create_Chomeur();
std::vector<Employer> Create_Employer();
std::vector<Entreprise> Create_Entreprise();
std::vector<Poste> Create_Poste();

/*
 * Rajout d'un employer dans le fichier CSV
 */
void addEmployerCSV(const Employer &empl, std::vector<Employer> &employers);
void addEntrepriseCSV(const Entreprise &entre, std::vector<Entreprise>&entreprises);
void addChomeurCSV(const Chomeur &chom, std::vector<Chomeur> &chomeurs);
void addPosteCSV(const Poste &post,std::vector<Poste> &postes);


/*
 * Suppression d'une ligne dans le fichier CSV
 * 
 * COMMENTAIRE : fonctionelle mais inutiles une fois que MajCSVObjet sera correctement implémenté 
 */
void delEmployerCSV(int ID);
void delEntrepriseCSV(int ID);
void delChomeurCSV(int ID);
void delPosteCSV(int ID);


/*
 * Mise à jour du fichier csv à partir de la base de donnée dynamique
 * 
 * EN COURS D'implémentation
 */
void MajCSVEmployer(std::vector<Employer> &employers);
void MajCSVEntreprise(std::vector<Employer> &employers);
void MajCSVChomeur(std::vector<Employer> &employers);
void MajCSVPoste(std::vector<Employer> &employers);

#endif

