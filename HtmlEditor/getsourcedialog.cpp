#include "getsourcedialog.h"
#include "ui_getsourcedialog.h"

GetSourceDialog::GetSourceDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::GetSourceDialog)
{
    ui->setupUi(this);

    editor = e;
}

GetSourceDialog::~GetSourceDialog()
{
    delete ui;
}

void GetSourceDialog::on_cancelButton_clicked()
{
    this->close();
}

void GetSourceDialog::on_getSourceButton_clicked()
{
    QString url = ui->lineEdit->text();

    if (url != "")
    {
        QString fileContents = editor->readFile(url);

        CodeEditor *codeEditor = editor->getCodeEditors().at(editor->getCurrentOpenTabIndex());

        codeEditor->appendPlainText(fileContents);
    }
}
