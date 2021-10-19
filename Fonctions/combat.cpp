#include "../Header/combat.h"
#include "../Header/navigation.h"
#include "../Header/heros.h"
#include "../Header/magie.h"
#include "../Header/force.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

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

// Variable du Jeux (Très important)
bool DonneerDejaCharger(false);
bool ChargementJoueurEtAi(false);
string TypeDeMonstree = "";
string BaseSetsss = "**********************************************************************************";
string BaseSet2s = "*                                                                                *";
bool PartieLancer(false);
string ChoixMenu = "";

// Heros
magie magie_HeroJoueur("", 0, 0, "", "", "", "", 0, 0, false);
force force_HeroJoueur("", 0, 0, "", "", "", "", 0, 0, false);

// Enemie
magie magie_Monstre("", 0, 0, "", "", "", "", 0, 0, false);
force force_Monstre("", 0, 0, "", "", "", "", 0, 0, false);

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

void combat::CreationJoueurEtPersonnage()
{
    if(jc_ClasseJoueur == "Mage" || jc_ClasseJoueur == "mage" || jc_ClasseJoueur == "Archer" || jc_ClasseJoueur == "Archer")
    {
        magie Player(jc_NomJoueur, jc_VieJoueur, jc_MonnaieJoueur, jc_ClasseJoueur, jc_EspeceJoueur, jc_FonctionsJoueur, jc_ArmesJoueur, jc_ForceJoueur, jc_ExpJoueur, jc_ProtegerJoueur);
        magie_HeroJoueur.TransfermHeros(Player);
    }
    else
    {
        force Player(jc_NomJoueur, jc_VieJoueur, jc_MonnaieJoueur, jc_ClasseJoueur, jc_EspeceJoueur, jc_FonctionsJoueur, jc_ArmesJoueur, jc_ForceJoueur, jc_ExpJoueur, jc_ProtegerJoueur);
        force_HeroJoueur.TransfermHeros(Player);
    }

    if(jc_tour != 20)
    {   // Apparition des ennemie de base
        srand (time(NULL));

        int ChooseAI_Espece = rand() % 3 + 1;

        // cout << ChooseAI_Espece << endl; // -> Permet de vérifié le nombre aléatoire

        int Attaque = 0;
        int Vie = 0;

        if(ChooseAI_Espece == 2)    // Assignation Araignée pour l'ennemie
        {
            if(jc_tour != 0)
            {
                Attaque = 2 * jc_tour;
                Vie = 35 * jc_tour;
            }
            else
            {
                Attaque = 2;
                Vie = 35;
            }

            force Spider("Araignee Venimeuse", Vie, 0, "Monstre", "Araignee", "Pondre oeufs", "Soie d'araignee", Attaque, 0, false);
            force_Monstre.TransfermHeros(Spider);
            TypeDeMonstree = "Araignee";
        }
        else if(ChooseAI_Espece == 1)    // Assignation Zombie pour l'ennemie
        {
            if(jc_tour != 0)
            {
                Attaque = 4 * jc_tour;
                Vie = 45 * jc_tour;
            }
            else
            {
                Attaque = 4;
                Vie = 45;
            }

            force Zombie("Zombies", Vie, 0, "Monstre", "Zombie", "Mordre", "Bras & Poing", Attaque, 0, false);
            force_Monstre.TransfermHeros(Zombie);
            TypeDeMonstree = "Zombie";
        }
        else if(ChooseAI_Espece == 3)    // Assignation Squelette pour l'ennemie
        {
            if(jc_tour != 0)
            {
                Attaque = 3 * jc_tour;
                Vie = 42 * jc_tour;
            }
            else
            {
                Attaque = 3;
                Vie = 42;
            }

            magie Skeleton("Archer Squelette", Vie, 0, "Monstre", "Squelette", "Prendre la poussiere", "Epee d'os & Arc", Attaque, 0, false);
            magie_Monstre.TransfermHeros(Skeleton);
            TypeDeMonstree = "Squelette";
        }
    }
    else
    {
        // Apparition du boss

    }

    PartieLancer = true;
    ChargementJoueurEtAi = true;
}

void combat::CheckLaPartie()    // Fonction qui regarde les statistique de la partie
{
    if(jc_ClasseJoueur == "Mage" || jc_ClasseJoueur == "mage" || jc_ClasseJoueur == "Archer" || jc_ClasseJoueur == "Archer")
    {
        if(magie_HeroJoueur.vivant() == false)
        {
            SiLeJoueurAPerdu();
        }
    }
    else
    {
        if(force_HeroJoueur.vivant() == false)
        {
            SiLeJoueurAPerdu();
        }
    }

    if(TypeDeMonstree == "Squelette")
    {
        if(magie_Monstre.vivant() == false )
        {
            SiLeJoueurAGagner();
        }
    }
    else if (TypeDeMonstree == "Zombie")
    {
        if(force_Monstre.vivant() == false)
        {
            SiLeJoueurAGagner();
        }
    }
    else if (TypeDeMonstree == "Araignee")
    {
        if(force_Monstre.vivant() == false)
        {
            SiLeJoueurAGagner();
        }
    }
}

void combat::SiLeJoueurAPerdu() // La fonction lancer si le joueur Perd
{
    cout << "Joueur a Perdu" << endl;
}

void combat::SiLeJoueurAGagner() // La fonction lancer si le joueur Gagne
{
    cout << "Joueur a Gagner" << endl;
}

void combat::Game()
{
    if(!DonneerDejaCharger)  // Initialisation de la partie
    {
        InitialisationGame();
    }

    if(!ChargementJoueurEtAi) // Chargement joueur est IA
    {
        CreationJoueurEtPersonnage();
    }

    if(PartieLancer)
    {
        CheckLaPartie();
    }

    // Menu du combat

    cout << BaseSetsss << endl << BaseSetsss << endl;
    cout << BaseSet2s << endl << BaseSet2s << endl;
    if(TypeDeMonstree == "Zombie" || TypeDeMonstree == "Araignee")
    {
        cout << "*             ";
        force_Monstre.afficher();
        cout << "             *" << endl;
    }
    else
    {
        cout << "*             ";
        magie_Monstre.afficher();
        cout << "             *" << endl;
    }

    cout << BaseSet2s << endl << BaseSet2s << endl;
    cout << "*             ";
    if(jc_ClasseJoueur == "Mage" || jc_ClasseJoueur == "mage" || jc_ClasseJoueur == "Archer" || jc_ClasseJoueur == "Archer")
    {
        magie_HeroJoueur.afficher();
    }
    else
    {
        force_HeroJoueur.afficher();
    }
    cout << "             *" << endl;
    cout << BaseSet2s << endl << BaseSet2s << endl;
    cout << BaseSetsss << endl << BaseSetsss << endl;
    cout << "* Attaquer (attack) / ";
    if(jc_ClasseJoueur == "Mage" || jc_ClasseJoueur == "mage" || jc_ClasseJoueur == "Archer" || jc_ClasseJoueur == "Archer")
    {
        cout << "Magie (magie) / ";
    }
    else
    {
        cout << "Force (coup) / ";
    }
    cout << "Inventaire (item) / Se proteger (protect) *" << endl;
    cout << BaseSetsss << endl << BaseSetsss << endl;
    cin >> ChoixMenu;

    if(ChoixMenu == "Attack" || ChoixMenu == "attack")
    {

    }
    else if (ChoixMenu == "Magie" || ChoixMenu == "magie" || ChoixMenu == "Force" || ChoixMenu == "force")
    {

    }
    else if (ChoixMenu == "Item" || ChoixMenu == "item")
    {

    }
    else if (ChoixMenu == "Protect" || ChoixMenu == "protect")
    {

    }
    else
    {
        Game();
    }
   // Game();


}