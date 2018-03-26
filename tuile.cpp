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

void Tuile::deplacer_gauche(vector<Tuile> L_tuile){
    bool peut_bouger = true;
    while (peut_bouger) {
        if (y==0){
            peut_bouger=false;
        }
        else{
            bool vide_gauche = true;
            int i=0;
            while (vide_gauche && i<L_tuile.size()){
                Tuile2=L_tuile[i];
                vide_gauche = (x==Tuile2.get_x() && y-1=Tuile2.get_y());
                i++;
            }
            if (vide_gauche){
                y=y-1;
            }
            else{
                if (valeur = Tuile2.get_val()){
                    fusion(Tuile2);
                    y=y-1;
                }
                else{
                    peut_bouger=false;
                }
            }
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
