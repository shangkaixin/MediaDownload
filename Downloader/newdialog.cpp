#include "newdialog.h"
#include "ui_newdialog.h"
#include <QDebug>

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    Method method;

    QObject::connect(ui->confirmButton,&QPushButton::clicked,[&](){
        url = ui->urlEdit->text();
        if(ui->mediaButton->isChecked() == true)
        {
            method = Media;
        }
        else if(ui->fileButton->isChecked() == true)
        {
            method = File;
        }
        else
        {
            QMessageBox::warning(this,QString("WARNING"),QString::fromLocal8Bit("请选择下载引擎"),QMessageBox::Ok);
            return;
        }

        emit this->setMission(method,url,filePath);
    });

    QObject::connect(ui->fileButton,&QPushButton::clicked,[&](){
        filePath = QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("保存文件为"));
        ui->pathEdit->setText(filePath);
    });


}

NewDialog::~NewDialog()
{
    delete ui;
}
