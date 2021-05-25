#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = ui->downloadView;

    Py_Initialize();
    if(!Py_IsInitialized())
    {
        qDebug() << "Qt initialized faild";
        return;
    }

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
        QObject::connect(newDlg,&NewDialog::setMission,this,&MainWindow::startMission);
        newDlg->exec();

    });

    //转码
    QObject::connect(ui->convertButton,&QPushButton::clicked,[&](){
        convertDlg = new ConvertDialog();
        QObject::connect(convertDlg,&ConvertDialog::startConvert,this,&MainWindow::convertMedia);
        convertDlg->exec();

    });
}

MainWindow::~MainWindow()
{
    Py_Finalize();
    delete ui;
}

/*
* you-get -o dir url
* youtube-dl -o dirTemplate url
*/


void MainWindow::startMission(QString url,QString filePath)
{
    newDlg->hide();
    delete newDlg;
    //QTableWidgetItem *download = new QTableWidgetItem();
    //download->set

    PyRun_SimpleString("import you_get");
    PyRun_SimpleString("import youtube_dl");





    qDebug() << url << ", " << filePath;
}

void MainWindow::convertMedia(QString command)
{
    //QProcess *work = new QProcess();
    //work->start("ffmpeg");
}



