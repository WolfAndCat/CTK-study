#ifndef CLIENT1PLUGIN_H
#define CLIENT1PLUGIN_H

#include <QObject>
#include <QWidget>

#include "ctkPluginContext.h"
#include "service/event/ctkEventAdmin.h"
#include "service/event/ctkEventHandler.h"

class Client1Plugin : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)
public:
    Client1Plugin(ctkPluginContext *context);

protected:
    void handleEvent(const ctkEvent &event) override;

signals:
    void openDlg(int a);

private slots:
    void onOpenDlg();
    void slot_zmkm(int);

private:
    void registToMainWindow();
    ctkPluginContext *m_context;
    QWidget *m_pWgt;
};

#endif // CLIENT1PLUGIN_H
