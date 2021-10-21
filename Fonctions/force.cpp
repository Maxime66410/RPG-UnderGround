//
// Created by max66 on 11/10/2021.
//

#include "../Header/force.h"
#include <stdio.h>
#include <string.h>

using namespace std;

force::force(std::string nomheros, int vieheros, int monnaieheros, std::string classeheros, std::string especeheros, std::string fonctionsheros, std::string armeheros, int forceheros, int expheros, bool protegerheros) : heros(nomheros, vieheros, monnaieheros, classeheros, especeheros, fonctionsheros, armeheros, forceheros, expheros, protegerheros)
{

}
force::~force()
{

}

void force::utilisationForce(heros &cible)
{
    cible.DiminutionVie(120);
    cout << "*             " << m_HeroNom << " Utilise Force Speciale donnant Degat : " << 120 << "             *";
}