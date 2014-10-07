#include "inserttextfielddialog.h"
#include "ui_inserttextfielddialog.h"

InsertTextFieldDialog::InsertTextFieldDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertTextFieldDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    editor = e;
}

InsertTextFieldDialog::~InsertTextFieldDialog()
{
    delete ui;
}

void InsertTextFieldDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertTextFieldDialog::on_insertButton_clicked()
{
    QString name = ui->nameBox->text();
    QString value = ui->valueBox->text();

    editor->insertTextField(name, value);

    this->close();
}
