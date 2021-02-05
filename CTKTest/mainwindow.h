#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "ctkPluginException.h"
#include "ctkPluginContext.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_install_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_uninstall_clicked();

private:
    bool LoadDLL(QString strDLL);
    bool RunDll();
    void GetDLL(QString strPath);

private:
    Ui::MainWindow *ui;

    ctkPluginFrameworkFactory factory;
    QSharedPointer<ctkPluginFramework> framework;

    QString m_strPath;
    //QList<QSharedPointer<ctkPlugin>> m_spPlugins;
};

#endif // MAINWINDOW_H
