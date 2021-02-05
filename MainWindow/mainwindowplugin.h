#ifndef MAINWINDOWPLUGIN_H
#define MAINWINDOWPLUGIN_H
#include <QObject>
#include "../includes/IWidgetManage.h"
#include "ctkPluginContext.h"
#include <QWidget>

class DataWidget;

class MainWindowPlugin : public QObject, public IWidgetManage
{
    Q_OBJECT
    Q_INTERFACES(IWidgetManage)
public:
    MainWindowPlugin(ctkPluginContext *context);
    ~MainWindowPlugin();
    virtual void ShowWidget();
private:
    ctkPluginContext *m_context;
    DataWidget* m_windowDlg;
};
#endif // MAINWINDOWPLUGIN_H
