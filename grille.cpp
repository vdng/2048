#include "grille.h"
#include <QTime>
#include <QTimer>

#include <iostream>
using namespace std;

Grille::Grille(QObject *parent) :
    QObject(parent) {
    init_rand();
    debut_jeu();
}

void Grille::debut_jeu() {
    memset(grille_, 0, sizeof(grille_));
    score_ = 0;
    tuile_max_ = 0;
    // On fait apparaître deux tuiles
    new_tuile();
    new_tuile();
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




/* Explication du fonctionnement du mouvement :
 * Pour s'épargner d'écrire 4 fois la même fonction à quelques détails près, on utilise la rotation;
 * On n'implémente en vérité qu'une seule méthode de mouvement (vers le haut : tout_bouger_haut)
 * Et pour les autres mouvements, on fait tourner la grille de Tuiles (rotation à droite) : assez de fois pour que le mouvement à effectuer soit vers le haut.
 * Puis on termine la rotation pour tout remettre dans l'ordre
 */

bool Grille::move(int direction) { // 0 pour haut, 1 pour gauche, 2 pour bas, 3 pour droite
    bool mouvement_possible = false;

    int i;
    for(i = 0; i < direction; i++) {
        rot_droite(); // Rotations jusqu'à ce que le mouvement se fasse en haut
    }
    mouvement_possible = tout_bouger_haut(); // On effectue le mouvement (et on en profite pour savoir si c'est possible ou pas
    for(i = direction; i <= 3; i++) {
        rot_droite(); // On termine la rotation pour revenir dans le bon sens
    }
    if (mouvement_possible) { // Si un mouvement est effectivement fait
        new_tuile(); // On génère une nouvelle tuile
        emit mouvement_fait(); // Il faut signaler que le mouvement est fait, pour que ce soit mis à jour
    }

    if(a_gagne() || finJeu()) { // Si c'est fini, il faut le signaler
        emit fin_ou_gagne();
        return false; // Et aucun mouvement n'est alors possile
    }

    return mouvement_possible; // On retourne le fait que le mouvement ait été effectué
}

bool Grille::moveUp() {
    return move(0);
}

bool Grille::moveLeft() {
    return move(1);
}

bool Grille::moveDown() {
    return move(2);
}

bool Grille::moveRight() {
    return move(3);
}


// Méthode effectuant la rotation à droite
void Grille::rot_droite() {
    int i, j;
    int tmp; // Variable temporaire servant à retenir la tuile (i,j)
    for (i = 0; i < 2; i++) {
        for (j = i; j < 4 - i - 1; j++) {
            tmp = grille_[i][j];
            grille_[i][j] = grille_[j][4-i-1];
            grille_[j][4-i-1] = grille_[4-i-1][4-j-1];
            grille_[4-i-1][4-j-1] = grille_[4-j-1][i];
            grille_[4-j-1][i] = tmp;
        }
    }
}

// Voici donc la vraie méthode de mouvement
bool Grille::tout_bouger_haut() {
    if (a_gagne() || finJeu()) { // Si le jeu est fini on ne fait rien (même en cas de victoire)
        return false;
    }
    bool peut_bouger = false; // Teste si le mouvement est possible
    int x;
    for (x = 0; x < 4; x++) { // On parcoure les colonnes
        peut_bouger |= mouvement(grille_[x]); // Pour chacune des colonnes, on effectue le mouvement (et peu_bouger devient vraie à partir du premier mouvement effectué
    }
    return peut_bouger; // On renvoie le fait que ça ait bougé ou pas
}

void Grille::init_rand() {
    auto time = QTime::currentTime();
    qsrand((uint) time.msec());
}



bool Grille::mouvement(int colonne[4]) { // Effectue le mouvement vers le haut sur une colonne
    bool peut_bouger = false;
    int position, fut_pos, stop = 0;
    // position parcoura les positions des tuiles dans la colonne
    // fut_pos indique quelle est la position que la tuile aura après le mouvement
    // stop est une valeur de contrôle, à ne pas dépasser (utile dans "future_position")

    int valeur_fusion; // Donne la nouvelle valeur après fusion entre deux Tuiles

    for (position = 0; position < 4; position++) { // On parcoure les positions
        if (colonne[position] != 0) { //Cas où on n'est pas tout en haut (car alors, aucun mouvement n'est possible, elle est à l'extrémité
            fut_pos = future_position(colonne, position, stop); // Donne la future position de la Tuile en mouvement
            if (fut_pos != position) { // Si il y a effectivement un mouvement (sinon, rien à faire)
                if (colonne[fut_pos] != 0) { // Dans le cas où la Tuile va à l'extrémité, c'est tout bon, il n'y a rien à faire. Sinon :
                    stop = fut_pos + 1; // Pour contrôler qu'on ne chevauche pas les Tuiles
                    valeur_fusion = colonne[fut_pos] + colonne[position]; // On calcule la somme les valeurs
                    score_ += valeur_fusion; // On rajoute cette valeur au score
                    emit chgt_score(); // On signale le changement de score
                    tuile_max_ = max(tuile_max_, valeur_fusion); // On emt à jour si nécessaire la valeur maximale de tuile
                }
                colonne[fut_pos] += colonne[position]; // On met à jour la valeur dans la nouvelle position (avec fusion si nécessaire)
                colonne[position] = 0; // La position d'où elle vient est vide : on le met à 0
                peut_bouger = true; // On a effectivement bougé
            }
        }
    }

    return peut_bouger;
}

int Grille::future_position(int colonne[4], const int position, const int stop) const {
// Donne, dans une colonne colonne, pour la Tuile en position position, la future position après le mouvement. stop étant la limite (pour éviter un chevauchement)
    int fut_pos; // La future position
    if (position == 0) {
        return position; // On ne peut pas aller plus loin que l'extrémité
    }
    for (fut_pos = position - 1; fut_pos >= 0; fut_pos--) { // On parcoure les futures positions possibles dans le bon ordre, du plus proche au plus loin)
        if (colonne[fut_pos] != 0) { //Si la case n'est pas vide
            if (colonne[fut_pos] != colonne[position]) { // Et si elle n'a pas la même valeur
                return fut_pos + 1; // Dans ce cas, il faut aller juste avant cette case
            }
            // Si elle a la même valeur, on peut la renvoyer comme future position
            return fut_pos;
        } else { // Si la case est vide
            if (fut_pos == stop) { // On vérifie qu'on ne va pas trop loin
                return fut_pos;
            }
        }
    }
    return position; // Si il ne s'est rien passé, on ne bouge pas, on renvoie position
}


// Pour tester si au moins deux sont égaux et adjacents dans la grille (selon la verticale seulement)
bool Grille::deux_egaux() const {
    bool aumoinsdeux = false;
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - 1; j++) {
            if (grille_[i][j] == grille_[i][j+1]) {
                aumoinsdeux = true; // en cas d'égalité, c'est bon
            }
        }
    }

    return aumoinsdeux;
}

int Grille::nb_cases_vides() const { // On compte le nombre de cases vides
    int i, j;
    int count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (grille_[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

bool Grille::finJeu() { // test si on est bloqué (et donc c'est la défaite)
    bool perdu = true;
    if (nb_cases_vides() > 0) { // On n'a pas encore perdu si il y a plus d'une case non vide
        return false;
    }
    if (deux_egaux()) { // On n'a pas perdu si il y a encore deux Tuiles adjacentes qu'on peut fusionner selon la verticale
        return false;
    }
    rot_droite(); // Il faut aussi vérifier selon l'horizontale
    if (deux_egaux()) {
        perdu = false;
    }
    rot_droite();
    rot_droite();
    rot_droite();// On a remis dans le bon sens
    return perdu;
}

bool Grille::a_gagne() {
    return tuile_max_ == 2048;
}
