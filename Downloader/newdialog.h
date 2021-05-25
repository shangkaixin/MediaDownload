#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QTextBrowser>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT
signals:
    void setMission(QString url,QString path);

public:
    explicit NewDialog(QWidget *parent = nullptr);
    ~NewDialog();

private:
    Ui::NewDialog *ui;
    QTextBrowser *log;
    QString url;
    QString filePath;
};

#endif // NEWDIALOG_H
