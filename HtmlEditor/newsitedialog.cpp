#include "newsitedialog.h"
#include "ui_newsitedialog.h"

NewSiteDialog::NewSiteDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::NewSiteDialog)
{
    ui->setupUi(this);
    editor = e;

    this->setFixedSize(this->size());
}

NewSiteDialog::~NewSiteDialog()
{
    delete ui;
}

void NewSiteDialog::on_buttonBox_accepted()
{
    QString siteName = ui->lineEdit->text();
    QString type = ui->comboBox->currentText().toLower();

    if (siteName.trimmed() == "" || type.trimmed() == "")
    {
        ui->errorField->setStyleSheet("QLabel { color: #ff0000; }");
        ui->errorField->setText("Please fill out all fields in the form.");

        this->show();
    }
    else
    {
        QString newSitePath = QDir::rootPath() + "RF-HTML-PROJECTS/" + siteName;

        if (!QDir(newSitePath).exists())
        {
            editor->createNewSite(siteName, type);
            this->close();
        }
        else
        {
            switch(QMessageBox::critical(this,
                                  tr("Site exists."),
                                  tr("A site by this name already exists. "
                                     "Would you like to overwrite it? This will delete all of the files that were in the old directory."), QMessageBox::Yes|QMessageBox::No))
            {
            case QMessageBox::Yes:
                editor->createNewSite(siteName, type);
                this->close();
                break;
            default:
                this->show();
                break;
            }
        }

    }
}
