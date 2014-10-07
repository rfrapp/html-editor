#include "insertradiogroupdialog.h"
#include "ui_insertradiogroupdialog.h"

InsertRadioGroupDialog::InsertRadioGroupDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertRadioGroupDialog)
{
    ui->setupUi(this);

    editor = e;
    this->setFixedSize(this->size());

}

InsertRadioGroupDialog::~InsertRadioGroupDialog()
{
    delete ui;
}

void InsertRadioGroupDialog::on_closeButton_clicked()
{
    this->close();
}


void InsertRadioGroupDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();
    QString optionText = ui->optionsTextBox->toPlainText();
    QStringList options = optionText.split('\n');


    editor->insertRadioGroup(name, options);
    this->close();
}
