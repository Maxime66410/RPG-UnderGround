#include "../Header/combat.h"
#include "../Header/navigation.h"
#include "../Header/heros.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Sauvegarde et data (joueur)
string const c_FichierDuNomJoueur("_Data.txt");
fstream c_FichierDuJoueur;

// Sauvegarde Tour (Tour du joueur)
string const c_FichierNomDesTour("_Tour.txt");
fstream c_FichierDuTour;

// Sauvegarde Inventaire
string const c_FichierDuNomInventaire("_Inventory.txt");
fstream c_FichierInventaire;

// Chargement des variable du Joueur qui est IMPORTANT !!!!!
string jc_NomJoueur = "";
int jc_VieJoueur = 0;
int jc_MonnaieJoueur = 0;
string jc_ClasseJoueur = "";
string jc_EspeceJoueur = "";
string jc_FonctionsJoueur = "";
string jc_ArmesJoueur = "";
int jc_ForceJoueur = 0;
int jc_ExpJoueur = 0;
bool jc_ProtegerJoueur(false);

// Chargement des variable des tour
int jc_tour = 0;

// Chargement des variables inventaire du Joueur
int jc_PotionDeSoins = 0;
int jc_PotionDeForce = 0;

// Chargement des variables enemy !!!

// Variable du Jeux (Très important)
bool DonneerDejaCharger(false);

void combat::InitialisationGame()
{
    c_FichierDuJoueur.open(c_FichierDuNomJoueur.c_str());
    c_FichierDuTour.open(c_FichierNomDesTour.c_str());
    c_FichierInventaire.open(c_FichierDuNomInventaire.c_str());

    string tempLigne = "";

    if(c_FichierDuJoueur)
    {
        while(getline(c_FichierDuJoueur, tempLigne))
        {
            jc_NomJoueur = tempLigne;
            c_FichierDuJoueur >> tempLigne;
            jc_VieJoueur = atoi(tempLigne.c_str());
            c_FichierDuJoueur >> tempLigne;
            jc_MonnaieJoueur = atoi(tempLigne.c_str());
            c_FichierDuJoueur >> tempLigne;
            jc_ClasseJoueur = tempLigne;
            c_FichierDuJoueur >> tempLigne;
            jc_EspeceJoueur = tempLigne;
            c_FichierDuJoueur >> tempLigne;
            jc_FonctionsJoueur = tempLigne;
            c_FichierDuJoueur >> tempLigne;
            jc_ArmesJoueur = tempLigne;
            c_FichierDuJoueur >> tempLigne;
            jc_ForceJoueur = atoi(tempLigne.c_str());
            c_FichierDuJoueur >> tempLigne;
            jc_ExpJoueur = atoi(tempLigne.c_str());
            break;
        }
    }
    else
    {
        cout << endl << "ERREUR : CHARGEMENT DU JOUEUR IMPOSSIBLE !" << endl;
    }

    if(c_FichierInventaire)
    {
        while(getline(c_FichierInventaire, tempLigne))
        {
            jc_PotionDeSoins = atoi(tempLigne.c_str());
            c_FichierInventaire >> tempLigne;
            jc_PotionDeForce = atoi(tempLigne.c_str());
            break;
        }
    }
    else
    {
        cout << endl << "ERREUR : CHARGEMENT DE L'INVENTAIRE IMPOSSIBLE !" << endl;
    }

    if(c_FichierDuTour)
    {
        while(getline(c_FichierDuTour, tempLigne))
        {
            jc_tour = atoi(tempLigne.c_str());
            break;
        }
    }
    else
    {
        cout << endl << "ERREUR : CHARGEMENT DES TOUR IMPOSSIBLE !" << endl;
    }

    c_FichierDuJoueur.close();
    c_FichierDuTour.close();
    c_FichierInventaire.close();
    DonneerDejaCharger = true;
}

void combat::Game()
{
    if(!DonneerDejaCharger)
    {
        InitialisationGame();
    }
}