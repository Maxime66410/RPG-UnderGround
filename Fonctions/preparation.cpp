#include "../Header/preparation.h"
#include "../Header/navigation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string NomJoueur = "";
string ClasseJoueur = "";
string BartWinds = "**********************************************************";
navigation Lnavigations;

int preparation::preparationGame() // Enregistrement nom joueur
{
    cout << BartWinds << endl << BartWinds << endl;
    cout << "************* Veuillez entre votre prenom ! **************" << endl;
    cout << BartWinds << endl << BartWinds << endl;
    cin >> NomJoueur;

    system("cls");

    ChoixClasse();

    return 0;
}

int preparation::ChoixClasse() // Choix de la classe du joueur
{
    cout << BartWinds << endl << BartWinds << endl;
    cout << "************** Veuillez choisir votre classe *************" << endl;
    cout << BartWinds << endl;
    cout << "********** Archer - Guerrier - Mage - Chevalier **********" << endl;
    cout << BartWinds << endl << BartWinds << endl;

    cin >> ClasseJoueur;

    if(ClasseJoueur == "Archer" || ClasseJoueur == "archer" || ClasseJoueur == "Guerrier" || ClasseJoueur == "guerrier" || ClasseJoueur == "Mage" || ClasseJoueur == "mage" || ClasseJoueur == "Chevalier" || ClasseJoueur == "chevalier")
    {
        SauvegardeInitialisation();
    }
    else
    {
        ChoixClasse();
    }

    return 0;
}

int preparation::SauvegardeInitialisation() // Sauvegarde du premier data
{
    string const NomDuFichier("_Data.txt"); // Nom du fichier de sauvegarde
    string const NomDuFichierTour("_Tour.txt");
    string const NomDuFichierInv("_Inventory.txt");
    ofstream SauvegardeFichier(NomDuFichier.c_str()); // Sauvegarde
    ofstream SauvegardeTour(NomDuFichierTour.c_str());
    ofstream SauvegardeInventaire(NomDuFichierInv.c_str());
    int ForceTemporaire = 0;
    int VieTemporaire = 0;
    string ArmeTemporaire = "";

    if(ClasseJoueur == "Archer" || ClasseJoueur == "archer")
    {
        ForceTemporaire = 5;
        VieTemporaire = 100;
        ArmeTemporaire = "Arc";
    }
    else if(ClasseJoueur == "Guerrier" || ClasseJoueur == "guerrier")
    {
        ForceTemporaire = 7;
        VieTemporaire = 250;
        ArmeTemporaire = "Epee";
    }
    else if(ClasseJoueur == "Mage" || ClasseJoueur == "mage")
    {
        ForceTemporaire = 6;
        VieTemporaire = 85;
        ArmeTemporaire = "Baton de Magie";
    }
    else if(ClasseJoueur == "Chevalier" || ClasseJoueur == "chevalier")
    {
        ForceTemporaire = 8;
        VieTemporaire = 350;
        ArmeTemporaire = "Grande Epee";
    }

    if(SauvegardeFichier && SauvegardeTour)
    {
        SauvegardeFichier << NomJoueur << endl << VieTemporaire << endl << 0 << endl << ClasseJoueur << endl << "Humain" << endl << "Chomeur" << endl << ArmeTemporaire << endl << ForceTemporaire << endl << 0 << endl << false << endl;
        SauvegardeTour << 0 << endl;
        SauvegardeInventaire << 0 << endl << 0 << endl;
        Lnavigations.MenuNavigation();
    }
    else
    {
        cout << "ERREUR SAUVEGARDE..." << endl << "Tapez sur n'importe qu'elle touche pour revenir au menu" << endl;
        cin.get();

        return 0;
    }

   return 0;
}