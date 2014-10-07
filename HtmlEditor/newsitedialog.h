#ifndef NEWSITEDIALOG_H
#define NEWSITEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class NewSiteDialog;
}

class NewSiteDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewSiteDialog(QWidget *parent = 0, Editor *e = 0);
    ~NewSiteDialog();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewSiteDialog *ui;
    Editor *editor;
};

#endif // NEWSITEDIALOG_H
