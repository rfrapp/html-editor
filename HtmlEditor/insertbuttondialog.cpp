#include "insertbuttondialog.h"
#include "ui_insertbuttondialog.h"

InsertButtonDialog::InsertButtonDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertButtonDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());
    editor = e;
}

InsertButtonDialog::~InsertButtonDialog()
{
    delete ui;
}

void InsertButtonDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertButtonDialog::on_insertButton_clicked()
{
    QString type = ui->typeBox->currentText();
    QString id = ui->idTextBox->text();
    QString value = ui->valueTextBox->text();

    editor->insertButton(type, id, value);

    this->close();
}
