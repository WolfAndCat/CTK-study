#ifndef CLIENTPLUGIN_H
#define CLIENTPLUGIN_H

#include <QObject>

#include "../includes/IWidgetManage.h"

class DataWidget;
class ctkPluginContext;

class ClientPlugin : public QObject, public IWidgetManage
{
    Q_OBJECT
    Q_INTERFACES(IWidgetManage);

public:
    ClientPlugin();

    void SetWidgetContext(ctkPluginContext *pluginContext);

    void ShowWidget() override;

private:
    DataWidget * m_pDataWgt;
};

#endif // CLIENTPLUGIN_H
