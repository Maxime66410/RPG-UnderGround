#include "../Header/sauvegarder.h"
#include "../Header/navigation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string BaseSets = "**********************************************************";
string BaseSets2 = "*                                                        *";

navigation LaNavigation;  // Pour allez dans les fonctions nagivations.cpp

string const NomFichiers("_Data.txt");  //  Fichier important du Data du jeu
fstream Fichiers(NomFichiers.c_str());

string const NomfichierTours("_Tour.txt");  //  Fichier des paramètre de tour du jeu
fstream FichierTours(NomfichierTours.c_str());

string const NomDuFichiersInv("_Inventory.txt"); // Fichier de l'inventaire du joueur
fstream FichierInventaire(NomDuFichiersInv.c_str());

// Variable joueur pour le sauvegarder
string tempHeroNom = "";
int tempHeroVie = 0;
int tempHeroMonnaie = 0;
string tempHeroClasse = "";
string tempHeroEspece = "";
string tempHeroFonction = "";
string tempHeroArme = "";
int tempHeroForce = 0;
int tempHeroExp = 0;

void sauvegarder::ChargerPartie() // Méthode pour charger la partie
{
    if(FichierTours && Fichiers && FichierInventaire)
    {
        cout << "Chargement avec succes !" << endl;
        system("cls");
        LaNavigation.MenuNavigation();
    }
}

void sauvegarder::SauvegarderPartieContinuer()  //  Méthode pour charger la partie
{
    if(Fichiers && FichierTours && FichierInventaire)
    {
        Fichiers << tempHeroNom << endl << tempHeroVie << endl << tempHeroMonnaie << endl << tempHeroClasse << endl << tempHeroEspece << endl << tempHeroFonction << endl << tempHeroArme << endl << tempHeroForce << endl << tempHeroExp << endl;
        LaNavigation.MenuNavigation();
    }
    else
    {
        cout << "ERREUR : Sauvegarde impossible !" << endl;
    }
}

void sauvegarder::SauvegarderPartieExit()   //  Méthode pour charger la partie
{
    if(Fichiers && FichierTours && FichierInventaire)
    {
        Fichiers << tempHeroNom << endl << tempHeroVie << endl << tempHeroMonnaie << endl << tempHeroClasse << endl << tempHeroEspece << endl << tempHeroFonction << endl << tempHeroArme << endl << tempHeroForce << endl << tempHeroExp << endl;
        cout << "Arret du programme..." << endl;
    }
    else
    {
        cout << "ERREUR : Sauvegarde impossible !" << endl;
    }
}

void sauvegarder::MenuSauvegarde(string HerosNom, int VieHero, int Monnaie, string Classe, string Espece, string Fonctions, string Arme, int Force, int Exp) // Méthode Menu Sauvegarder
{
    tempHeroNom = HerosNom;
    tempHeroVie = VieHero;
    tempHeroMonnaie = Monnaie;
    tempHeroClasse = Classe;
    tempHeroEspece = Espece;
    tempHeroFonction = Fonctions;
    tempHeroArme = Arme;
    tempHeroForce = Force;
    tempHeroExp = Exp;

    string ChoixSave = "";

    cout << BaseSets << endl << BaseSets << endl << BaseSets2 << endl << BaseSets2 << endl;
    cout << "*           Sauvegarder et Continuer (savec)             *" << endl;
    cout << BaseSets2 << endl;
    cout << "*            Sauvegarder et Quitter (savex)              *" << endl;
    cout << BaseSets2 << endl;
    cout << "*        Charger la derniere sauvegarde (charge)         *" << endl;
    cout << BaseSets2 << endl << BaseSets2 << endl << BaseSets << endl << BaseSets << endl;

    cin >> ChoixSave;

    if(ChoixSave == "Savec" || ChoixSave == "savec")
    {
        system("cls");
        SauvegarderPartieContinuer();
    }
    else if(ChoixSave == "Savex" || ChoixSave == "savex")
    {
        system("cls");
        SauvegarderPartieExit();
    }
    else if(ChoixSave == "Charge" || ChoixSave == "charge")
    {
        system("cls");
        ChargerPartie();
    }
    else
    {
        system("cls");
        MenuSauvegarde(tempHeroNom, tempHeroVie, tempHeroMonnaie, tempHeroClasse, tempHeroEspece, tempHeroFonction, tempHeroArme, tempHeroForce, tempHeroExp);
    }
}