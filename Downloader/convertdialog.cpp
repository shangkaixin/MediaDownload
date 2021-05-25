#include "convertdialog.h"
#include "ui_convertdialog.h"
#include <QDebug>

ConvertDialog::ConvertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvertDialog)
{
    ui->setupUi(this);

    // 源文件浏览框
    QObject::connect(ui->originButton,&QPushButton::clicked,[&](){
        QString originPath = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("源文件"));
        ui->originEdit->setText(originPath);
    });

    // 目的文件浏览框
    QObject::connect(ui->resultButton,&QPushButton::clicked,[&](){
        QString resultPath = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("源文件"));
        ui->resultEdit->setText(resultPath);
    });

    // 确定按钮
    QObject::connect(ui->confirmButton,&QPushButton::clicked,[&](){
        QString origin;
        QString value;
        QString destination;
        QString command;
        origin = ui->originEdit->text();
        destination = ui->resultEdit->text();

        if(ui->needAudio->checkState() != Qt::Checked)
            value += " -an";

        if(ui->needVideo->checkState() != Qt::Checked)
            value += " -vn";

        command = "-i " + origin + value + " " + destination;
        emit startConvert(command);
        qDebug() << command;
    });

}

ConvertDialog::~ConvertDialog()
{
    delete ui;
}
