#include "grille.h"

#include <iostream>
using namespace std;

Grille::Grille(QObject *parent) : QObject(parent)
{
    init_rand();
    debut_jeu();
}

// Fonction d'affichage, pour les tests (utile avant de programmer l'affichage)
void Grille::afficher() const {
    cout << endl;
    int i, j;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            cout << grille_[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int Grille::get(const int x, const int y) const {
    return grille_[x][y];
}

int Grille::get_score() const {
    return score_;
}

void Grille::debut_jeu() {
    memset(grille_, 0, sizeof(grille_));
    score_ = 0;
    tuile_max_ = 0;
}


void Grille::init_rand() {
    auto time = QTime::currentTime();
    qsrand((uint) time.msec());
}
