//
// Created by max66 on 11/10/2021.
//

#include "../Header/magie.h"
#include <stdio.h>
#include <string.h>

using namespace std;

magie::magie(std::string nomheros, int vieheros, int monnaieheros, std::string classeheros, std::string especeheros, std::string fonctionsheros, std::string armeheros, int forceheros, int expheros, bool protegerheros)  : heros(nomheros, vieheros, monnaieheros, classeheros, especeheros, fonctionsheros, armeheros, forceheros, expheros, protegerheros)
{

}



void magie::m_magie(heros &cible)
{
    cible.DiminutionVie(180);
}