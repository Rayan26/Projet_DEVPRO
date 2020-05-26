#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"
#include "Entreprise.h"
#include "Poste.h"
#include "Chomeur.h"
#include "Employer.h"
#include "menu.h"
#include "Parse.h"
#include "Service.h"
#include "ajout.h"

/* 
 * Affiche le menu Initial 
 * On peut ensuite rejoindre
 * Le menu Entreprises
 * Le menu Employé
 * Le menu Chomeur
 */
void affichage_menu_principal();
int onInputPrincipal();

/*
 * Menu Entreprise
 * Permet de Créer un profil d'entreprise
 * Ou de s'identifier pour acceder au menu intermédiare entreprise
 */
void affichage_menu_entreprise();
int onInputEntreprise();

/*
 * Menu Chomeur
 * Permet de Créer un profil de demandeur d'emploi
 * Ou de s'identifier pour acceder au menu intermédiare chomeur
 */
void affichage_menu_chomeur();
int onInputChomeur();

/*
 * Menu Employé
 * Permet de Créer un profil d'employé
 * Ou de s'identifier pour acceder au menu intermédiare employé
 */
void affichage_menu_employer();
int onInputEmployer();

/*
 * Menu intermediare entreprise
 * Permet de créer un poste à pourvoir,
 * Permet de supprimer un poste à pourvoir,
 * Permet de faire une recherche parmis les demandeurs d'emplois
 */
void affichage_menu_intermediaire_entreprise();
int onInputIntEntreprise();

/*
 * Menu Intermédiaire chercheur d'emploi
 * Permet de Modifier son profil
 * Permet de transtionner vers employés
 * Permet de supprimer son profil
 * Permet de faire une recherche parmis les postes à pourvoir
 */
void affichage_menu_intermediaire_chomeur();
int onInputIntChomeur();

/*
 * Menu Intermédiaire employé
 * Permet de Modifier son profil
 * Permet de transtionner vers chercheur d'emploi
 * Permet de supprimer son profil
 * Permet de faire une recherche parmis les postes à pourvoir
 */
void affichage_menu_intermediaire_employer();
int onInputIntEmployer();

/*
 * Fonctions appellant le constructeur de l'objet,
 * Lui attribuant un id disponible
 * Et demande les information necessaire à creer l'objet
 * puis appeler les fonctions  addObjet de ajout.h 

 */
void creer_profil_entreprise();
void creer_profil_chomeur();
void creer_profil_employer();
void creer_poste();

/*
 * Fonctions permetant de charger le profil de l'objet
 * en comparant l'id rentré par l'utilisateur à ceux présent dans la base de données
 * si erreur retourne au menu_objet
 * sinon on appelle affichage_menu_intermediaire_objet()
 * 
 */
void identification_entreprise();
void identification_chomeur();
void identification_employer();

/*
 * Permet de modifier les informations concernant la personne comme son CP ou son mail
 * Appeler ensuite majObjetCSV()
 */
void modification_profil_chomeur();
void modification_profil_employer();
void transition_chercheur_emploi();
void transition_employer();

/*
 * Appelle delOBJET de ajout.h
 * Puis retourne au menu principal 
 */
void supprimer_profil_chomeur();
void supprimer_profil_employer();
void supprimer_profil_entreprise();
void supprimer_poste();

void rechercher_demandeur_emploi();
