#include "insertuploadfielddialog.h"
#include "ui_insertuploadfielddialog.h"

InsertUploadFieldDialog::InsertUploadFieldDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertUploadFieldDialog)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    editor = e;
}

InsertUploadFieldDialog::~InsertUploadFieldDialog()
{
    delete ui;
}

void InsertUploadFieldDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertUploadFieldDialog::on_insertButton_clicked()
{
    QString name = ui->nameTextBox->text();

    editor->insertUploadField(name);

    this->close();
}
