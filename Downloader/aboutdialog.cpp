#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    ui->iconLabel->setPixmap(QPixmap(":/icon/icon/about.png").scaled(60,60,Qt::KeepAspectRatio));
    ui->infoLabel->setText(QString::fromLocal8Bit("软件基于Qt5开发，并封装下载器\r\n"
                                                  "所使用到的插件:\r\n"
                                                  "youtube-dl\r\n"
                                                  "python 3.8\r\n"
                                                  "ffmpeg\r\n"
                                                  "aria2\r\n"
                                                  "ThunderX\r\n"
                                                  "仅供学习参考使用，请勿贩卖，版权所有®"));

    QObject::connect(ui->updateButton,&QPushButton::clicked,[&](){

    });

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
