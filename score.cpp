#include "score.h"

Score::Score(QObject *parent) : QObject(parent){
    sco = 0;
    emit scoreChanged();
}

void Score::maj(){
    emit scoreChanged();
}

QString Score::readScore(){
    return QString::number(sco);
}
