#ifndef GRILLE_TRANSITION_H
#define GRILLE_TRANSITION_H

#include <QAbstractListModel>
#include "grille.h"

/* Cette classe a été crée suite à un problème rencontré :
 *  dans le QML, les cases sont indicées de 0 à 15 alors que dans grille.cpp, elles sont identifiées par leurs coordonnées (x,y)
 * Cette classe sert donc de transition entre les deux fonctionnements
 */

class Grille_Transition : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int get_score READ get_score NOTIFY chgt_score)
    Q_PROPERTY(bool finJeu READ finJeu NOTIFY fin_ou_gagne)
    Q_PROPERTY(bool a_gagne READ a_gagne NOTIFY fin_ou_gagne)

public:
    explicit Grille_Transition(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    // Ce sont les mêmes méthodes que dans Grille
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();

    int get_score() const;

    bool finJeu();
    bool a_gagne();

signals:
    void chgt_score();
    void fin_ou_gagne();


public slots:
    void chgt_donnee();

private:
    Grille grille_;

};

#endif // GRILLE_TRANSITION_H
