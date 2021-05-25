#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = ui->downloadView;

    table->setColumnCount(2);
    QStringList header;
    header << QString::fromLocal8Bit("任务名") << QString::fromLocal8Bit("下载进度");
    table->setHorizontalHeaderLabels(header);
    table->setColumnWidth(0,200);
    table->setColumnWidth(1,400);







    // 关于
    QObject::connect(ui->aboutButton,&QPushButton::clicked,[&](){
        aboutDlg = new AboutDialog();
        aboutDlg->exec();
    });

    // 新任务
    QObject::connect(ui->newButton,&QPushButton::clicked,[&](){
        newDlg = new NewDialog();
        newDlg->exec();
        QObject::connect(newDlg,&NewDialog::setMission,this,&MainWindow::startMission);
    });

    //转码
    QObject::connect(ui->convertButton,&QPushButton::clicked,[&](){
        convertDlg = new ConvertDialog();
        convertDlg->exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startMission(QString url,QString filePath)
{
    newDlg->hide();
    delete newDlg;
    //QTableWidgetItem *download = new QTableWidgetItem();
    //download->set
    qDebug() << url << ", " << filePath;
}

void MainWindow::convertMedia()
{

}



