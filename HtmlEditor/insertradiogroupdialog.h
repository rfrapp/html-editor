#ifndef INSERTRADIOGROUPDIALOG_H
#define INSERTRADIOGROUPDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertRadioGroupDialog;
}

class InsertRadioGroupDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertRadioGroupDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertRadioGroupDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertRadioGroupDialog *ui;
    Editor *editor;
};

#endif // INSERTRADIOGROUPDIALOG_H
