#include "newdialog.h"
#include "ui_newdialog.h"
#include <QDebug>

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    log = ui->logBrowser;

    QObject::connect(ui->confirmButton,&QPushButton::clicked,[&](){
        url = ui->urlEdit->text();
        emit this->setMission(url,filePath);
    });

    QObject::connect(ui->fileButton,&QPushButton::clicked,[&](){
        filePath = QFileDialog::getExistingDirectory(this,QString::fromLocal8Bit("保存文件到"));
        ui->pathEdit->setText(filePath);
    });


}

NewDialog::~NewDialog()
{
    delete ui;
}
