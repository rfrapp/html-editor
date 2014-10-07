#include "editor.h"
#include "error.h"
#include "ui_editor.h"
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include <QtXml>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

using namespace std;

Editor::Editor(QWidget *parent) : QMainWindow(parent), ui(new Ui::Editor)
{   
    ui->setupUi(this);

    // remove GUI generated tabs
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(0);

    // add empty file to open files list
    openFiles.push_back(File("", "untitled-1", ""));

    // create a new tab and add custom editor to it
    CodeEditor *firstEditor = new CodeEditor(ui->tab, this);
    QHBoxLayout *layout = new QHBoxLayout;
    QWidget *newTab = new QWidget(ui->tabWidget);
    //HtmlSyntaxHighlighter *h = new HtmlSyntaxHighlighter(firstEditor->document());

    layout->addWidget(firstEditor);

    newTab->setLayout(layout);

    // allow for the user to close tabs
    ui->tabWidget->setTabsClosable(true);

    // add custom tab to tabwidget
    ui->tabWidget->addTab(newTab, "untitled-1*");

    // add the code editor to editor list
    codeEditors.push_back(firstEditor);

    // give the editor focus
    firstEditor->setFocus();

    // set the editor's font
    setEditorFont();

    // initialize the app
    init();

    ui->treeView->setSelectionBehavior(QTreeView::SelectRows);

    ui->listWidget->hide();

    ui->actionError_List->setChecked(false);
    ui->actionHTML_Page->setToolTip("Save as");
}

void Editor::hideTree()
{
    if (ui->treeView->isVisible())
        ui->treeView->hide();
    else
        ui->treeView->show();
}

void Editor::hideEditor()
{
    if (ui->tabWidget->isVisible())
        ui->tabWidget->hide();
    else
        ui->tabWidget->show();
}

void Editor::hideErrorBox()
{
    if (ui->listWidget->isVisible())
        ui->listWidget->hide();
    else
        ui->listWidget->show();
}

int Editor::getOpenTabCount()
{
    return ui->tabWidget->count();
}

void Editor::addAsteriskToTab()
{
    if (!ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("*"))
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), ui->tabWidget->tabText(ui->tabWidget->currentIndex()) + "*");
}

void Editor::setEditorFont(QString fontName)
{
    CodeEditor *currentEditor = codeEditors[ui->tabWidget->currentIndex()];

    // load the font size setting
    QSettings settings("RyanCo", "HtmlEditor");
    settings.beginGroup("RF-HTML-EDITOR");
    int fontSize = settings.value("fontSize", 12).toInt();
    settings.endGroup();

    // the font for the new textbox
    QFont font;

    // set font attributes
    font.setFamily(fontName);
    font.setFixedPitch(true);
    font.setPointSize(fontSize);

    currentEditor->setFont(font);

    const int tabStop = 4;  // 4 characters

    QFontMetrics metrics(font);
    currentEditor->setTabStopWidth(tabStop * metrics.width(' '));
}

void Editor::addNewTemplate(QString tName, QString tType, QString tDesc)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    string templateText = currentEditor->toPlainText().toStdString();
    ofstream templateFile;
    QString xmlPath  = QDir::homePath() + "/RF-HTML-PROJECTS/templates/templates.xml";
    QString templatePath = QDir::homePath() + "/RF-HTML-PROJECTS/templates/" + tName + "." + tType.toLower();
    QFile xmlFile(xmlPath);
    FileTemplate newTemplate(QDir::homePath() + "/RF-HTML-PROJECTS/templates/", tName + "." + tType.toLower(), QString::fromStdString(templateText), tDesc);
    QDomDocument xmlDoc;
    QDomNode templateNode;
    QDomNode templateNameNode;
    QDomNode templatePathNode;
    QDomNode templateDescNode;
    fileTemplates.push_back(newTemplate);

    if (xmlFile.open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate))
    {
        QDomElement root = xmlDoc.createElement("Templates");

        xmlDoc.appendChild(root);

        foreach (FileTemplate temp, fileTemplates)
        {
            templateNode = xmlDoc.createElement("Template");
            root.appendChild(templateNode);

            templateNameNode = xmlDoc.createElement("Name");
            templateNameNode.appendChild(xmlDoc.createTextNode(temp.getName()));
            templateNode.appendChild(templateNameNode);

            templatePathNode = xmlDoc.createElement("Path");
            templatePathNode.appendChild(xmlDoc.createTextNode(temp.getLocation()));
            templateNode.appendChild(templatePathNode);

            templateDescNode = xmlDoc.createElement("Description");
            templateDescNode.appendChild(xmlDoc.createTextNode(temp.getDescription()));
            templateNode.appendChild(templateDescNode);

        }

        // save the new template in the templates folder
        templateFile.open(templatePath.toStdString().c_str());
        templateFile << templateText;
        templateFile.close();


        // inform the user that their template was saved
        QMessageBox::information(this, tr("Template added"), tr("Your template has been created "
                                                                "in your templates folder."));


        xmlFile.write(xmlDoc.toString().toStdString().c_str());

        xmlFile.flush();
        xmlFile.close();
    }
}

void Editor::insertTag(QString tag)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString closeTag = "";

    if (tag == "<!--")
    {
        currentEditor->insertPlainText(tag + " -->");
    }

    else if (tag.contains("!") || tag.contains("/"))
    {
        currentEditor->insertPlainText(tag);
    }
    else
    {
        closeTag = tag;
        closeTag.insert(1, "/");

        currentEditor->insertPlainText(tag + closeTag);
    }
}

void Editor::insertImage(QString imgPath, QString altText)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString imgTag = "<img src=\"" + imgPath + "\" alt=\"" + altText + "\" />";

    currentEditor->insertPlainText(imgTag);
}

void Editor::insertForm(QString id, QString method, QString enctype, QString action)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString formTag;

    if (!enctype.toLower().contains("none"))
        formTag = "<form id=\"" + id + "\" method=\"" + method + "\" enctype=\"" + enctype.toLower() + "\" action=\"" + action + "\"></form>";
    else
        formTag = "<form id=\"" + id + "\" method=\"" + method + "\" action=\"" + action + "\"></form>";

    currentEditor->insertPlainText(formTag);
}

void Editor::insertTextField(QString name, QString value)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString inputTag = "<input type=\"text\" name=\"" + name + "\" value=\"" + value + "\" />";

    currentEditor->insertPlainText(inputTag);
}

void Editor::insertTextarea(QString name, QString value)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString textareaTag = "<textarea name=\"" + name + "\">" + value + "</textarea>";

    currentEditor->insertPlainText(textareaTag);
}

void Editor::insertCheckbox(QString name, QString id, QString text)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString checkboxTag = "<span>\n\t<input type=\"checkbox\" name=\"" + name + "\" id=\"" + id + "\" value=\"" + id + "\" /> " + text + "\n</span>";

    currentEditor->insertPlainText(checkboxTag);
}

void Editor::insertRadioButton(QString name, QString id, QString text)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString radioTag = "<span>\n\t<input type=\"radio\" name=\"" + name + "\" id=\"" + id + "\" value=\"" + id +  "\" />" + text + "\n</span>";

    currentEditor->insertPlainText(radioTag);
}

void Editor::insertRadioGroup(QString name, QStringList radioText)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QStringList radioButtons;

    for (int i = 0; i < radioText.count(); i++)
    {
        QString id = name + "_" + QString::number(i + 1);

        radioButtons << "<span>\n\t<input type=\"radio\" name=\"" + name + "\" id=\"" + id + "\" value=\"" + radioText.at(i) + "\">" + radioText.at(i) + "\n</span>\n";
    }

    for (int i = 0; i < radioButtons.count(); i++)
    {
        currentEditor->insertPlainText(radioButtons.at(i));
    }
}

void Editor::insertSelectBox(QString name, QStringList options)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString selectTag = "<select name=\"" + name + "\">";

    foreach (QString option, options)
    {
        selectTag.append("\n\t<option value=\"" + option + "\">" + option + "</option>");
    }

    selectTag.append("\n</select>");

    currentEditor->insertPlainText(selectTag);
}

void Editor::insertUploadField(QString name)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString uploadTag = "<input type=\"file\" name=\"" + name + "\" />";

    currentEditor->insertPlainText(uploadTag);
}

void Editor::insertButton(QString type, QString id, QString value)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString buttonTag = "";

    if (type == "Submit")
        buttonTag = "<input type=\"submit\" ";
    else
        buttonTag = "<input type=\"button\" ";

    buttonTag.append("id=\"" + id + "\" value=\"" + value + "\" />");

    currentEditor->insertPlainText(buttonTag);
}

void Editor::insertHiddenField(QString name, QString value)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString hiddenTag = "<input type=\"hidden\" name=\"" + name + "\" value=\"" + value + "\" />";

    currentEditor->insertPlainText(hiddenTag);
}

void Editor::insertTable(int rows, int columns, int borderSize)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString tableTag = "<table border=\"" + QString::number(borderSize) + "\">";

    for (int i = 0; i < rows; i++)
    {
        tableTag.append("\n\t<tr>");
        for (int j = 0; j < columns; j++)
        {
            tableTag.append("\n\t\t<td></td>");
        }
        tableTag.append("\n\t</tr>");
    }

    tableTag.append("\n</table>");

    currentEditor->insertPlainText(tableTag);
}

void Editor::insertHyperlink(QString text, QString link, QString target, int accessKey, int tabIndex)
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];
    QString aTag = "<a href=\"" + link + "\" target=\"" + target + "\" accesskey=\"" + QString::number(accessKey)
            + "\" tabindex=\"" + QString::number(tabIndex) + "\">" + text + "</a>";

    currentEditor->insertPlainText(aTag);
}

void Editor::init()
{
    wireEvents();
    createDirs();
    createTemplates();
    readInTemplates();

    // set shortcuts
    ui->actionOpen->setShortcut(QKeySequence("Ctrl+O"));
    ui->actionSave->setShortcut(QKeySequence("Ctrl+S"));
    ui->actionFind_and_Replace->setShortcut(QKeySequence("Ctrl+F"));
    ui->actionPrint->setShortcut(QKeySequence("Ctrl+P"));
    ui->actionTest_in_browser->setShortcut(QKeySequence("Ctrl+B"));
    ui->actionShow_Full_Screen->setShortcut(QKeySequence("Ctrl+E"));
}

void Editor::closeEvent(QCloseEvent *e)
{
    for (int i = ui->tabWidget->count() - 1; i >= 0; i--)
    {
        File currentFile = openFiles[i];

        if (ui->tabWidget->tabText(i).contains("*"))
        {
            switch( QMessageBox::information( this, "Are you sure?",
                                                  "The file \"" + currentFile.getName() + "\" has been changed. "
                                                  "Would you like to save the file?",
                                                      QMessageBox::Save|QMessageBox::Cancel|QMessageBox::Close))
            {
            case QMessageBox::Save:

                // save the file
                save();

                // if there is only one tab left,
                // close program, otherwise, close tab
                if (i == 0)
                    e->accept();
                else
                {
                    closeTab(i);
                }

                break;

            case QMessageBox::Cancel:

                // ignore the event
                e->ignore();
                break;

            case QMessageBox::Close:

                // if there is only one tab left,
                // close program, otherwise, close tab
                if (i == 0)
                    e->accept();
                else
                {
                    ui->tabWidget->setTabText(i, ui->tabWidget->tabText(i).mid(0, ui->tabWidget->tabText(i).length() - 1));
                    closeTab(i);
                }

                break;
            }

        }
    }
}

void Editor::wireEvents()
{
    // wire select all, cut, copy, and paste events to menu options
    connect(ui->actionCopy, SIGNAL(triggered()), SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), SLOT(paste()));
    connect(ui->actionCut, SIGNAL(triggered()), SLOT(cut()));
    connect(ui->actionSelect_All, SIGNAL(triggered()), SLOT(selectAll()));

    // wire undo and redo events
    connect(ui->actionUndo, SIGNAL(triggered()), SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), SLOT(redo()));

    // wire open, save as, and save events
    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(openFile()));
    connect(ui->actionHTML_Page, SIGNAL(triggered()), SLOT(saveAs()));
    connect(ui->actionSave, SIGNAL(triggered()), SLOT(save()));

    connect(ui->actionTest_in_browser, SIGNAL(triggered()), SLOT(preview()));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), SLOT(createTreeModel()));

    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), SLOT(closeTab(int)));

    connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), SLOT(openFileFromTree(QModelIndex)));

    connect(ui->actionPrint, SIGNAL(triggered()), SLOT(print()));

    connect(ui->actionNew_Site, SIGNAL(triggered()), SLOT(openNewSiteDialog()));
    connect(ui->actionNew_File, SIGNAL(triggered()), SLOT(openNewFileDialog()));

    connect(ui->actionPrint, SIGNAL(triggered()), SLOT(print()));

    connect(ui->actionFind_and_Replace, SIGNAL(triggered()), SLOT(openFindAndReplaceDialog()));

    connect(ui->actionSettings, SIGNAL(triggered()), SLOT(openSettingsDialog()));

    connect(ui->actionTemplate, SIGNAL(triggered()), SLOT(openNewTemplateDialog()));

    connect(ui->actionFile_Tree_View, SIGNAL(triggered()), SLOT(hideTree()));

    connect(ui->actionCode_Editor, SIGNAL(triggered()), SLOT(hideEditor()));

    connect(ui->actionError_List, SIGNAL(triggered()), SLOT(hideErrorBox()));

    connect(ui->actionShow_Full_Screen, SIGNAL(triggered()), SLOT(showCodeFullScreen()));

    connect(ui->actionTag, SIGNAL(triggered()), SLOT(openInsertTagDialog()));
    connect(ui->actionImage, SIGNAL(triggered()), SLOT(openInsertImageDialog()));

    connect(ui->actionForm, SIGNAL(triggered()), SLOT(openInsertFormDialog()));

    connect(ui->actionText_Field, SIGNAL(triggered()), SLOT(openInsertTextFieldDialog()));
    connect(ui->actionTextarea, SIGNAL(triggered()), SLOT(openInsertTextareaDialog()));
    connect(ui->actionCheckbox, SIGNAL(triggered()), SLOT(openInsertCheckboxDialog()));
    connect(ui->actionRadio_Button, SIGNAL(triggered()), SLOT(openInsertRadioButtonDialog()));
    connect(ui->actionRadio_Group, SIGNAL(triggered()), SLOT(openInsertRadioGroupDialog()));
    connect(ui->actionSelect_Box, SIGNAL(triggered()), SLOT(openInsertSelectBoxDialog()));

    connect(ui->actionFile_Upload_field, SIGNAL(triggered()), SLOT(openInsertUploadFieldDialog()));
    connect(ui->actionButton, SIGNAL(triggered()), SLOT(openInsertButtonDialog()));
    connect(ui->actionHidden_field, SIGNAL(triggered()), SLOT(openInsertHiddenFieldDialog()));
    connect(ui->actionTable, SIGNAL(triggered()), SLOT(openInsertTableDialog()));
    connect(ui->actionHyperlink, SIGNAL(triggered()), SLOT(openInsertHyperlinkDialog()));
    connect(ui->actionGet_Source, SIGNAL(triggered()), SLOT(openGetSourceDialog()));
    connect(ui->actionCheck_for_errors, SIGNAL(triggered()), SLOT(checkForErrors()));
}

void Editor::createTemplates()
{
    // create template files if they do not exist
    FileTemplate *temps[2];
    QString path = QDir::homePath() + "/RF-HTML-PROJECTS/templates/";
    QFile xmlFile(path + "templates.xml");
    QString basicName = "html5template-basic.html";
    QString fullName = "html5template-full.html";
    QDomDocument document;
    QDomElement root;
    QDomElement templateNode;
    QDomElement nameNode;
    QDomElement pathNode;
    QDomElement descNode;

    QString basicTemplateContents =
            "<!DOCTYPE html>\n"
            "<html>\n\t<head>\n\t\t<title></title>"
            "\n\t</head>\n\t<body>\n\n\t</body>\n</html>";

    QString fullTemplateContents =
            "<!DOCTYPE html>"
            "\n<html lang=\"en\">"
                "\n\t<head>"
                    "\n\t\t<title>Untitled</title>"
                "\n\t</head>"
                "\n\t<body>"
                    "\n\t\t<header>"
                        "\n\t\t\t<!-- Site header here -->"
                    "\n\t\t</header>"
                    "\n\t\t<section>"
                        "\n\t\t\t<!-- Main content here -->"
                        "\n\t\t\t<article>"
                            "\n\t\t\t\t<header> <!-- Article header here --> </header>"
                            "\n\t\t\t\t<section> <!-- Article contents here --> </section>"
                            "\n\t\t\t\t<footer> <!-- Article footer here --> </footer>"
                        "\n\t\t\t</article>"
                    "\n\t\t</section>"
                    "\n\t\t<aside>"
                        "\n\t\t\t<!-- Side-Bar Stuff Here -->"
                    "\n\t\t</aside>"
                    "\n\t\t<footer>"
                        "\n\t\t\t<!-- Site footer here &copy; -->"
                    "\n\t\t</footer>"
                "\n\t</body>"
            "\n</html>";


    if (!xmlFile.exists())
    {
        if (xmlFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            temps[0] = new FileTemplate(path + basicName, basicName, basicTemplateContents, "A basic HTML5 template");
            temps[1] = new FileTemplate(path + fullName, fullName, fullTemplateContents, "A full HTML5 template. Features headers, navs, sections, footers, and articles");

            // create the root element
            root = document.createElement("Templates");
            document.appendChild(root);

            for (int i = 0; i < 2; i++)
            {
                templateNode = document.createElement("Template");
                root.appendChild(templateNode);

                nameNode = document.createElement("Name");
                nameNode.appendChild(document.createTextNode(temps[i]->getName()));
                templateNode.appendChild(nameNode);

                pathNode = document.createElement("Path");
                pathNode.appendChild(document.createTextNode(temps[i]->getLocation()));
                templateNode.appendChild(pathNode);

                descNode = document.createElement("Description");
                descNode.appendChild(document.createTextNode(temps[i]->getDescription()));
                templateNode.appendChild(descNode);
            }
            xmlFile.write(document.toString().toStdString().c_str());

            xmlFile.flush();
            xmlFile.close();
        }
    }

    if (!QFileInfo(path + basicName).exists())
    {
        ofstream newTemplate;
        QString filePath = path + basicName;

        newTemplate.open((path.toStdString() + basicName.toStdString()).c_str());

        if (newTemplate.is_open())
        {
            newTemplate << basicTemplateContents.toStdString();
        }

        newTemplate.close();
    }

    if (!QFileInfo(path + fullName).exists())
    {
        ofstream newTemplate;
        QString filePath = path + fullName;

        newTemplate.open(filePath.toStdString().c_str());

        if (newTemplate.is_open())
        {
            newTemplate << fullTemplateContents.toStdString();
        }

        newTemplate.close();
    }
}

void Editor::highlightErrors(vector<Error> errors)
{
    if (errors.size() > 0)
    {
        CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];

        for (unsigned int i = 0; i < errors.size(); i++)
        {
            currentEditor->highlightLine(errors[i].getLineNumber());
        }
    }
}

void Editor::createNewSite(QString siteName, QString type)
{
    ofstream newFile;

    // if the project folder doesn't exist
    if (!QDir(QDir::homePath() + "/RF-HTML-PROJECTS/" + siteName).exists())
    {
        // create it
        QDir().mkdir(QDir::homePath() + "/RF-HTML-PROJECTS/" + siteName);

        newFile.open(QString(QDir::homePath() + "/RF-HTML-PROJECTS/" + siteName + "/index." + type).toStdString().c_str());

        // create an index file for the new c
        openFile(QDir::homePath() + "/RF-HTML-PROJECTS/" + siteName + "/index." + type);

        newFile.close();

        // notify the user of the new site creation
        QMessageBox::information(this, "New Site Created",
                                 "A new site named \"" + siteName + "\" was created"
                                    " in " +
                                    QDir::homePath() + "/RF-HTML-PROJECTS/" + siteName);
    }
}

void Editor::createNewFile(QString siteTitle, QString fileName, QString fileType, bool loadFromTemplate, int templateIndex)
{
    QString path = QDir::homePath() + "/RF-HTML-PROJECTS/" + siteTitle;
    ofstream newFile;

    newFile.open((path.toStdString() + "/" + fileName.toStdString() + "." + fileType.toStdString()).c_str());

    openFile(path + "/" + fileName + "." + fileType);

    QMessageBox::information(this, "File Created", "The file \"" + fileName + "." + fileType + "\" has been created in " + path + "/");

    if (loadFromTemplate && templateIndex >= 0)
    {
        CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];

        if (currentEditor->toPlainText().trimmed() != "")
            currentEditor = codeEditors[getCurrentOpenTabIndex() + 1];

        FileTemplate selectedTemplate = fileTemplates[templateIndex];

        currentEditor->appendPlainText(selectedTemplate.getContents());
        addAsteriskToTab();
    }

    newFile.close();
}

void Editor::findText(QString findText)
{
    CodeEditor *editor = codeEditors[getCurrentOpenTabIndex()];

    // highlight the text that the user requested
    editor->find(findText);
}

void Editor::replaceText(QString findText, QString replaceText)
{
    CodeEditor *editor = codeEditors[getCurrentOpenTabIndex()];

    // get the editor's text
    QString currentText = editor->toPlainText();

    // replace the user's requested 'find' text
    // with their requested 'replace' text
    currentText.replace(findText, replaceText);

    // clear the editor's text
    editor->clear();

    // add the thext to the editor
    editor->appendPlainText(currentText);


}

int Editor::getCurrentOpenTabIndex()
{
    return ui->tabWidget->currentIndex();
}

void Editor::setTextWrapping(bool wrap)
{
    if (wrap)
    {

        foreach (CodeEditor *e, codeEditors)
        {
            e->setWordWrapMode(QTextOption::WrapAnywhere);
        }
    }
    else
    {
        foreach (CodeEditor *e, codeEditors)
        {
            e->setWordWrapMode(QTextOption::NoWrap);
        }
    }
}

void Editor::setFontSize(int size)
{
    QSettings fontSetting("RyanCo", "HtmlEditor");
    fontSetting.beginGroup("RF-HTML-EDITOR");
    fontSetting.setValue("fontsize", size);
    fontSetting.endGroup();

    foreach(CodeEditor *e, codeEditors)
    {
       QFont newFont(e->font());
       newFont.setPointSize(size);

       e->setFont(newFont);
    }
}

QString Editor::getEditorFont()
{
    CodeEditor *current = codeEditors[getCurrentOpenTabIndex()];

    return current->font().family();
}

vector<CodeEditor *> Editor::getCodeEditors() const
{
    return codeEditors;
}

void Editor::createDirs()
{
    // create project folder if it doesn't exist
    if (!QDir(QDir::homePath() + "/RF-HTML-PROJECTS").exists())
    {
        QDir().mkdir(QDir::homePath() + "/RF-HTML-PROJECTS");
        QMessageBox::information(
            this,
            "Directory Created",
            "A directory has been created in your home folder called: RF-HTML-PROJECTS. It is recommended to save your files there for organization purposes.");
    }

    // create templates folder if it doesn't exist
    if (!QDir(QDir::homePath() + "/RF-HTML-PROJECTS/templates").exists())
    {
        QDir().mkdir(QDir::homePath() + "/RF-HTML-PROJECTS/templates");
    }
}

Editor::~Editor()
{
    delete ui;
}

vector<FileTemplate>* Editor::getTemplates()
{
    return &(fileTemplates);
}

void Editor::readInTemplates()
{
    QFile file(QDir::homePath() + "/RF-HTML-PROJECTS/templates/templates.xml");
    QDomDocument xml;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        xml.setContent(&file);

        QDomNodeList templateNodes = xml.elementsByTagName("Template");
        QDomNodeList templateChildNodes;

        for (int i = 0; i < templateNodes.count(); i++)
        {
            QString name = "";
            QString path = "";
            QString contents = "";
            QString desc = "";

            templateChildNodes = templateNodes.at(i).childNodes();

            for (int j = 0; j < templateChildNodes.count(); j++)
            {
                if (templateChildNodes.at(j).nodeName() == "Name")
                    name = templateChildNodes.at(j).toElement().text();
                if (templateChildNodes.at(j).nodeName() == "Path")
                    path = templateChildNodes.at(j).toElement().text();
                if (templateChildNodes.at(j).nodeName() == "Description")
                    desc = templateChildNodes.at(j).toElement().text();
            }

            contents = readFile(path);
            qDebug() << "\n\nI am here!!\n\n";
            FileTemplate newTemplate(path, name, contents, desc);
            fileTemplates.push_back(newTemplate);
        }
    }
}

void Editor::print()
{
    // get the current editor
    CodeEditor *editor = codeEditors[ui->tabWidget->currentIndex()];

    // get the text in the editor
    QTextDocument *document = editor->document();
    QPrinter printer;

    // open a print dialog
    QPrintDialog* dialog = new QPrintDialog(&printer, this);

    // if the user presses OK
    if (dialog->exec() == QDialog::Accepted)
    {
        // print the document's content
        document->print(&printer);
    }

}

void Editor::openNewSiteDialog()
{
    NewSiteDialog *dialog = new NewSiteDialog(this, this);

    // open the new site dialog
    dialog->show();
}

void Editor::openNewFileDialog()
{
    NewFileDialog *dialog = new NewFileDialog(this, this);

    dialog->show();
}

void Editor::openNewTemplateDialog()
{
    NewTemplateDialog *dialog = new NewTemplateDialog(this, this);

    dialog->show();
}

void Editor::openFindAndReplaceDialog()
{
    FindAndReplaceDialog *dialog = new FindAndReplaceDialog(this, this);

    dialog->show();
}

void Editor::openSettingsDialog()
{
    SettingsDialog *dialog = new SettingsDialog(this, this);

    dialog->show();
}

void Editor::openInsertTagDialog()
{
    InsertTagDialog *dialog = new InsertTagDialog(this, this);

    dialog->show();
}

void Editor::openInsertImageDialog()
{
    InsertImageDialog *dialog = new InsertImageDialog(this, this);

    dialog->show();
}

void Editor::openInsertFormDialog()
{
    InsertFormDialog *dialog = new InsertFormDialog(this, this);

    dialog->show();
}

void Editor::openInsertTextFieldDialog()
{
    InsertTextFieldDialog *dialog = new InsertTextFieldDialog(this, this);

    dialog->show();
}

void Editor::openInsertTextareaDialog()
{
    InsertTextareaDialog *dialog = new InsertTextareaDialog(this, this);

    dialog->show();
}

void Editor::openInsertCheckboxDialog()
{
    InsertCheckboxDialog *dialog = new InsertCheckboxDialog(this, this);

    dialog->show();
}

void Editor::openInsertRadioButtonDialog()
{
    InsertRadioButtonDialog *dialog = new InsertRadioButtonDialog(this, this);

    dialog->show();
}

void Editor::openInsertRadioGroupDialog()
{
    InsertRadioGroupDialog *dialog = new InsertRadioGroupDialog(this, this);

    dialog->show();
}

void Editor::openInsertSelectBoxDialog()
{
    InsertSelectBoxDialog *dialog = new InsertSelectBoxDialog(this, this);

    dialog->show();
}

void Editor::openInsertUploadFieldDialog()
{
    InsertUploadFieldDialog *dialog = new InsertUploadFieldDialog(this, this);

    dialog->show();
}

void Editor::openInsertButtonDialog()
{
    InsertButtonDialog *dialog = new InsertButtonDialog(this, this);

    dialog->show();
}

void Editor::openInsertHiddenFieldDialog()
{
    InsertHiddenFieldDialog *dialog = new InsertHiddenFieldDialog(this, this);

    dialog->show();
}

void Editor::openInsertTableDialog()
{
    InsertTableDialog *dialog = new InsertTableDialog(this, this);

    dialog->show();
}

void Editor::openInsertHyperlinkDialog()
{
    InsertHyperlinkDialog *dialog = new InsertHyperlinkDialog(this, this);

    dialog->show();
}

void Editor::openGetSourceDialog()
{
    GetSourceDialog *dialog = new GetSourceDialog(this, this);

    dialog->show();
}

void Editor::save(int fileIndex)
{
    File *currentFile;
    const CodeEditor *currentEditor;

    if (fileIndex != -1)
    {
        currentFile = &(openFiles[fileIndex]);
        currentEditor = codeEditors[fileIndex];
    }
    else
    {
        currentFile = &(openFiles[ui->tabWidget->currentIndex()]);
        currentEditor = codeEditors[ui->tabWidget->currentIndex()];
    }

    fstream file;

    // if the file has been saved already
    if (currentFile->getLocation() != "")
    {
        // set the file's contents to the text in the textarea
        currentFile->setContents(currentEditor->toPlainText());

        // open the current file
        file.open((currentFile->getLocation() + "/" + currentFile->getName()).toStdString().c_str());

        if (file.is_open())
        {
            // put the file objects's contents into the file
            file << currentFile->getContents().toStdString();

            // remove asterisk in tab text
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), currentFile->getName());
        }
        else
            QMessageBox::information(this, "Problem", "Not saved" + currentFile->getLocation() + currentFile->getName());

        file.close();
    }
    else
    {
        saveAs();
    }
}

void Editor::saveAs()
{
    ofstream wFile;
    QString qFileName;
    QString fileLocation;

    // opens save dialog, returns the path to the created file
    QString filePath = QFileDialog::getSaveFileName(
                this,
                tr("Save HTML Document"),
                QDir::homePath() + "/RF-HTML-PROJECTS",
                tr("HTML Document (*.html);; PHP Script (*.php);; JavaScript File (*.js);; Cascading Style Sheet (*.css)"));

    // set the file name to the path
    string fileName = filePath.toStdString();

    fileLocation = QString::fromStdString(fileName.substr(0, fileName.find_last_of("\\/")));

    // set the name to everything after the last /
    fileName = fileName.substr(fileName.find_last_of("\\/") + 1, fileName.length());

    qFileName = QString::fromStdString(fileName);


    if (qFileName != "")
    {
        // open the new file
        wFile.open(filePath.toStdString().c_str());

        File *currentFile = &(openFiles[ui->tabWidget->currentIndex()]);
        CodeEditor *currentEditor = codeEditors[ui->tabWidget->currentIndex()];

        // set file's contents to the current textarea's
        currentFile->setContents(currentEditor->toPlainText());

        // set the file's location
        currentFile->setLocation(fileLocation);

        // set file's name
        currentFile->setFileName(qFileName);

        // put the first tab's content into the file
        if (wFile.is_open())
        {
            wFile << currentFile->getContents().toStdString();
        }

        // set the current tab's text to the new file name
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), qFileName);

        // create the tree view for the new directory
        createTreeModel();

        wFile.close();
    }
}

void Editor::checkForErrors(QString action)
{
    CodeEditor *currentEditor = codeEditors[ui->tabWidget->currentIndex()];
    QStringList lines = currentEditor->toPlainText().split("\n");
    vector<Error> errors;
    int lessThanSignCount = 0;
    int greaterThanSignCount = 0;

    // check each line for errors
    for (int i = 0; i < lines.count(); i++)
    {
        lessThanSignCount = 0;
        greaterThanSignCount = 0;

        for (int j = 0; j < lines.at(i).length(); j++)
        {
            if (lines.at(i).at(j) == '<')
                lessThanSignCount++;
            if (lines.at(i).at(j) == '>')
                greaterThanSignCount++;
        }

        //if (i == lines.count() - 1)
        //{
            if (lessThanSignCount > greaterThanSignCount)
            {
                Error newError("Syntax Error", "Missing closing '>'", i);
                errors.push_back(newError);
            }
            else if (lessThanSignCount < greaterThanSignCount)
            {
                Error newError("Syntax Error", "Missing opening '<'", i);
                errors.push_back(newError);
            }

        //}

//        if (lines.at(i).contains("<") && !lines.at(i).contains(">"))
//        {
//            Error newError("Syntax Error", "Missing closing '>'", i);
//            errors.push_back(newError);
//        }
//        if (!lines.at(i).contains("<") && lines.at(i).contains(">"))
//        {
//            Error newError("Syntax Error", "Missing opening '<'", i);
//            errors.push_back(newError);
//        }
    }

    // if there are errors
    // then add them to the errors listbox
    if (errors.size() > 0)
    {
        ui->listWidget->clear();

        for (unsigned int i = 0; i < errors.size(); i++)
        {
            QString type = errors[i].getType();
            QString desc = errors[i].getDescription();
            int lineNumber = errors[i].getLineNumber();

            ui->listWidget->addItem(type + ": " + desc + " on line " +  QString::number(lineNumber + 1));
            ui->listWidget->item(i)->setIcon(QIcon(":/images/Error_Icon.png"));
        }

        if (action == "click")
        {
            QTextCursor newCursor = currentEditor->textCursor();
            newCursor.setPosition(0);
            currentEditor->setTextCursor(newCursor);
        }

        highlightErrors(errors);

        //QMessageBox::information(this, tr("You have errors!"), tr("Your document contains errors. Please refer to the error list to view them."));
    }
    else
    {
        ui->listWidget->clear();
        //QMessageBox::information(this, tr("You don't have errors!"), tr("Your document does not contain any errors!"));
    }
}

QString Editor::readFile(QString path)
{
    QString fileContents;
    ifstream rFile;
    string str;
    stringstream ss;


    // open the file
    rFile.open(path.toStdString().c_str());

    if (rFile.is_open())
    {
        // read each line of the file
        while (getline(rFile, str, '\n'))
        {
            ss << str << "\n";
        }
    }

    // replace "\9" with tab character
    fileContents = QString::fromStdString(ss.str());
    fileContents = fileContents.replace("\\9", "\t");

    return fileContents;
}

void Editor::openFile(QString path)
{    
    QString filePath;

    if (path == "")
    {
        // opens a file dialog, returns a path to the selected file
        filePath = QFileDialog::getOpenFileName(
                    this,
                    tr("Open HTML Document"),
                    QDir::homePath(),
                    tr("All Files (*);;HTML Document (*.html);; PHP Script (*.php);; JavaScript File (*.js);; Cascading Style Sheet (*.css)"));
    }
    else
    {
        filePath = path;
    }

    QString fileContents = "";
    QString fileName = "";
    QString newFilePath = "";
    string dirPath = filePath.toStdString();
    QFileSystemModel *model = new QFileSystemModel;
    CodeEditor *firstEditor = codeEditors[0];

    fileName = QString::fromStdString(dirPath.substr(dirPath.find_last_of("\\/") + 1, dirPath.length()));

    // remove the file name in path string
    newFilePath = QString::fromStdString(dirPath.substr(0, dirPath.find_last_of("\\/")));

    // get the contents of the selected file
    fileContents = readFile(filePath);

    if (newFilePath != "")
    {
        if (firstEditor->toPlainText() == "")
        {
            model->setRootPath(newFilePath);

            ui->treeView->setModel(model);
            ui->treeView->setRootIndex(model->index(newFilePath));

            // clear the textarea's contents
            firstEditor->clear();

            // put the file's contents into the textarea
            firstEditor->appendPlainText(fileContents);

            if (fileName != "")
                ui->tabWidget->setTabText(0, fileName);

            openFiles.pop_back();
            openFiles.push_back(File(newFilePath, fileName, fileContents));
        }
        else
        {
            // add a new tab to the tabwidget
            addTab(fileName, fileContents);

            openFiles.push_back(File(newFilePath, fileName, fileContents));
        }
    }

}

void Editor::addTab(QString fileName, QString fileContents, File newFile)
{
    openFiles.push_back(newFile);

    // call base method
    addTab(fileName, fileContents);
}

void Editor::addTab(QString fileName, QString fileContents)
{
    // the new tab and it's contents
    QWidget *newTab = new QWidget(ui->tabWidget, NULL);
    newTab->setObjectName("tab_" + QString::number(getOpenTabCount()));

    QHBoxLayout *layout = new QHBoxLayout;
    CodeEditor *newTextEdit = new CodeEditor(newTab, this);

    newTextEdit->setObjectName("htmlCodeBox" + getOpenTabCount());

    // the font for the new textbox
    QFont font;

    // set font attributes
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    // set tab size and font of textedit
    newTextEdit->setFont(font);
    newTextEdit->setTabStopWidth(60);

    // add textedid to the layout
    layout->addWidget(newTextEdit);

    // add the layout to the tab
    newTab->setLayout(layout);

    // add the file's text to the textedit
    newTextEdit->appendPlainText(fileContents);

    // add the tab to the tabwidget
    ui->tabWidget->addTab(newTab, fileName);

    // add the editor to the list of editors
    codeEditors.push_back(newTextEdit);   
}

void Editor::openFileFromTree(QModelIndex selectedIndex)
{
    int col = selectedIndex.column();
    File *currentFile = &(openFiles[ui->tabWidget->currentIndex()]);

    if (col == 0)
    {
        //qDebug() << selectedIndex.data().toString();
        QVariant data = selectedIndex.data();
        QString filePath = currentFile->getLocation();
        QString fileName = data.toString();
        QString fileContents = readFile(filePath + "/" + fileName);
        File newFile(filePath, fileName, fileContents);

        openFiles.push_back(newFile);

        addTab(fileName, fileContents);
    }

}

void Editor::closeTab(int index)
{
    File currentFile = openFiles[index];

    // if there is more than one tab open
    if (ui->tabWidget->count() > 1)
    {
        if (ui->tabWidget->tabText(index).contains("*"))
        {
            switch( QMessageBox::information( this, "Are you sure?",
                                                  "The file \"" + currentFile.getName() + "\" has been changed. "
                                                  "Would you like to save the file?",
                                                      QMessageBox::Save|QMessageBox::Cancel|QMessageBox::Close))
            {
            case QMessageBox::Save:

                // save the file
                save();

                // if there is only one tab left,
                // close program, otherwise, close tab
                if (index == 0)
                {
                    openFiles.erase(openFiles.begin());
                    codeEditors.erase(codeEditors.begin());
                }
                else
                {
                    openFiles.erase(openFiles.begin() + index);
                    codeEditors.erase(codeEditors.begin() + index);
                }

                break;

            case QMessageBox::Cancel:

                // ignore the event

                break;

            case QMessageBox::Close:

                // if there is only one tab left,
                // close program, otherwise, close tab
                if (index == 0)
                {
                    openFiles.erase(openFiles.begin());
                    codeEditors.erase(codeEditors.begin());
                }
                else
                {
                    openFiles.erase(openFiles.begin() + index);
                    codeEditors.erase(codeEditors.begin() + index);
                }

                break;
            }
        }
        ui->tabWidget->removeTab(index);
    }
    else
    {
        this->close();
    } // end else
}

void Editor::showCodeFullScreen()
{
    CodeEditor *currentEditor = codeEditors[getCurrentOpenTabIndex()];

    qDebug() << "X: " << currentEditor->geometry().x();
    qDebug() << "Y: " << currentEditor->geometry().y();
    qDebug() << "Width: " << currentEditor->geometry().width();
    qDebug() << "Height: " << currentEditor->geometry().height();
    qDebug() << "Tabwidth: " << ui->tabWidget->currentWidget()->width();
    qDebug() << "Tabheight: " << ui->tabWidget->currentWidget()->height();

    // if the editor is not full screen
    if (currentEditor->parent() != this)
    {
        currentEditor->setParent(this);
        currentEditor->showFullScreen();
        currentEditor->setGeometry(0, 0, this->width(), this->height());
    }
    else
    {
        currentEditor->setParent(ui->tabWidget->currentWidget());
        currentEditor->showNormal();
        currentEditor->setGeometry(ui->tabWidget->currentWidget()->geometry());
    }
}

void Editor::createTreeModel()
{
    model = new QFileSystemModel;
    File selectedFile = openFiles[ui->tabWidget->currentIndex()];

    model->setRootPath(selectedFile.getLocation());

    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(selectedFile.getLocation()));
}

void Editor::paste()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->paste();
}

void Editor::copy()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->copy();
}

void Editor::selectAll()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->selectAll();
}

void Editor::redo()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->redo();
}

void Editor::undo()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->undo();
}

void Editor::cut()
{
    CodeEditor *selectedEditor = codeEditors[ui->tabWidget->currentIndex()];

    selectedEditor->cut();
}

void Editor::preview()
{
    File newFile = openFiles[ui->tabWidget->currentIndex()];
    QString currentTabText = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    QUrl url("file:///" + newFile.getLocation() + "/" + newFile.getName());

    if (newFile.getLocation() != "" && !currentTabText.contains("*"))
    {
        QDesktopServices::openUrl(url);
    }
    else
        QMessageBox::information(this, "Save", "You must save before opening this file in a browser");
}


