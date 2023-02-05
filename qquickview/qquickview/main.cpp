#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.rootContext()->setContextProperty("this_title", QStringLiteral("abc example"));
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();


    return app.exec();
}
