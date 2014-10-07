#include "insertselectboxdialog.h"
#include "ui_insertselectboxdialog.h"

InsertSelectBoxDialog::InsertSelectBoxDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertSelectBoxDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    editor = e;
}

InsertSelectBoxDialog::~InsertSelectBoxDialog()
{
    delete ui;
}

void InsertSelectBoxDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertSelectBoxDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();
    QStringList options = ui->optionsTextBox->toPlainText().split("\n");

    editor->insertSelectBox(name, options);

    this->close();
}
