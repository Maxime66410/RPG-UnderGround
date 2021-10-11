//
// Created by max66 on 11/10/2021.
//

#ifndef RPGUNDERGROUND_MAGIE_H
#define RPGUNDERGROUND_MAGIE_H

#include "heros.h"

class magie : public heros{
public:
    magie(std::string nomheros, int vieheros, int monnaieheros, std::string classeheros, std::string especeheros, std::string fonctionsheros, std::string armeheros, int forceheros, int expheros, bool protegerheros);

private:
    void m_magie(heros &cible);
};


#endif //RPGUNDERGROUND_MAGIE_H
