#include "tuile.h"
#include <time.h>

Tuile::Tuile(QObject *parent) : QObject(parent)
{
    srand(time(NULL));
    int rando = rand() % 100;
    if rando>70{
        valeur=4;
    }
    else{
        valeur=2;
    }
    x=coord_x;
    y=coord_y;
}

void Tuile::fusion(Tuile Tuile2){
    valeur*=2;
    delete Tuile2;
}

void Tuile::get_val(){
    return valeur;
}

void Tuile::deplacer_gauche(){
    bool peut_bouger = true;
    while (peut_bouger) {
        if (y==0){
            peut_bouger=false;
        }
        else{

        }

    }
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
