//
// Created by max66 on 30/09/2021.
//

#ifndef RPGUNDERGROUND_SAUVEGARDER_H
#define RPGUNDERGROUND_SAUVEGARDER_H

#include <iostream>
#include <string>

class sauvegarder {
public:
    void ChargerPartie();
    void SauvegarderPartieContinuer();
    void SauvegarderPartieExit();
    void MenuSauvegarde(std::string HerosNom, int VieHero, int Monnaie, std::string Classe, std::string Espece, std::string Fonctions, std::string Arme, int Force, int Exp);
};


#endif //RPGUNDERGROUND_SAUVEGARDER_H
