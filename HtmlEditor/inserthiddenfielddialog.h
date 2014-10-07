#ifndef INSERTHIDDENFIELDDIALOG_H
#define INSERTHIDDENFIELDDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertHiddenFieldDialog;
}

class InsertHiddenFieldDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertHiddenFieldDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertHiddenFieldDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertHiddenFieldDialog *ui;
    Editor *editor;
};

#endif // INSERTHIDDENFIELDDIALOG_H
