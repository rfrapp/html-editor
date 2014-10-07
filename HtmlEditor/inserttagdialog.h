#ifndef INSERTTAGDIALOG_H
#define INSERTTAGDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertTagDialog;
}

class InsertTagDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertTagDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertTagDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_insertButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::InsertTagDialog *ui;
    Editor *editor;

    void loadTags();
    void addTag();
};

#endif // INSERTTAGDIALOG_H
