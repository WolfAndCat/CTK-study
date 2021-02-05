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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;

    void setupUi(QWidget *DataWidget)
    {
        if (DataWidget->objectName().isEmpty())
            DataWidget->setObjectName(QString::fromUtf8("DataWidget"));
        DataWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(DataWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView = new QListView(DataWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(DataWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_send = new QPushButton(DataWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DataWidget);

        QMetaObject::connectSlotsByName(DataWidget);
    } // setupUi

    void retranslateUi(QWidget *DataWidget)
    {
        DataWidget->setWindowTitle(QCoreApplication::translate("DataWidget", "Form", nullptr));
        pushButton_send->setText(QCoreApplication::translate("DataWidget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataWidget: public Ui_DataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWIDGET_H
