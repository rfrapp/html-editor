#ifndef INSERTTEXTAREADIALOG_H
#define INSERTTEXTAREADIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertTextareaDialog;
}

class InsertTextareaDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertTextareaDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertTextareaDialog();
    
private slots:


    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertTextareaDialog *ui;
    Editor *editor;
};

#endif // INSERTTEXTAREADIALOG_H
