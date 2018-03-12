#ifndef SCORE_H
#define SCORE_H

#include <QObject>

class Score : public QObject
{
    Q_OBJECT
public:
    explicit Score(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SCORE_H