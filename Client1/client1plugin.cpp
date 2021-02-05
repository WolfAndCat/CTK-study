#include "client1plugin.h"

#include <QLabel>

#include "service/event/ctkEventConstants.h"

Client1Plugin::Client1Plugin(ctkPluginContext * context):m_context(context)
{
    m_pWgt = new QWidget;

    connect(this, SIGNAL(openDlg(int)), this, SLOT(slot_zmkm(int)), Qt::QueuedConnection);

    ctkDictionary dic;
    dic.insert(ctkEventConstants::EVENT_TOPIC, "zhimakaimen");
    context->registerService<ctkEventHandler>(this, dic);
}

void Client1Plugin::handleEvent(const ctkEvent &event)
{
    if(event.getTopic() == "zhimakaimen")
    {
        qDebug() << "emit openDlg()";

        emit openDlg(event.getProperty("test").toInt());
    }
}

void Client1Plugin::onOpenDlg()
{
    qDebug() << "onOpenDlg()";
    if(m_pWgt)
    {
        m_pWgt->show();
    }
}

void Client1Plugin::slot_zmkm(int iNum)
{
    qDebug() << "ok?";
    if(m_pWgt)
    {
        QLabel *lab = new QLabel;
        lab->setText(QString::fromStdString(std::to_string(iNum)));
        lab->setParent(m_pWgt);
        lab->move(0,0);
        m_pWgt->show();
    }
}
