#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "newdialog.h"
#include "aboutdialog.h"
#include "convertdialog.h"

#include <Python.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startMission(QString url,QString filePath);
    void convertMedia(QString command);

private:
    Ui::MainWindow *ui;
    QTableWidget *table;

    AboutDialog *aboutDlg;
    NewDialog *newDlg;
    ConvertDialog *convertDlg;
};
#endif // MAINWINDOW_H
