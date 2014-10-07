#ifndef INSERTUPLOADFIELDDIALOG_H
#define INSERTUPLOADFIELDDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertUploadFieldDialog;
}

class InsertUploadFieldDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertUploadFieldDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertUploadFieldDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertUploadFieldDialog *ui;
    Editor *editor;
};

#endif // INSERTUPLOADFIELDDIALOG_H
