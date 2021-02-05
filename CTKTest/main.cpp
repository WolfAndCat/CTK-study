#include <QApplication>
#include <QDebug>

#include "ctkPluginFrameworkLauncher.h"

#include "mainwindow.h"
#include "IWidgetManage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("ctkExaple");

    ctkPluginFrameworkLauncher::addSearchPath("../libs");
    if(!ctkPluginFrameworkLauncher::start("org.commontk.eventadmin"))
    {
        qDebug() << "ctkPluginFrameworkLauncher::start fail";
        qDebug() << "------------------------------------------";
    }

    //MainWindow mw;
    //mw.show();

    ctkPluginFrameworkFactory factory;

    QSharedPointer<ctkPluginFramework> framework;

    framework = factory.getFramework();

    try {
        framework->init();
        framework->start();
    } catch (const ctkPluginException& e) {
        qDebug() << "framework init fail";
        qDebug() << e.message() << e.getType();
    }

    ctkPluginFrameworkEvent fe = framework->waitForStop(1000);

    while (!fe.getErrorString().isEmpty())
    {
        qDebug() << fe.getErrorString();
        fe = framework->waitForStop(1000);
    }

    ctkPluginFrameworkLauncher::shutdown();

//    QString dir = QCoreApplication::applicationDirPath();

//    dir += "/plugins/MainWindow/MainWindow.dll";

//    qDebug() << dir;

//    QUrl url = QUrl::fromLocalFile(dir);
//    QSharedPointer<ctkPlugin> plugin;

//    try {
//        plugin = framework->getPluginContext()->installPlugin(url);
//    } catch (const ctkPluginException& e) {
//        qDebug() << e.message() << e.getType();
//    }

//    try {
//        plugin->start(ctkPlugin::START_TRANSIENT);
//    } catch (const ctkPluginException& e) {
//        qDebug() << e.message() << e.getType();
//    }

//    QString dir1 = QCoreApplication::applicationDirPath();

//    dir1 += "/plugins/Client1/Client1.dll";

//    qDebug() << dir1;

//    QUrl url1 = QUrl::fromLocalFile(dir1);
//    QSharedPointer<ctkPlugin> plugin1;

//    try {
//        plugin1 = framework->getPluginContext()->installPlugin(url1);
//    } catch (const ctkPluginException& e) {
//        qDebug() << e.message() << e.getType();
//    }

//    try {
//        plugin1->start(ctkPlugin::START_TRANSIENT);
//    } catch (const ctkPluginException& e) {
//        qDebug() << e.message() << e.getType();
//    }

//    ctkPluginContext* context = framework->getPluginContext();
//    ctkServiceReference ref =context->getServiceReference<IWidgetManage>();
//    IWidgetManage* mainWindow;
//    if(ref)
//        mainWindow = context->getService<IWidgetManage>(ref);
//    if(mainWindow)
//        mainWindow->ShowWidget();

    return a.exec();
}
