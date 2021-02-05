#include "clientplugin.h"

#include <QDebug>

#include "datawidget.h"

ClientPlugin::ClientPlugin()
{

}

void ClientPlugin::SetWidgetContext(ctkPluginContext *pluginContext)
{
    m_pDataWgt = new DataWidget(pluginContext);
}

void ClientPlugin::ShowWidget()
{
    qDebug() << "ShowWidget client";
    m_pDataWgt->show();
}
