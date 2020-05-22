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
 * 
 * COMMENTAIRE je pense qu'on devrait prendre l'objet en argument dans cette fonction 
 * REPONSE Pas besoin, on a son id et la liste complète des entreprises en globale donc on pourra toujours y acceder
 */
void affichage_menu_intermediaire_entreprise();
int onInputIntEntreprise();

/*
 * Menu Intermédiaire chercheur d'emploi
 * Permet de Modifier son profil
 * Permet de transtionner vers employés
 * Permet de supprimer son profil
 * Permet de faire une recherche parmis les postes à pourvoir
 *  
 * COMMENTAIRE je pense qu'on devrait prendre l'objet en argument dans cette fonction 
 */
void affichage_menu_intermediaire_chomeur();
int onInputIntChomeur();

/*
 * Menu Intermédiaire employé
 * Permet de Modifier son profil
 * Permet de transtionner vers chercheur d'emploi
 * Permet de supprimer son profil
 * Permet de faire une recherche parmis les postes à pourvoir
 * 
 * COMMENTAIRE je pense qu'on devrait prendre l'objet en argument dans cette fonction 
 */
void affichage_menu_intermediaire_employer();
int onInputIntEmployer();

/*
 * Fonctions appellant le constructeur de l'objet,
 * Lui attribuant un id disponible
 * Et demande les information necessaire à creer l'objet
 * puis appeler les fonctions  addObjet de ajout.h 
 * 
 * A IMPLEMENTER
 */
void creer_profil_entreprise();
void creer_profil_chomeur();
void creer_profil_employer();

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
 * 
 * A IMPLEMENTER
 */
void modification_profil_chomeur();
void modification_profil_employer();


/*
 * Permet de faire la transition vers le coté obscur de la force
 * Creer  le nouvel objet avec les informations de l'ancien
 * Puis appelle le menu_intermediaire_of_the_other_side()
 * 
 * Dans le cas du passage de chomeur à employé on doit demander l'id de la nouvelle entreprise
 * puis appeler ajout_employer_entreprise() qui rajoute le nouvel employé à la liste de ses employés
 *
 * A IMPLEMENTER
 */
void transition_chercheur_emploi();
void transition_employer();


/*
 * Appelle delOBJET de ajout.h
 * Puis retourne au menu principal 
 * 
 * A IMPLEMENTER
 */
void supprimer_profil_chomeur();
void supprimer_profil_employer();



void creer_poste();

void supprimer_poste();

void rechercher_demandeur_emploi();

