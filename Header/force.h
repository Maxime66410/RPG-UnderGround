//
// Created by max66 on 11/10/2021.
//

#ifndef RPGUNDERGROUND_FORCE_H
#define RPGUNDERGROUND_FORCE_H

#include "heros.h"

class force : public heros {
public:
    force(std::string nomheros, int vieheros, int monnaieheros, std::string classeheros, std::string especeheros, std::string fonctionsheros, std::string armeheros, int forceheros, int expheros, bool protegerheros);
    void utilisationForce(heros &cible);
};


#endif //RPGUNDERGROUND_FORCE_H
