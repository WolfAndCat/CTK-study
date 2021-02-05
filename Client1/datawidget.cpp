#include "datawidget.h"
#include "ui_datawidget.h"
#include "ctkPluginContext.h"
#include "service/event/ctkEventConstants.h"
#include "service/event/ctkEventAdmin.h"

DataWidget::DataWidget(ctkPluginContext *pluginContext) :
    m_pPluginContext(pluginContext),
    ui(new Ui::DataWidget)
{
    ui->setupUi(this);

    ctkDictionary props;
    props.insert(ctkEventConstants::EVENT_TOPIC, "MainWindow/DataWidget/signal");
    ctkServiceReference ref = pluginContext->getServiceReference<ctkEventAdmin>();
    if(ref)
    {
        ctkEventAdmin* eventAdmin = pluginContext->getService<ctkEventAdmin>(ref);
        eventAdmin->subscribeSlot(this, SLOT(Slot_Receive(const ctkEvent &)), props, Qt::QueuedConnection);
    }
}

DataWidget::~DataWidget()
{
    delete ui;
}

void DataWidget::Slot_Receive(const ctkEvent& event)
{
    ui->listWidget->addItem(event.getProperty("SendMessage").toString());
}
