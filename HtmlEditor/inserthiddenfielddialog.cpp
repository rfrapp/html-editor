#include "inserthiddenfielddialog.h"
#include "ui_inserthiddenfielddialog.h"

InsertHiddenFieldDialog::InsertHiddenFieldDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertHiddenFieldDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());
}

InsertHiddenFieldDialog::~InsertHiddenFieldDialog()
{
    delete ui;
}

void InsertHiddenFieldDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertHiddenFieldDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();
    QString value = ui->valueTextBox->text();

    editor->insertHiddenField(name, value);
    this->close();
}
