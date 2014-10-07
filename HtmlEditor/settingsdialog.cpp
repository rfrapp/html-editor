#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>
#include <QFontDatabase>

SettingsDialog::SettingsDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    CodeEditor *tmp;

    ui->setupUi(this);

    fillFontComboBox();

    attemptFontChangeCount = 0;

    editor = e;

    tmp = editor->getCodeEditors().at(0);

    this->setFixedSize(this->size());

    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(48);

    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setMaximum(48);

    connect(ui->checkBox, SIGNAL(clicked()), SLOT(on_checkBox_clicked()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), SLOT(changeFontSize(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), SLOT(changeFontSize(int)));

    ui->spinBox->setValue(tmp->font().pointSize());
    ui->checkBox->setChecked((tmp->wordWrapMode() == QTextOption::WrapAnywhere) ? true : false);

    QString editorFont = editor->getEditorFont();

    //qDebug() << "The Font is: " + editorFont;

    int indexToSelect = ui->comboBox->findText(editorFont);

    //qDebug() << "Index to select: " + QString::number(indexToSelect);

    ui->comboBox->setCurrentIndex(indexToSelect);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_checkBox_clicked()
{
    bool wrapText = ui->checkBox->isChecked();
    //QSettings wrapSetting("RF-HTML-Editor", "HtmlEditor");

    editor->setTextWrapping(wrapText);
}

void SettingsDialog::on_cancelButton_clicked()
{
    this->close();
}

void SettingsDialog::changeFontSize(int value)
{   
    editor->setFontSize(value);

    QSettings fontSizeSetting("RF-HTML-Editor", "HtmlEditor");

    //fontSizeSetting.beginGroup("RF-HTML-Editor");

    fontSizeSetting.setValue("RF-HTML-Editor/fontSize", value);

    //fontSizeSetting.endGroup();
}

void SettingsDialog::fillFontComboBox()
{
    QFontDatabase db;
    QStringList fonts;

    fonts = db.families();

    foreach (QString font, fonts)
    {
        ui->comboBox->addItem(font);
    }
}

void SettingsDialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (attemptFontChangeCount > 0)
        editor->setEditorFont(arg1);
    else
        attemptFontChangeCount++;
}








