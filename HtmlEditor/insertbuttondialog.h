#ifndef INSERTBUTTONDIALOG_H
#define INSERTBUTTONDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertButtonDialog;
}

class InsertButtonDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertButtonDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertButtonDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertButtonDialog *ui;
    Editor *editor;
};

#endif // INSERTBUTTONDIALOG_H
