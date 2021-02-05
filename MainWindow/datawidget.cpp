#include "datawidget.h"
#include "ui_datawidget.h"
#include "ctkServiceReference.h"
#include "ctkPluginContext.h"
#include "service/event/ctkEventAdmin.h"

DataWidget::DataWidget(ctkPluginContext * context) :
    m_pContext(context),
    ui(new Ui::DataWidget)
{
    ui->setupUi(this);

    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();

    if(ref)
    {
        ctkEventAdmin * evenAdmin = context->getService<ctkEventAdmin>(ref);
        evenAdmin->publishSignal(this, SIGNAL(Signal_SendText(ctkDictionary)), "MainWindow/DataWidget/signal", Qt::QueuedConnection);
    }
}

DataWidget::~DataWidget()
{
    delete ui;
}

void DataWidget::on_pushButton_send_clicked()
{
    ctkDictionary info;
    info.insert("SendMessage", ui->lineEdit->text());
    emit Signal_SendText(info);
    ui->lineEdit->clear();
}
