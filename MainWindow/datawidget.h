#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>

#include "ctkDictionary.h"

class ctkPluginContext;

namespace Ui {
class DataWidget;
}

class DataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataWidget(ctkPluginContext * context);
    ~DataWidget();

signals:
    void Signal_SendText(const ctkDictionary&);

private slots:
    void on_pushButton_send_clicked();

private:
    Ui::DataWidget *ui;

    ctkPluginContext * m_pContext;
};

#endif // DATAWIDGET_H
