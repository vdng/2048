#include "grille_transition.h"

Grille_Transition::Grille_Transition(QObject *parent) :
    QAbstractListModel(parent)
{
    connect(&grille_, &Grille::mouvement_fait, this, &Grille_Transition::chgt_donnee);
    connect(&grille_, &Grille::chgt_score, this, &Grille_Transition::chgt_score);
    connect(&grille_, &Grille::fin_ou_gagne, this, &Grille_Transition::fin_ou_gagne);
}

int Grille_Transition::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)

    return 16;
}

QVariant Grille_Transition::data(const QModelIndex &index, int role) const {
    int x, y;
    if (index.row() < 0 || index.row() >= 4 * 4) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        x = index.row() % 4;
        y = index.row() / 4;
        QString str = QString::number(grille_.get(x, y));
        return str;
    }
    return QVariant();
}

void Grille_Transition::moveUp() {
    grille_.moveUp();
}

void Grille_Transition::moveRight() {
    grille_.moveRight();
}

void Grille_Transition::moveDown() {
    grille_.moveDown();
}

void Grille_Transition::moveLeft() {
    grille_.moveLeft();
}

void Grille_Transition::chgt_donnee() {
    emit dataChanged(createIndex(0, 0), createIndex(15, 0));
}

int Grille_Transition::get_score() const {
    return grille_.get_score();
}

bool Grille_Transition::finJeu() {
    return grille_.finJeu();
}

bool Grille_Transition::a_gagne() {
    return grille_.a_gagne();
}
