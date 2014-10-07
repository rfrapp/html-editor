#ifndef INSERTTABLEDIALOG_H
#define INSERTTABLEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertTableDialog;
}

class InsertTableDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertTableDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertTableDialog();
    
private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_closeButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertTableDialog *ui;
    Editor *editor;
};

#endif // INSERTTABLEDIALOG_H
