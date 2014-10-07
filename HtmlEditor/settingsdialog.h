#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "editor.h"
#include "codeeditor.h"
#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0, Editor *e = 0);
    ~SettingsDialog();
    
private slots:
    void on_checkBox_clicked();

    void on_cancelButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

protected slots:
    void changeFontSize(int);

private:
    Ui::SettingsDialog *ui;
    Editor *editor;
    int attemptFontChangeCount;

    void fillFontComboBox();
};

#endif // SETTINGSDIALOG_H
