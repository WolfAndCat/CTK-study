/********************************************************************************
** Form generated from reading UI file 'datawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWIDGET_H
#define UI_DATAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWidget
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *DataWidget)
    {
        if (DataWidget->objectName().isEmpty())
            DataWidget->setObjectName(QString::fromUtf8("DataWidget"));
        DataWidget->resize(400, 300);
        listWidget = new QListWidget(DataWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 40, 256, 192));

        retranslateUi(DataWidget);

        QMetaObject::connectSlotsByName(DataWidget);
    } // setupUi

    void retranslateUi(QWidget *DataWidget)
    {
        DataWidget->setWindowTitle(QCoreApplication::translate("DataWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataWidget: public Ui_DataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWIDGET_H
