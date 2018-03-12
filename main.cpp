#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "score.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    Score score;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("vueObjectCpt",&score); // On crée un objet vueObjectCpt lié à notre compteur
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
