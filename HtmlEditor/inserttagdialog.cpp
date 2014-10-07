#include "inserttagdialog.h"
#include "ui_inserttagdialog.h"

InsertTagDialog::InsertTagDialog(QWidget *parent, Editor *e) :
    QDialog(parent),
    ui(new Ui::InsertTagDialog)
{
    ui->setupUi(this);

    editor = e;

    this->setFixedSize(this->size());

    loadTags();
}

InsertTagDialog::~InsertTagDialog()
{
    delete ui;
}

void InsertTagDialog::loadTags()
{
    QStringList tags;

    tags << "<!--" <<
            "<!doctype>" << "<a>" <<
            "<abbr>" << "<acronym>" <<
            "<address>" << "<applet>" <<
            "<area>" << "<article>" << "<aside>" <<
            "<audio>" << "<b>" << "<base>" <<
            "<basefont>" << "<bdo>" <<
            "<big>" << "<blockquote>" <<
            "<body>" << "<br />" << "<button>" << "<canvas>" <<
            "<caption>" << "<center>" <<
            "<cite>" << "<code>" <<
            "<col>" << "<colgroup>" <<
            "<dd>" << "<del>" << "<dfn>" <<
            "<dir>" << "<div>" << "<dl>" <<
            "<dt>" << "<em>" << "<fieldset>" <<
            "<font>" << "<footer>" << "<form>" << "<frame>" <<
            "<frameset>" << "<h1>" << "<h2>" <<
            "<h3>" << "<h4>" << "<h5>" << "<h6>" <<
            "<head>" << "<header>" << "<hr />" << "<html>" << "<i>" <<
            "<iframe>" << "<img>" << "<input />" << "<ins>" <<
            "<isindex>" << "<kbd>" << "<label>" <<
            "<legend>" << "<li>" << "<link>" <<
            "<map>" << "<menu>" <<
            "<meta>" << "<nav>" << "<noframes>" <<
            "<noscript>" << "<object>" << "<ol>" <<
            "<optgroup>" << "<option>" << "<p>" <<
            "<param>" << "<pre>" << "<q>" << "<s>" <<
            "<samp>" << "<script>" << "<select>" <<
            "<section>" << "<small>" << "<span>" << "<strike>" <<
            "<strong>" << "<style>" << "<sub>" <<
            "<sup>" << "<table>" << "<tbody>" <<
            "<td>" << "<textarea>" << "<tfoot>" <<
            "<th>" << "<thead>" << "<title>" <<
            "<tr>" << "<tt>" << "<u>" << "<ul>" << "<var>" <<
            "<video>";

    ui->listWidget->addItems(tags);
}

void InsertTagDialog::addTag()
{
    QListWidgetItem *selected = ui->listWidget->currentItem();
    QString tag = selected->text();

    editor->insertTag(tag);
    this->close();
}

void InsertTagDialog::on_closeButton_clicked()
{
    this->close();
}

void InsertTagDialog::on_insertButton_clicked()
{
    addTag();
}

void InsertTagDialog::on_listWidget_doubleClicked(const QModelIndex &index)
{
    addTag();
}
