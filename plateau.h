#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>

class Plateau : public QObject
{
    Q_OBJECT
public:
    explicit Plateau(QObject *parent = nullptr);
    vector<Tuile> liste_tuiles;



signals:

public slots:
};

#endif // PLATEAU_H
