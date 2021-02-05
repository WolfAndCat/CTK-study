#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>

namespace Ui {
class DataWidget;
}

#include "ctkDictionary.h"

class ctkPluginContext;
class ctkEvent;

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataWidget(ctkPluginContext *pluginContext);
    ~DataWidget();

private slots:
    void Slot_Receive(const ctkEvent& event);

private:
    Ui::DataWidget *ui;

    ctkPluginContext *m_pPluginContext;
};

#endif // DATAWIDGET_H
