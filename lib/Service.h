#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"
#include "Entreprise.h"
#include "Poste.h"
#include "Employer.h"
#include "Chomeur.h"

using namespace std;

/*
 * Fonctions permettant de récuperer un objet dans la BDD dynamique à partir de son id
 */
Entreprise *get_entreprise(int id, vector<Entreprise> &entreprises);
Employer *get_employers(int id, vector<Employer> &employers);
Chomeur *get_chomeur(int id, vector<Chomeur> &chomeurs);
Poste *get_poste(int id, vector<Poste> &postes);

/*
 * Permet de récuperer tout les employés d'une entreprise
 */
vector<Employer> get_employers_de_entreprise(int id_entr, vector<Employer> &employers);

//Fonctions de recherches d'un poste pour un employé ou un chomeur
vector<Poste> recherche_par_comp(string competence_recherche, vector<Poste> postes);
vector<Poste> recherche_par_comp_CP(string competence_recherche, string CP, vector<Poste> postes, vector<Entreprise> entreprises);
vector<Employer> recherche_employer_par_comp(string competence_recherche, vector<Employer> &employers);
vector<Employer> recherche_employer_par_comp_CP(string competence_recherche, string CP, vector<Employer> &employers);

/*
 * RESTE à IMPLEMENTER RECHERCHE PERSONNE POUR UNE ENTREPRISE
 */
vector<Chomeur> rechercher_chomeur(string CP, vector<Chomeur> chomeurs);

/*
 * Fonction permettant de rajouter un employé parmis les employés de l'entreprise
 */
void ajout_employer_entreprise(Employer &empl, int id_entreprise, vector<Entreprise> &entreprises);
