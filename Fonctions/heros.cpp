#include "../Header/heros.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

heros::heros(std::string nomhero, int viehero, int monnaiehero, std::string classehero, std::string especeheros, std::string fonctionhero, std::string armehero, int forcehero, int exphero, bool protegerhero)
// Constructeur avec attribut
{
    m_HeroNom = nomhero;
    m_HeroVie = viehero;
    m_Monnaie = monnaiehero;
    m_Heroclasse = classehero;
    m_HerosEspece = especeheros;
    m_HeroFonctions = fonctionhero;
    m_HeroArmes = armehero;
    m_HeroForce = forcehero;
    m_HeroExp = exphero;
    m_HeroProteger = protegerhero;
}

void heros::DiminutionVie(int vieenmoins)   //  Méthode pour diminuer la vie du joueur
{
    m_HeroVie -= vieenmoins;
    if(m_HeroVie < 0)
    {
        m_HeroVie = 0;
    }
}

bool heros::vivant() const //  Savoir si le héros est vivant
{
    return (m_HeroVie>0);
}

bool heros::seProteger() // Pour protéger le joueur
{
    if(m_HeroProteger)
    {
        m_HeroProteger = false;
    }
    else
    {
        m_HeroProteger = true;
    }
}

void heros::Attaquer(heros &cible)  //  Méthode pour attaquer un monstre
{
    if(cible.m_HerosEspece != "humain" || cible.m_HerosEspece != "Humain" || cible.m_HerosEspece != "humains" || cible.m_HerosEspece != "Humains")
    {
        cible.DiminutionVie(m_HeroForce);
    }
    else
    {
        cout << "Vous ne pouvez pas attaquer votre allier !" << endl;
    }
}

void heros::Competence(heros &cible) {
    if(cible.m_HerosEspece != "humain" || cible.m_HerosEspece != "Humain" || cible.m_HerosEspece != "humains" || cible.m_HerosEspece != "Humains")
    {
        cible.DiminutionVie(m_HeroForce);
    }
    else
    {
        cout << "Vous ne pouvez pas attaquer votre allier !" << endl;
    }
}

void heros::Fuir() // Méthode qui permet de fuir un combat
{
    int ChangeDeFuir = rand() % 10 + 1;
    // Code
}

void heros::utiliserObjets(std::string objet) // Méthode qui permet de utiliser un objet
{
    if(objet == "Potion de Soins" || objet == "potion de soins")
    {
        m_HeroVie += 50;
    }
    else if(objet == "Potion de Attaque+" || objet == "potion de attaque+")
    {
        m_HeroForce += 15;
    }
}

void heros::TransfermHeros(heros &cible) // Faire transfère heros pour variable global
{
    m_HeroNom = cible.m_HeroNom;
    m_HeroVie = cible.m_HeroVie;
    m_Monnaie = cible.m_Monnaie;
    m_Heroclasse = cible.m_Heroclasse;
    m_HerosEspece = cible.m_HerosEspece;
    m_HeroFonctions = cible.m_HeroFonctions;
    m_HeroArmes = cible.m_HeroArmes;
    m_HeroForce = cible.m_HeroForce;
    m_HeroExp = cible.m_HeroExp;
    m_HeroProteger = false;
}

void heros::afficher() const // Méthode pour afficher les informations du héros
{
    if(vivant() == true)
    {
        cout << m_HerosEspece << " > " << m_HeroNom << " : " << m_HeroVie << " / vivant";
    }
    else
    {
        cout << m_HerosEspece << " > " << m_HeroNom << " : " << m_HeroVie << " / mort";
    }
}