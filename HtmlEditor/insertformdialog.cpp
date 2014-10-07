#include "insertformdialog.h"
#include "ui_insertformdialog.h"
#include <QFileDialog>

InsertFormDialog::InsertFormDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertFormDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());

    ui->actionPathTextBox->setDisabled(true);
}

InsertFormDialog::~InsertFormDialog()
{
    delete ui;
}

void InsertFormDialog::on_browseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open HTML Document"),
                QDir::rootPath(),
                tr("PHP Script (*.php); ASPX Script (*.aspx)"));

    ui->actionPathTextBox->setText(filePath);
}

void InsertFormDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertFormDialog::on_addButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString method = ui->methodGroup->checkedButton()->text();
    QString enctype = ui->enctypeGroup->checkedButton()->text();
    QString action = ui->actionPathTextBox->text();

    editor->insertForm(id, method, enctype, action);

    this->close();
}
