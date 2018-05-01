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

    void debut_jeu(); // Permet d'initier le jeu
    void init_rand(); // Nécessaire pour utiliser l'aléatoir
};

#endif // GRILLE_H
