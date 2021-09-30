#ifndef RPGUNDERGROUND_HEROS_H
#define RPGUNDERGROUND_HEROS_H
#include <iostream>

class heros {
protected:
    std::string m_HeroNom;
    int m_HeroVie;
    int m_Monnaie;
    std::string m_Heroclasse;
    std::string m_HerosEspece;
    std::string m_HeroFonctions;
    std::string m_HeroArmes;
    int m_HeroForce;
    int m_HeroExp;
    bool m_HeroProteger;

public:
    heros();
    heros(std::string nomhero, int viehero, int monnaiehero, std::string classehero, std::string especeheros, std::string fonctionhero, std::string armehero, int forcehero, int exphero, bool protegerhero);
    void DiminutionVie(int vieenmoins);
    void Attaquer(heros &cible);
    void Competence(heros &cible);
    void utiliserObjets(std::string objet);
    bool seProteger();
    bool vivant() const;
    void Fuir();
    virtual void afficher() const;
};


#endif //RPGUNDERGROUND_HEROS_H