#ifndef CLIENT1ACTIVATOR_H
#define CLIENT1ACTIVATOR_H

#include <QObject>

#include "ctkPluginActivator.h"

class Client1Plugin;
class ClientPlugin;

class Client1Activator : public QObject, public ctkPluginActivator
{
public:
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Client1")
    Q_INTERFACES(ctkPluginActivator)

public:
    Client1Activator();

    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

    Client1Plugin * m_plugin;
    ClientPlugin *m_pPlugin;
};

#endif // CLIENT1ACTIVATOR_H
