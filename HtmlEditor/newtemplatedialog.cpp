#include "newtemplatedialog.h"
#include "ui_newtemplatedialog.h"

NewTemplateDialog::NewTemplateDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::NewTemplateDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());
}

NewTemplateDialog::~NewTemplateDialog()
{
    delete ui;
}

void NewTemplateDialog::on_closeButton_clicked()
{
    this->close();
}

void NewTemplateDialog::on_addButton_clicked()
{
    QString tName = ui->templateNameTextBox->text();
    QString tType = ui->templateTypeComboBox->currentText();
    QString tDesc = ui->templateDescriptionTextBox->toPlainText();

    if (tName.trimmed() == "" || tDesc.trimmed() == "" || tType.trimmed() == "")
    {
        ui->errorLabel->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorLabel->setText("Please fill out all fields in the form.");

        this->show();
    }
    else
    {
        if (tType == "ASPX Template")
            tType = "aspx";
        if (tType == "Cascading Style-Sheet Template")
            tType = "css";
        if (tType == "HTML Template")
            tType = "html";
        if (tType == "JavaScript Template")
            tType = "js";
        if (tType == "PHP Template")
            tType = "php";

        QString filePath(QDir::rootPath() + "RF-HTML-PROJECTS/templates/" + tName + "." + tType);

        if (!QFileInfo(filePath).exists())
        {
            editor->addNewTemplate(tName, tType, tDesc);
            this->close();
        }
        else
        {
            switch(QMessageBox::critical(this,
                                  tr("Template exists."),
                                  tr("A template by this name already exists. "
                                     "Would you like to overwrite it?"), QMessageBox::Yes|QMessageBox::No))
            {
            case QMessageBox::Yes:
                editor->addNewTemplate(tName, tType, tDesc);
                this->close();

                break;

            }
        }
    }
}






