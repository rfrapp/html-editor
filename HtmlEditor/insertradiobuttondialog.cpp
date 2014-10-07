#include "insertradiobuttondialog.h"
#include "ui_insertradiobuttondialog.h"

InsertRadioButtonDialog::InsertRadioButtonDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertRadioButtonDialog)
{
    ui->setupUi(this);
    editor = e;

    this->setFixedSize(this->size());
}

InsertRadioButtonDialog::~InsertRadioButtonDialog()
{
    delete ui;
}

void InsertRadioButtonDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertRadioButtonDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();
    QString id = ui->idTextBox->text();
    QString text = ui->labelTextBox->text();

    editor->insertRadioButton(name, id, text);
}
