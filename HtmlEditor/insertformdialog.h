#ifndef INSERTFORMDIALOG_H
#define INSERTFORMDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertFormDialog;
}

class InsertFormDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertFormDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertFormDialog();
    
private slots:
    void on_browseButton_clicked();

    void on_closeButton_clicked();

    void on_addButton_clicked();

private:
    Ui::InsertFormDialog *ui;
    Editor *editor;
};

#endif // INSERTFORMDIALOG_H
