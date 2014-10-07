#ifndef INSERTHYPERLINKDIALOG_H
#define INSERTHYPERLINKDIALOG_H

#include <QDialog>
#include "editor.h"

namespace Ui {
class InsertHyperlinkDialog;
}

class InsertHyperlinkDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InsertHyperlinkDialog(QWidget *parent = 0, Editor *e = 0);
    ~InsertHyperlinkDialog();
    
private slots:
    void on_closeButton_clicked();

    void on_browseButton_clicked();

    void on_insertButton_clicked();

private:
    Ui::InsertHyperlinkDialog *ui;
    Editor *editor;
};

#endif // INSERTHYPERLINKDIALOG_H
