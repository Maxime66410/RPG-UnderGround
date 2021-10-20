#ifndef RPGUNDERGROUND_COMBAT_H
#define RPGUNDERGROUND_COMBAT_H


class combat {
public:
    void SiLeJoueurAGagner(); // La fonction lancer si le joueur Gagne
    void SiLeJoueurAPerdu();    // La fonction lancer si le joueur Perd
    void Attaquer();    // Fonction Attaquer
    void Speciale();    // Fonction Attaque Spéciale
    void Inventaire();  // Fonction Inventaire (Utilisation / Regarder)
    void CheckLaPartie();   // Fonction qui regarde les statistique de la partie
    void CreationJoueurEtPersonnage();  // Création du joueur ainsi que de l'ennemie
    void EnemieAttaqueJoueurItem(); // Fonction qui permet de dire si l'ennemie attaque le joueur après l'utilisation d'un objet.
    void sauvegarderLesData(); // Sauvegarde des Data du joueurs si il gagne
    void Game(); // Base du script qui relie toute les fonctions
    void InitialisationGame();  // Initialisation des Data du joueur
};


#endif //RPGUNDERGROUND_COMBAT_H
