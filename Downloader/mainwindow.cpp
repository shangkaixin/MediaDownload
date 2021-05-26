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

    // 检测是否为第一次使用，并搭建环境






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
    delete ui;
}

/*
* you-get -o dir url
*
*
* youtube-dl -o dirTemplate url
* [download] Destination: ??ACICFG?????к??S21E04 -??????610?????(1080P ????????-1hA411L7dM.flv
* "\r[download]  57.0% of 561.64MiB at  7.08MiB/s ETA 00:34         "
*/


void MainWindow::startMission(Method method,QString url,QString filePath)
{
    // 新增任务表
    newDlg->hide();
    delete newDlg;
    QTableWidgetItem *name = new QTableWidgetItem();
    name->setText(url);
    QTableWidgetItem *progress = new QTableWidgetItem();
    progress->setText(QString::fromLocal8Bit("连接中..."));
    table->insertRow(0);
    int index = table->rowCount();
    table->setItem(index-1,0,name);
    table->setItem(index-1,1,progress);
    QApplication::processEvents();

    // 开始任务
    QString command("cmd");
    QString args;
    QString currentPath = QApplication::applicationDirPath();
    if(method == Media)
    {
        args =" /c ";
        args += "D:\\workspace\\Download_Play";
        args += "\\youtube-dl\\youtube-dl.exe";
    }
    else if(method == File)
    {

        args = " /c " + currentPath + "\\aira2\\aira2c.exe";
    }

    args += " -o ";
    args += filePath + " ";
    args += url;

    QProcess work;
    QObject::connect(&work,&QProcess::readyReadStandardOutput,[&](){
        QApplication::processEvents();
        //QTableWidgetItem *progress = new QTableWidgetItem();
        progress->setText(work.readAllStandardOutput());
        //table->setItem(index-1,1,progress);
    });
    work.setReadChannel(QProcess::StandardOutput);
    work.start(command,QStringList(args));
    work.waitForFinished(-1);

}

void MainWindow::convertMedia(QString command)
{
    /*
    // 新增任务表
    newDlg->hide();
    delete newDlg;
    QTableWidgetItem *name = new QTableWidgetItem();
    name->setText(url);
    QTableWidgetItem *progress = new QTableWidgetItem();
    progress->setText("连接中...");
    table->insertColumn(1);
    int index = table->columnCount();
    table->setItem(0,index-1,name);
    table->setItem(1,index-1,progress);

    QString currentPath = QApplication::applicationDirPath();
    args = " /c " + currentPath + "\\aira2\\aira2c.exe";

    //QProcess *work = new QProcess();
    //work->start("ffmpeg");
    */
}



