#ifndef INSERTCHECKBOXDIALOG_H
#define INSERTCHECKBOXDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertCheckboxDialog;
}

class InsertCheckboxDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertCheckboxDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertCheckboxDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertCheckboxDialog *ui;
    Editor *editor;
};

#endif // INSERTCHECKBOXDIALOG_H
