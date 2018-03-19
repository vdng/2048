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
    engine.rootContext()->setContextProperty("vueObjectSco",&score);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

/********************************
 *          To do list          *
 ********************************
 *
 * **** Déroulement d'un tour ***
 *
 * - action_faite = false
 * - demander déplacement
 * - effectuer : déplacement
 *      -> màj du score
 *      -> gestion du mouvement
 *      -> interface graphique
 * - si action faite : apparition_tuile
 *
 *
 * *** Besoin de : ***
 *
 * Tuile
 * Score

*/
