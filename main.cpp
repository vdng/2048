#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "grille_transition.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Grille_Transition grille_transition;
    engine.rootContext()->setContextProperty("grille_transition", &grille_transition);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
