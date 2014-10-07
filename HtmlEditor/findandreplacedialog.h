#ifndef FINDANDREPLACEDIALOG_H
#define FINDANDREPLACEDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class FindAndReplaceDialog;
}

class FindAndReplaceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FindAndReplaceDialog(QWidget *parent = 0, Editor *e = 0);
    ~FindAndReplaceDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_findButton_clicked();

    void on_findAndReplaceButton_clicked();

private:
    Ui::FindAndReplaceDialog *ui;
    Editor *editor;
};

#endif // FINDANDREPLACEDIALOG_H
