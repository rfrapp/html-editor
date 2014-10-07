#include "findandreplacedialog.h"
#include "ui_findandreplacedialog.h"

FindAndReplaceDialog::FindAndReplaceDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::FindAndReplaceDialog)
{
    ui->setupUi(this);

    editor = e;

    // prevent window resizing
    this->setFixedSize(this->size());
}

FindAndReplaceDialog::~FindAndReplaceDialog()
{
    delete ui;
}

// close button clicked
void FindAndReplaceDialog::on_closeButton_clicked()
{
    this->close();
}

void FindAndReplaceDialog::on_findButton_clicked()
{
    QString findText = ui->findTextbox->text();

    if (findText.trimmed() == "")
    {
        ui->errorField->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorField->setText("Please fill out the 'find' field.");

        this->show();
    }
    else
    {
        ui->errorField->clear();
        editor->findText(findText);
    }
}

void FindAndReplaceDialog::on_findAndReplaceButton_clicked()
{
    QString findText = ui->findTextbox->text();
    QString replaceText = ui->replaceTextBox->text();

    if (findText.trimmed() == "" || replaceText.trimmed() == "")
    {
        ui->errorField->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorField->setText("Please fill out all fields in the form.");

        this->show();
    }
    else
    {
        ui->errorField->clear();
        editor->replaceText(findText, replaceText);
    }

}
