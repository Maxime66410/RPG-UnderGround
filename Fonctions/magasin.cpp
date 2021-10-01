#include "../Header/magasin.h"
#include "../Header/navigation.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string BaseSetss = "**********************************************************";
string BaseSetss2 = "*                                                        *";

// Charge des données utilisateur

string const NomFichierMag("_Data.txt");
fstream Fichierheros;

string tempNomheross = "";
int tempVieHeross = 0;
int tempMonnaies = 0;
string tempClasses = "";
string tempEspeces = "";
string tempFonctionss = "";
string tempArmes = "";
int tempForces = 0;
int tempExps = 0;

// Charge des données inventaire

string const NomFichierInv("_Inventory.txt");
fstream FichierInv;

int tempPotionHealth = 0;
int tempPotionForce = 0;

navigation LaNavigations;

void magasin::Acheter() // Méthode pour Acheter les objets du magasin
{
    string Acheterchoix = "";
    string confirmChoix = "";

    cout << BaseSetss << endl << BaseSetss << endl << BaseSetss2 << endl << BaseSetss2 << endl;
    cout << "*               Potion de Soins (health) : 15            *" << endl;
    cout << "*                Potion de Force (force) : 25            *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*                     Votre inventaire                   *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*      Potion de Soins : " << tempPotionHealth << "  -  Potion de Force : " << tempPotionForce << "       *" << endl;
    cout << BaseSetss2 << endl << BaseSetss2 << endl << BaseSetss << endl << BaseSetss << endl;

    cin >> Acheterchoix;

    if(Acheterchoix == "health" || Acheterchoix == "health")
    {
        cout << "Etes vous sur de vouloir acheter une Potion de Soins ? (Oui/Non) :" << endl;

        cin >> confirmChoix;

        if(confirmChoix == "Oui" || confirmChoix == "oui")
        {
            if(tempMonnaies >= 15)
            {
                tempPotionHealth += 1;
                tempMonnaies -= 15;
                Acheter();
            }
            else
            {
                cout << "Vous avez pas assez d'argent pour acheter une potion de Soins" << endl;
                Acheter();
            }
        }
        else
        {
            Acheter();
        }
    }
    else if(Acheterchoix == "Force" || Acheterchoix == "force")
    {
        cout << "Etes vous sur de vouloir acheter une Potion de Force ? (Oui/Non) :" << endl;

        cin >> confirmChoix;

        if(confirmChoix == "Oui" || confirmChoix == "oui")
        {
            if(tempMonnaies >= 15)
            {
                tempPotionForce += 1;
                tempMonnaies -= 25;
                Acheter();
            }
            else
            {
                cout << "Vous avez pas assez d'argent pour acheter une potion de Force" << endl;
                Acheter();
            }
        }
        else
        {
            Acheter();
        }
    }
    else
    {
        SauvegarderInv();
        MenuShop();
    }
}

void magasin::Vendre() //   Méthode pour vendre les objets de l'inventaire
{
    string vendrechoix = "";
    string confirmChoixvendre = "";

    cout << BaseSetss << endl << BaseSetss << endl << BaseSetss2 << endl << BaseSetss2 << endl;
    cout << "*                     Votre inventaire                   *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*      Potion de Soins : " << tempPotionHealth << "  -  Potion de Force : " << tempPotionForce << "       *" << endl;
    cout << BaseSetss2 << endl << BaseSetss2 << endl << BaseSetss << endl << BaseSetss << endl;

    cin >> vendrechoix;

    if(vendrechoix == "health" || vendrechoix == "Health")
    {
        if(tempPotionHealth >= 1)
        {
            cout << "Voulez vous vendre une potion de soins pour 10 Monnaie ? (oui/non) : " << endl;
            cin >> confirmChoixvendre;

            if(confirmChoixvendre == "Oui" || confirmChoixvendre == "oui")
            {
                tempMonnaies += 10;
                tempPotionHealth -= 1;
                Vendre();
            }
            else
            {
                cout << "Vous n'avais pas assez de Potion de Soins dans votre Inventaire !" << endl;
                Vendre();
            }
        }
    }
    else if(vendrechoix == "force" || vendrechoix == "Force")
    {
        if(tempPotionForce >= 1)
        {
            cout << "Voulez vous vendre une potion de force pour 15 Monnaie ? (oui/non) : " << endl;
            cin >> confirmChoixvendre;

            if(confirmChoixvendre == "Oui" || confirmChoixvendre == "oui")
            {
                tempMonnaies += 15;
                tempPotionForce -= 1;
                Vendre();
            }
            else
            {
                cout << "Vous n'avais pas assez de Potion de Force dans votre Inventaire !" << endl;
                Vendre();
            }
        }
    }
    else
    {
        SauvegarderInv();
        MenuShop();
    }
}

void magasin::SauvegarderInv()  //  Méthode pour sauvegarder les donnée de l'inventaire
{
    Fichierheros.open(NomFichierMag.c_str(), ios::out | ios::trunc);
    FichierInv.open(NomFichierInv.c_str(), ios::out | ios::trunc);

    if(Fichierheros)
    {
        Fichierheros << tempNomheross << endl << tempVieHeross << endl << tempMonnaies << endl << tempClasses << endl << tempEspeces << endl << tempFonctionss << endl << tempArmes << endl << tempForces << endl << tempExps << endl;
    }
    else
    {
        cout << "ERREUR : HEROS NON SAUVEGARDER" << endl;
    }

    if(FichierInv)
    {
        FichierInv << tempPotionHealth << endl << tempPotionForce << endl;
    }
    else
    {
        cout << "ERREUR : INVENTAIRE NON SAUVEGARDER" << endl;
    }
    Fichierheros.close();
    FichierInv.close();
}

void magasin::ChargerSauvegardes() //    Méthode pour charger les donnée de l'inventaire
{
    Fichierheros.open(NomFichierMag.c_str());
    FichierInv.open(NomFichierInv.c_str());

    string ligne = "";
    string Nomheros = "";
    string VieJoueur = "";
    string MonnaieJoueur = "";
    string Classe = "";
    string Espece = "";
    string Fonctions = "";
    string Arme = "";
    string Force = "";
    string Exps = "";
    string PotionHealth = "";
    string PotionForce = "";

    if(Fichierheros && FichierInv)
    {
        while(getline(Fichierheros, ligne))
        {
            Nomheros = ligne;
            Fichierheros >> ligne;
            VieJoueur = ligne;
            Fichierheros >> ligne;
            MonnaieJoueur = ligne;
            Fichierheros >> ligne;
            Classe = ligne;
            Fichierheros >> ligne;
            Espece = ligne;
            Fichierheros >> ligne;
            Fonctions = ligne;
            Fichierheros >> ligne;
            Arme = ligne;
            Fichierheros >> ligne;
            Force = ligne;
            Fichierheros >> ligne;
            Exps = ligne;
            break;
        }

        while(getline(FichierInv, ligne))
        {
            PotionHealth = ligne;
            FichierInv >> ligne;
            PotionForce = ligne;
            break;
        }

        tempNomheross = Nomheros;
        tempVieHeross = atoi(VieJoueur.c_str());
        tempMonnaies = atoi(MonnaieJoueur.c_str());
        tempClasses = Classe;
        tempEspeces = Espece;
        tempFonctionss = Fonctions;
        tempArmes = Arme;
        tempForces = atoi(Force.c_str());
        tempExps = atoi(Exps.c_str());

        tempPotionHealth = atoi(PotionHealth.c_str());
        tempPotionForce = atoi(PotionForce.c_str());
    }

    Fichierheros.close();
    FichierInv.close();
}

void magasin::RetourMenu()  //  Méthode pour fermer le magasin et sauvegarder l'inventaire
{
    SauvegarderInv();
    LaNavigations.MenuNavigation();
}

void magasin::MenuShop()    //  Méthode pour ouvrir le menu
{
    ChargerSauvegardes();

    string choixShop = "";

    cout << BaseSetss << endl << BaseSetss << endl << BaseSetss2 << endl << BaseSetss2 << endl;
    cout << "*                     Magasin d'objet                    *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*                      Acheter (buy)                     *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*                      Vendre (sell)                     *" << endl;
    cout << BaseSetss2 << endl;
    cout << "*                  Retour au Menu (exit)                 *" << endl;
    cout << BaseSetss2 << endl << BaseSetss2 << endl << BaseSetss << endl << BaseSetss << endl;

    cin >> choixShop;

    if(choixShop == "Buy" || choixShop == "buy")
    {
        system("cls");
        Acheter();
    }
    else if(choixShop == "Sell" || choixShop == "sell")
    {
        system("cls");
        Vendre();
    }
    else if(choixShop == "Exit" || choixShop == "exit")
    {
        system("cls");
        RetourMenu();
    }
    else
    {
        system("cls");
        MenuShop();
    }
}