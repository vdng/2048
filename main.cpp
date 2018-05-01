#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Grille grille;
    engine.rootContext()->setContextProperty("grille", &grille);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
