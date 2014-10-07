#include "inserttabledialog.h"
#include "ui_inserttabledialog.h"

InsertTableDialog::InsertTableDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertTableDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());
    ui->borderSpinBox->setMinimum(0);
    ui->rowsSpinBox->setMinimum(0);
    ui->colsSpinBox->setMinimum(0);
}

InsertTableDialog::~InsertTableDialog()
{
    delete ui;
}

// yes button
void InsertTableDialog::on_radioButton_clicked()
{
    ui->borderSpinBox->show();
    ui->pxLabel->show();
}

// no button
void InsertTableDialog::on_radioButton_2_clicked()
{
    ui->borderSpinBox->hide();
    ui->pxLabel->hide();
}

void InsertTableDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertTableDialog::on_insertButton_clicked()
{
    int rows = ui->rowsSpinBox->value();
    int columns = ui->colsSpinBox->value();
    int borderSize = 0;

    if (ui->radioButton->isChecked())
        borderSize = ui->borderSpinBox->value();

    editor->insertTable(rows, columns, borderSize);
    this->close();
}
