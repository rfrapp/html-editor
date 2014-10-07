#include "insertcheckboxdialog.h"
#include "ui_insertcheckboxdialog.h"

InsertCheckboxDialog::InsertCheckboxDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertCheckboxDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    editor = e;
}

InsertCheckboxDialog::~InsertCheckboxDialog()
{
    delete ui;
}

void InsertCheckboxDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertCheckboxDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();
    QString id = ui->idTextBox->text();
    QString text = ui->labelTextBox->text();

    editor->insertCheckbox(name, id, text);
    this->close();
}
