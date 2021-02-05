#include "mainwindowactivator.h"
#include <QDebug>

#include "mainwindowplugin.h"

MainWindowActivator::MainWindowActivator()
{

}

void MainWindowActivator::start(ctkPluginContext *context)
{
    m_plugin = new MainWindowPlugin(context);
    ctkDictionary dic;
    context->registerService<IWidgetManage>(m_plugin, dic);
}

void MainWindowActivator::stop(ctkPluginContext *context)
{
    if(m_plugin)
    {
        delete m_plugin;
    }
}
