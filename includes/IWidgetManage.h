#ifndef WIDGETMANAGE_H
#define WIDGETMANAGE_H

#include <QObject>

class IWidgetManage
{
public:
    virtual void ShowWidget() = 0;
};


Q_DECLARE_INTERFACE(IWidgetManage, "interface_mainwindow")

#endif // WIDGETMANAGE_H
