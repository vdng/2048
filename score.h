#ifndef SCORE_H
#define SCORE_H

#include <QObject>

class Score : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString scoQML READ readScore NOTIFY scoreChanged)

public:
    explicit Score(QObject *parent = nullptr);
    Q_INVOKABLE void maj();

    QString readScore();

signals:
    void scoreChanged();

public slots:

private:
    int sco;
};

#endif // SCORE_H
