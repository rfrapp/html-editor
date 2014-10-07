#ifndef INSERTRADIOBUTTONDIALOG_H
#define INSERTRADIOBUTTONDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertRadioButtonDialog;
}

class InsertRadioButtonDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertRadioButtonDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertRadioButtonDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertRadioButtonDialog *ui;
    Editor *editor;
};

#endif // INSERTRADIOBUTTONDIALOG_H
