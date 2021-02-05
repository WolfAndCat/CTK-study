#include "client1activator.h"

#include "client1plugin.h"
#include "clientplugin.h"

Client1Activator::Client1Activator()
{

}

void Client1Activator::start(ctkPluginContext *context)
{
    qDebug() << "Client1Activator start";

    m_plugin = new Client1Plugin(context);

    m_pPlugin = new ClientPlugin;
    m_pPlugin->SetWidgetContext(context);
    ctkDictionary dic;
    context->registerService<IWidgetManage>(m_pPlugin, dic);
}

void Client1Activator::stop(ctkPluginContext *context)
{
    if(m_plugin)
    {
        delete m_plugin;
    }
}
