#include "../Header/navigation.h"
#include "../Header/sauvegarder.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

string BaseSet = "**********************************************************";
string BaseSet2 = "*                                                        *";

string const NomFichier("_Data.txt");
ifstream Fichier(NomFichier.c_str());

string const NomfichierTour("_Tour.txt");
ifstream FichierTour(NomfichierTour.c_str());

string tempNomheros = "";
int tempVieHeros = 0;
int tempMonnaie = 0;
string tempClasse = "";
string tempEspece = "";
string tempFonctions = "";
string tempArme = "";
int tempForce = 0;
int tempExp = 0;
int tempTour = 0;

sauvegarder LaSauvegarder;

string navigation::ChargerLaSauvegarde()
{
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

    return "OK" ;
}

void navigation::MenuNavigation()
{
    ChargerLaSauvegarde();

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
        cout << "COMBAT GO !";
    }
    else if (Choix == "Shop" || Choix == "shop")
    {
        cout << "SHOP GO !";
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