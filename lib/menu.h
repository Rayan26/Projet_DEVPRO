#pragma once
#include <iostream>
#include <string>
#include <vector>

int onInputPrincipal();
int onInputEntreprise();
int onInputEmployer();
int onInputChomeur();
int onInputIntChomeur();




void creer_profil_entreprise();
void creer_profil_chomeur();
void creer_profil_employer();

void identification_entreprise();
void identification_chomeur();
void identification_employer();

void affichage_menu_principal();
void affichage_menu_entreprise();
void affichage_menu_chomeur();
void affichage_menu_employer();

void affichage_menu_intermediaire_chomeur();
void affichage_menu_intermediaire_entreprise();
void affichage_menu_intermediaire_employer();

void modification_profil_chomeur();
void modification_profil_employer();

void transition_chercheur_emploi();
void transition_employer();

void supprimer_profil_chomeur();
void supprimer_profil_employer();

void creer_poste();

void supprimer_poste();

void rechercher_demandeur_emploi();