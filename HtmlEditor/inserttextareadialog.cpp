#include "inserttextareadialog.h"
#include "ui_inserttextareadialog.h"

InsertTextareaDialog::InsertTextareaDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertTextareaDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    editor = e;
}

InsertTextareaDialog::~InsertTextareaDialog()
{
    delete ui;
}

void InsertTextareaDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertTextareaDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextbox->text();
    QString value = ui->valueTextbox->text();

    editor->insertTextarea(name, value);

    this->close();
}
