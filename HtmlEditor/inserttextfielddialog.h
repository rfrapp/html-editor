#ifndef INSERTTEXTFIELDDIALOG_H
#define INSERTTEXTFIELDDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertTextFieldDialog;
}

class InsertTextFieldDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertTextFieldDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertTextFieldDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertTextFieldDialog *ui;
    Editor *editor;
};

#endif // INSERTTEXTFIELDDIALOG_H
