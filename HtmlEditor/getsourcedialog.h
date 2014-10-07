#ifndef GETSOURCEDIALOG_H
#define GETSOURCEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class GetSourceDialog;
}

class GetSourceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GetSourceDialog(QWidget *parent = 0, Editor *e = 0);
    ~GetSourceDialog();
    
private slots:
    void on_cancelButton_clicked();

    void on_getSourceButton_clicked();

private:
    Editor *editor;
    Ui::GetSourceDialog *ui;
};

#endif // GETSOURCEDIALOG_H
