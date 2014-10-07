#include "inserthyperlinkdialog.h"
#include "ui_inserthyperlinkdialog.h"
#include <QFileDialog>

InsertHyperlinkDialog::InsertHyperlinkDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertHyperlinkDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());

    ui->accessKeySpinBox->setMinimum(0);
    ui->tabIndexSpinBox->setMinimum(0);
}

InsertHyperlinkDialog::~InsertHyperlinkDialog()
{
    delete ui;
}

void InsertHyperlinkDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertHyperlinkDialog::on_browseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                tr("Link to document"),
                QDir::rootPath(),
                tr("HTML Page (*.html);; PHP Script (*.php); ASPX Script (*.aspx)"));

    ui->linkTextBox->setText(filePath);
}

void InsertHyperlinkDialog::on_insertButton_clicked()
{
    QString text = ui->textTextBox->text();
    QString link = ui->linkTextBox->text();
    QString target = ui->targetComboBox->currentText();
    int accessKey = ui->accessKeySpinBox->value();
    int tabIndex = ui->tabIndexSpinBox->value();

    editor->insertHyperlink(text, link, target, accessKey, tabIndex);
    this->close();
}








