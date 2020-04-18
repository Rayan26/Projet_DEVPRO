#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"
#include "Entreprise.h"
#include "Poste.h"
#include "Parse.h"

using namespace std;

Entreprise *get_entreprise(int id, vector<Entreprise> &entreprises);
Employer* get_employers(int id, vector<Employer> &employers);
Chomeur* get_chomeur(int id, vector<Chomeur> &chomeurs);
Poste * get_poste(int id, vector<Poste> &postes);
vector<Employer> get_employers_de_entreprise(int id_entr, vector<Employer> &employers);


//Fonctions de recherches
vector<Poste> recherche_par_comp(string competence_recherche,vector<Poste> postes);
vector<Poste> recherche_par_comp_CP(string competence_recherche,string CP,vector<Poste> postes,vector<Entreprise> entreprises);

