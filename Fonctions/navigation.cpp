#include "../Header/navigation.h"
#include "../Header/sauvegarder.h"
#include "../Header/magasin.h"
#include "../Header/combat.h"
#include "../Header/preparation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

string BaseSet = "**********************************************************";
string BaseSet2 = "*                                                        *";

string const NomFichier("_Data.txt");   // prise en charge du fichier data
ifstream Fichier;

string const NomfichierTour("_Tour.txt"); // prise en charge du fichier tour
ifstream FichierTour;

string tempNomheros = ""; // variable temporaire pour le nom du héros
int tempVieHeros = 0;   // variable temporaire pour la vie du Héros
int tempMonnaie = 0;   // variable temporaire pour la Monnaie
string tempClasse = "";   // variable temporaire pour la Classe du Héros
string tempEspece = "";   // variable temporaire pour l'Espece du héros
string tempFonctions = "";   // variable temporaire pour la Fonctions du héros
string tempArme = "";   // variable temporaire pour l'arme du héros
int tempForce = 0;   // variable temporaire pour la force du héros
int tempExp = 0;   // variable temporaire pour le expérience du héros
int tempTour = 0;   // variable temporaire pour le tour

sauvegarder LaSauvegarder;
magasin LeMagasin;
combat LeCombat;
preparation LaPreparation;

string navigation::ChargerLaSauvegarde()
{
    Fichier.open(NomFichier.c_str());
    FichierTour.open(NomfichierTour.c_str());

    string ligne = "";
    string Nomheros = "";
    string VieJoueur = "";
    string MonnaieJoueur = "";
    string Classe = "";
    string Espece = "";
    string Fonctions = "";
    string Arme = "";
    string Force = "";
    string Exp = "";
    string NbrTour = "";

    if(Fichier) // ce test échoue si le fichier n'est pas ouvert
    {
        while(getline(Fichier, ligne))
        {
            Nomheros = ligne;
            Fichier >> ligne;
            VieJoueur = ligne;
            Fichier >> ligne;
            MonnaieJoueur = ligne;
            Fichier >> ligne;
            Classe = ligne;
            Fichier >> ligne;
            Espece = ligne;
            Fichier >> ligne;
            Fonctions = ligne;
            Fichier >> ligne;
            Arme = ligne;
            Fichier >> ligne;
            Force = ligne;
            Fichier >> ligne;
            Exp = ligne;
            break;
        }
    }

    if(FichierTour)
    {
        while(getline(FichierTour, ligne))
        {
            NbrTour = ligne;
            break;
        }
    }

    tempNomheros = Nomheros;
    tempVieHeros = atoi(VieJoueur.c_str());
    tempMonnaie = atoi(MonnaieJoueur.c_str());
    tempTour = atoi(NbrTour.c_str());
    tempClasse = Classe;
    tempEspece = Espece;
    tempFonctions = Fonctions;
    tempArme = Arme;
    tempForce = atoi(Force.c_str());
    tempExp = atoi(Exp.c_str());

    Fichier.close();
    FichierTour.close();

    return "OK" ;
}

void navigation::MenuNavigation()
{
    system("cls");
    ChargerLaSauvegarde();

    if(tempTour != 20)
    {
        string Choix = "";

        cout << BaseSet << endl << BaseSet << endl;
        cout << BaseSet2 << endl << BaseSet2 << endl;
        cout << "*** Heros Nom : " << tempNomheros << "    Vie : " << tempVieHeros << "    Monnaie : " << tempMonnaie << " ***" << endl ;
        cout << "*                   Tour : " << tempTour << " / 20                        *" << endl;
        cout << BaseSet2 << endl << BaseSet2 << endl;
        cout << "*                    Combat (combat)                     *" << endl;
        cout << BaseSet2 << endl;
        cout << "*                    Magasin (shop)                      *" << endl;
        cout << BaseSet2 << endl;
        cout << "*                   Sauvegarder (save)                   *" << endl;
        cout << BaseSet2 << endl << BaseSet << endl << BaseSet << endl;

        cin >> Choix;

        if(Choix == "Combat" || Choix == "combat")
        {
            system("cls");
            LeCombat.Game();
        }
        else if (Choix == "Shop" || Choix == "shop")
        {
            system("cls");
            LeMagasin.MenuShop();
        }
        else if(Choix == "Save" || Choix == "save")
        {
            system("cls");
            LaSauvegarder.MenuSauvegarde(tempNomheros, tempVieHeros, tempMonnaie, tempClasse, tempEspece, tempFonctions, tempArme, tempForce, tempExp);
        }
        else
        {
            system("cls");
            MenuNavigation();
        }
    }
    else
    {
        string ChoixTemp = "";

        cout << BaseSet << endl << BaseSet << endl;
        cout << BaseSet2 << endl << BaseSet2 << endl;
        cout << "*                    Vous avez gagner !                  *" << endl;
        cout << BaseSet2 << endl;
        cout << "*    Vous pouvez recommencer la partie (continuer) ou    *" << endl;
        cout << "*                     quitter (exit)                     *" << endl;
        cout << BaseSet2 << endl<< BaseSet2 << endl << BaseSet << endl << BaseSet << endl;

        cin >> ChoixTemp;

        if(ChoixTemp == "Continuer" || ChoixTemp == "continuer")
        {
            system("cls");
            LaPreparation.preparationGame();
        }
        else
        {
            // ferme le programme
        }
    }
}