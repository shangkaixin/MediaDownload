#ifndef CONVERTDIALOG_H
#define CONVERTDIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class ConvertDialog;
}

class ConvertDialog : public QDialog
{
    Q_OBJECT

signals:
    void startConvert(QString command);

public:
    explicit ConvertDialog(QWidget *parent = nullptr);
    ~ConvertDialog();

private:
    Ui::ConvertDialog *ui;

};

#endif // CONVERTDIALOG_H
