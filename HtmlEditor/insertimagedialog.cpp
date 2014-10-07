#include "insertimagedialog.h"
#include "ui_insertimagedialog.h"
#include <QFileDialog>

InsertImageDialog::InsertImageDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertImageDialog)
{
    ui->setupUi(this);
    editor = e;

    this->setFixedSize(this->size());

    ui->lineEdit->setDisabled(true);
}

InsertImageDialog::~InsertImageDialog()
{
    delete ui;
}

void InsertImageDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertImageDialog::on_browseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open HTML Document"),
                QDir::rootPath(),
                tr("PNG Image (*.png);; JPG Image (*.jpg);; Bitmap Image (*.bmp);;"));

    ui->lineEdit->setText(filePath);
}

void InsertImageDialog::on_insertButton_clicked()
{
    QString imgPath = ui->lineEdit->text();
    QString altText = ui->altText->text();

    if (imgPath.trimmed() == "" || altText.trimmed() == "")
    {
        ui->errorLabel->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorLabel->setText("Please fill out all fields in the form.");

        this->show();
    }
    else
    {
        editor->insertImage(imgPath, altText);

        this->close();
    }
}





