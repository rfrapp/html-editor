#ifndef NEWTEMPLATEDIALOG_H
#define NEWTEMPLATEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class NewTemplateDialog;
}

class NewTemplateDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewTemplateDialog(QWidget *parent = 0, Editor *e = 0);
    ~NewTemplateDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_addButton_clicked();

private:
    Ui::NewTemplateDialog *ui;
    Editor *editor;
};

#endif // NEWTEMPLATEDIALOG_H
