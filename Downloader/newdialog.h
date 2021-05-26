#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QTextBrowser>
#include <QMessageBox>

enum Method{
  Media = 0,
  File
};

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT
signals:
    void setMission(Method method,QString url,QString path);

public:
    explicit NewDialog(QWidget *parent = nullptr);
    ~NewDialog();

private:
    Ui::NewDialog *ui;
    QString url;
    QString filePath;
};

#endif // NEWDIALOG_H
