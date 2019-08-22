#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <QImageWriter>
#include <QImage>
#include <QtWebView>
#include "appmanager.h"
#include "imageprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QtWebView::initialize();
    AppManager *appManager = new AppManager();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QLatin1String("appManager"), appManager);
    ImageProvider *imageProvider = new ImageProvider();
    engine.addImageProvider("imageprovider",imageProvider);
    qputenv("QML_DISABLE_DISK_CACHE", "1"); // or
    qputenv("QML_DISABLE_DISK_CACHE", "true");
    QScreen *screen = app.screens()[0];
    appManager->screenPointer = screen;
    double dpi = screen->physicalDotsPerInch();
    dpi-= dpi * 10/100;
    if(dpi >= 640) dpi = dpi/640; //xxxhdpi
    else if (dpi >= 480) dpi = dpi/480; //xxhdpi
    else if (dpi >= 320) dpi = dpi/320; //xhdpi
    else if (dpi >= 240) dpi = dpi/240; //hdpi
    else if (dpi >= 160) dpi = dpi/160; //mdpi
    else if (dpi >= 120) dpi = dpi/120; //ldpi
    else{
        dpi = 1;//ldpi
    }

    engine.rootContext()->setContextProperty("dpiToPixelValue",dpi);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
