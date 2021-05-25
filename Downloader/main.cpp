#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/icon/icon/edit-media.png"));
    w.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    //w.setStyleSheet();
    w.show();
    return a.exec();
}
