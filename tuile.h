#ifndef TUILE_H
#define TUILE_H

#include <QObject>

class Tuile : public QObject
{
    Q_OBJECT
public:
    explicit Tuile(QObject *parent = nullptr);
    Q_INVOKABLE void fusion(Tuile Tuile2);
    int get_val();
    Q_INVOKABLE void deplacer_gauche(vector<Tuile> L_tuile);
    Q_INVOKABLE void deplacer_droite();
    Q_INVOKABLE void deplacer_haut();
    Q_INVOKABLE void deplacer_bas();
    int get_x();
    int get_y();

private:
    int valeur;
    int couleur;
    int x;
    int y;


signals:

public slots:
};

#endif // TUILE_H
