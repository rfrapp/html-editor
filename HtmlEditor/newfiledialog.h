#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>
#include "editor.h"
#include <vector>
#include "filetemplate.h"
#include <QMessageBox>

namespace Ui {
class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewFileDialog(QWidget *parent = 0, Editor *e = 0);
    ~NewFileDialog();
    
private slots:
    void on_buttonBox_accepted();

    void on_templateNames_currentIndexChanged(int index);

protected:
    virtual void resizeEvent(QResizeEvent *);
private:
    Ui::NewFileDialog *ui;
    Editor *editor;


    bool isValidated;

    void populateSiteList();
    void populateTemplateList();
};

#endif // NEWFILEDIALOG_H
