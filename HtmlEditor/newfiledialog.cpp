#include "newfiledialog.h"
#include "ui_newfiledialog.h"
#include <QDir>
#include <QFileInfo>
#include "filetemplate.h"

NewFileDialog::NewFileDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);
    editor = e;

    populateSiteList();
    populateTemplateList();

    isValidated = false;

    this->setFixedSize(this->size());
    ui->templateDescription->setDisabled(true);
}

void NewFileDialog::populateTemplateList()
{
    vector<FileTemplate> *templates = editor->getTemplates();

    for (int i = 0; i < templates->size(); i++)
    {
        FileTemplate *temp = &(templates->at(i));
        ui->templateNames->addItem(temp->getName());
    }
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

void NewFileDialog::populateSiteList()
{
    // open the projects directory
    QDir projectDir(QDir::homePath() + "/RF-HTML-PROJECTS/");


    // add each directory name to the combobox, excluding templates folder
    foreach (QFileInfo dir, projectDir.entryInfoList(QDir::AllDirs|QDir::NoDotAndDotDot))
    {
        if (!dir.fileName().contains("templates"))
            ui->siteList->addItem(dir.fileName());
    }

}

void NewFileDialog::on_buttonBox_accepted()
{
    QString siteTitle = ui->siteList->currentText();
    QString fileName = ui->lineEdit->text();
    QString fileType = ui->fileTypeList->currentText().toLower();

    // validate the form
    if (siteTitle.trimmed() == "" || fileName.trimmed() == "" || fileType.trimmed() == "")
    {
        ui->errorField->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorField->setText("Please fill out all fields in the form.");

        this->show();
    }
    else
    {
        if (fileType == "aspx file")
            fileType = "aspx";
        else if (fileType == "cascading style-sheet")
            fileType = "css";
        else if (fileType == "javascript file")
            fileType = "js";
        else if (fileType == "html file")
            fileType = "html";
        else if (fileType == "php script")
            fileType = "php";

        QString pathToNewFile(QDir::rootPath() + "RF-HTML-PROJECTS/" + siteTitle + "/" + fileName + "." + fileType);

        if (ui->templateNames->currentIndex() > 0)
        {
            if (!QFileInfo(pathToNewFile).exists())
            {
                editor->createNewFile(siteTitle, fileName, fileType, true, ui->templateNames->currentIndex() - 1);
                this->close();
            }
            else
            {
                switch(QMessageBox::critical(this,
                                      tr("File exists."),
                                      tr("A file by this name already exists. "
                                         "Would you like to overwrite it?"), QMessageBox::Yes|QMessageBox::No))
                {
                case QMessageBox::Yes:
                    editor->createNewFile(siteTitle, fileName, fileType, true, ui->templateNames->currentIndex() - 1);
                    this->close();

                    break;

                } // end switch

            } // end else
        }
        else
        {
            if (!QFileInfo(pathToNewFile).exists())
            {
                editor->createNewFile(siteTitle, fileName, fileType);
                this->close();
            }
            else
            {
                switch(QMessageBox::critical(this,
                                      tr("File exists."),
                                      tr("A file by this name already exists. "
                                         "Would you like to overwrite it?"), QMessageBox::Yes|QMessageBox::No))
                {
                case QMessageBox::Yes:
                    editor->createNewFile(siteTitle, fileName, fileType);
                    this->close();

                    break;

                } // end switch

            } // end else
        }
    }
}

void NewFileDialog::resizeEvent(QResizeEvent *e)
{
    e->ignore();
}

void NewFileDialog::on_templateNames_currentIndexChanged(int index)
{
    vector<FileTemplate> *templates = editor->getTemplates();

    ui->templateDescription->clear();

    if (index > 0)
    {
        FileTemplate *selected = &(templates->at(index - 1));

        ui->templateDescription->appendPlainText(selected->getDescription());
    }
}
