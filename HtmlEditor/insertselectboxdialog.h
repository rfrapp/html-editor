#ifndef INSERTSELECTBOXDIALOG_H
#define INSERTSELECTBOXDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertSelectBoxDialog;
}

class InsertSelectBoxDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertSelectBoxDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertSelectBoxDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertSelectBoxDialog *ui;
    Editor *editor;
};

#endif // INSERTSELECTBOXDIALOG_H
