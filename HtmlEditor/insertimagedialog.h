#ifndef INSERTIMAGEDIALOG_H
#define INSERTIMAGEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertImageDialog;
}

class InsertImageDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertImageDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertImageDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_browseButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertImageDialog *ui;
    Editor *editor;
};

#endif // INSERTIMAGEDIALOG_H
