#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>

#include "../includes/IWidgetManage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    framework = factory.getFramework();

    try {
        framework->init();
        framework->start();
    } catch (const ctkPluginException& e) {
        qDebug() << "framework init fail";
        qDebug() << e.message() << e.getType();
    }

    //m_spPlugins.clear();

    QString strPath = QApplication::applicationDirPath() + "/plugins";
    GetDLL(strPath);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (framework) {
        framework->stop();
    }
}

bool MainWindow::LoadDLL(QString strDLL)
{
    qDebug() << strDLL;
    QUrl url = QUrl::fromLocalFile(strDLL);
    QSharedPointer<ctkPlugin> plugin;

    try {
        plugin = framework->getPluginContext()->installPlugin(url);
    } catch (const ctkPluginException& e) {
        qDebug() << e.message() << e.getType();
        return false;
    }

    try {
        plugin->start(ctkPlugin::START_TRANSIENT);
    } catch (const ctkPluginException& e) {
        qDebug() << e.message() << e.getType();
        return false;
    }

    //m_spPlugins.append(plugin);
    return true;
}

bool MainWindow::RunDll()
{
    ctkPluginContext* context = framework->getPluginContext();
    auto refs =context->getServiceReferences<IWidgetManage>();

    qDebug() << "------------------------------------------------";

    for(auto ref:refs)
    {
        IWidgetManage* mainWindow;
        if(ref)
            mainWindow = context->getService<IWidgetManage>(ref);
        if(mainWindow)
        {
            mainWindow->ShowWidget();
            //return true;
        }
    }

//    for(auto pugin : m_spPlugins)
//    {
//        ctkPluginContext* context = pugin->getPluginContext();
//        ctkServiceReference ref =context->getServiceReference<IWidgetManage>();
//        IWidgetManage* mainWindow;
//        if(ref)
//            mainWindow = context->getService<IWidgetManage>(ref);
//        if(mainWindow)
//        {
//            mainWindow->ShowWidget();
//            return true;
//        }
//    }

    return false;
}

void MainWindow::GetDLL(QString strPath)
{
    if(strPath.isEmpty())
    {
        return;
    }

    QDir dir(strPath);
    dir.setFilter(QDir::Files);
    dir.setNameFilters(QStringList() << "*.dll");
    QFileInfoList fil = dir.entryInfoList();

    QStringList strDlls;
    for(auto fi : fil)
    {
        strDlls.append(fi.fileName());
    }

    m_strPath = strPath;
    ui->lineEdit->setText(strPath);
    ui->listWidget_load->clear();
    ui->listWidget_unload->clear();
    ui->listWidget_unload->addItems(strDlls);
}

void MainWindow::on_pushButton_install_clicked()
{
    int iRow = ui->listWidget_unload->currentRow();
    if(iRow > -1)
    {
        QString strDll = ui->listWidget_unload->currentItem()->text();
        if(LoadDLL(m_strPath + "/" + strDll))
        {
            ui->listWidget_load->addItem(ui->listWidget_unload->takeItem(iRow));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString strPath = QFileDialog::getExistingDirectory(this);
    if(!strPath.isEmpty())
    {
        GetDLL(strPath);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    RunDll();
}

void MainWindow::on_pushButton_uninstall_clicked()
{
    int iRow = ui->listWidget_load->currentRow();
    if(iRow > -1)
    {
        QString strDll = ui->listWidget_load->currentItem()->text();

       /* for(auto plugin: m_spPlugins)
        {
            if(strDll.left(strDll.size() - 4) == plugin->getSymbolicName())
            {
                plugin->uninstall();
                m_spPlugins.removeOne(plugin);
                ui->listWidget_unload->addItem(ui->listWidget_load->takeItem(iRow));
                break;
            }
        }*/
    }
}
