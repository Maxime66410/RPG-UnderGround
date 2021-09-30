#include <iostream>
#include <string>
#include "Header/preparation.h"
#include "Header/sauvegarder.h"

using namespace std;

int main() {
    string BartWind = "**********************************************************"; // Template  des barre
    preparation preparationHeader;  //  Ma fonction préparation
    sauvegarder LaSauvegarde; // Ma Fonction Sauvegarder
    string Choix;   //  Texte pour le choix

    cout << BartWind << endl << BartWind << endl;
    cout << "******************** RPG UnderGround *********************" << endl;
    cout << BartWind << endl << BartWind << endl;
    cout << "********** Commencer une nouvelle partie (play) **********" << endl;
    cout << "*********** Charger une partie existante (load) **********" << endl;
    cout << "****************** Quitter le jeu (exit) *****************" << endl;
    cout << BartWind << endl << BartWind << endl;

    cin >> Choix;   //  Choix du joueur

    if(Choix == "play" || Choix == "Play")
    {
        system("cls");
        preparationHeader.preparationGame();
    }
    else if(Choix == "load" || Choix == "Load")
    {
        system("cls");
        LaSauvegarde.MenuSauvegarde(" ", 0, 0, " ", " ", " ", " ", 0, 0);
    }
    else
    {
        cout << "Arret du programme" << endl;
    }

    return 0;
}
