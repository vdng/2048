#ifndef GRILLE_H
#define GRILLE_H

#include <QTime>
#include <QTimer>

#include <QObject>

class Grille : public QObject
{
    Q_OBJECT
public:
    explicit Grille(QObject *parent = nullptr);

    void afficher() const; // Fonction d'affichage pour les tests

    int get(const int x, const int y) const; // Obtenir la valeur de la tuile (x,y)
    int get_score() const; // Donne le score

signals:

public slots:

private :
    int grille_[4][4]; // Valeurs des tuiles
    int score_;
    int tuile_max_; //Valeur la plus haute des tuiles

    int new_val() const; // Génère une nouvelle valeur de tuile (1/10 de 4 et 9/10 de 2)
    void new_tuile(); // Créé une nouvelle tuile

    void debut_jeu(); // Permet d'initier le jeu
    void init_rand(); // Nécessaire pour utiliser l'aléatoir
};

#endif // GRILLE_H
