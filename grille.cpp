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

int Grille::new_val() const { // Choisit une nouvelle valeur pour une nouvelle tuile
    if (qrand()%10 == 9) { return 4;} else {return 2;}
}

void Grille::new_tuile() { // Génère une nouvelle tuile
    int i, j;
    int liste_tuiles_libres[16][2]; // Liste des coordonnées des emplacements libres pour une nouvelle tuile (au maximum le nombre de tuiles)
    int longueur = 0; //Longeur de la liste
    int que_choisir; // L'indice futur de choix de l'emplacement pour la nouvelle tuile

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(grille_[i][j] == 0) {
                liste_tuiles_libres[longueur][0] = i;
                liste_tuiles_libres[longueur][1] = j; // On enregistre les emplacements libres
                longueur++; // Et on augmente la taille (pour savoir combien on en a)
            }
        }
    }

    if (longueur > 0) { // Si il y a au moins un emplacement libre
        que_choisir = qrand() % longueur; // On choisit au hasard le nouvel emplacement
        i = liste_tuiles_libres[que_choisir][0];
        j = liste_tuiles_libres[que_choisir][1];
        grille_[i][j] = new_val(); // On créé la nouvelle tuile avec sa nouvelle valeur
    }
}

void Grille::debut_jeu() {
    memset(grille_, 0, sizeof(grille_));
    score_ = 0;
    tuile_max_ = 0;
    // On fait apparaître deux tuiles
    new_tuile();
    new_tuile();
}


void Grille::init_rand() {
    auto time = QTime::currentTime();
    qsrand((uint) time.msec());
}
