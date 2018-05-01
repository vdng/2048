#ifndef GRILLE_H
#define GRILLE_H

#include <QTime>
#include <QTimer>

#include <QObject>

class Grille : public QObject
{
    Q_OBJECT
public:
    explicit Grille(QObject *parent = 0);

    void afficher() const; // Fonction d'affichage pour les tests

    int get(const int x, const int y) const; // Obtenir la valeur de la tuile (x,y)
    int get_score() const; // Donne le score

    bool finJeu(); // Retourne vrai si le joueur est bloqué (auquel cas il perd)
    bool a_gagne(); // Retourne vrai si le joueur a gagné

    bool moveUp(); // Mouvement vers le haut
    bool moveRight(); // Mouvement vers la droite
    bool moveDown(); // Mouvement vers le bas
    bool moveLeft(); // Mouvement vers la gauche

signals:

    void mouvement_fait(); //Dès qu'un mouvement est fait
    void chgt_score(); // A chaque changement de score
    void fin_ou_gagne(); // Dès que ça change d'état : le jeu est fini (gagné ou pas)


public slots:

private :
    int grille_[4][4]; // Valeurs des tuiles
    int score_;
    int tuile_max_; //Valeur la plus haute des tuiles

    int new_val() const; // Génère une nouvelle valeur de tuile (1/10 de 4 et 9/10 de 2)
    void new_tuile(); // Créé une nouvelle tuile

    void debut_jeu(); // Permet d'initier le jeu
    void init_rand(); // Nécessaire pour utiliser l'aléatoire

    bool move(int direction); // Effectue un mouvement (0 pour haut, 1 pour gauche, 2 pour bas, 3 pour droite
    void rot_droite(); //Fait faire une rotation vers la droite (expliqué dans le cpp)
    bool tout_bouger_haut(); // Gère tout ce qui concerne le mouvement vers le haut : déplacements et fusions
    bool mouvement(int array[4]); // Effectue le mouvement d'une colonne (dans la array), et retourne false s'il n'y a aucun mouvement

    int future_position(int array[4], const int pos, const int stop) const; // Donne, dans le mouvement, la future position de la tuile en position pos
    bool deux_egaux() const; //Test si dans la grille, au moins deux tuiles adjacentes verticalement sont égaes
    int nb_cases_vides() const; // Compte le nombre de tuiles vides
};

#endif // GRILLE_H
