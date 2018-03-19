#include "tuile.h"

Tuile::Tuile(QObject *parent) : QObject(parent)
{
    valeur = 2;
    couleur = 4c4545;
}

void Tuile::fusion(Tuile Tuile2){
    valeur *= 2;
}

void Tuile::get_val(){
    return valeur;
}

void Tuile::deplacer_gauche(){

}

void Tuile::deplacer_droite(){

}

void Tuile::deplacer_haut(){

}

void Tuile::deplacer_bas(){

}

void Tuile::get_x(){
    return x;
}

void Tuile::get_y(){
    return y;
}
