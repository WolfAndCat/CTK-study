#include "mainwindowplugin.h"


#include "service/event/ctkEvent.h"
#include "service/event/ctkEventAdmin.h"
#include "service/event/ctkEventHandler.h"

#include "datawidget.h"

MainWindowPlugin::MainWindowPlugin(ctkPluginContext *context)
    :m_context(context)
{
    m_windowDlg = new DataWidget(context);
}

MainWindowPlugin::~MainWindowPlugin()
{
    if(m_windowDlg)
    {
        delete m_windowDlg;
    }
}
void MainWindowPlugin::ShowWidget()
{
    //m_windowDlg->show();
//    ctkServiceReference ref;
//    ctkEventAdmin* eventAdmin;
//    ref = m_context->getServiceReference<ctkEventAdmin>();
//    if(ref)
//    {
//        qDebug() << "getService<ctkEventAdmin>";
//        eventAdmin = m_context->getService<ctkEventAdmin>(ref);
//        m_context->ungetService(ref);
//    }

//    ctkDictionary message;
//    if(eventAdmin)
//    {
//        qDebug() << "eventAdmin->postEvent();";
//        message.insert("test", 5201314);
//        eventAdmin->postEvent(ctkEvent("zhimakaimen", message));
//    }

    m_windowDlg->show();

    qDebug() << "ShowWidget mainwindow";
}
