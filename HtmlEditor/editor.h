#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <QtCore>
#include <QtGui>
#include "file.h"
#include "filetemplate.h"
#include "codeeditor.h"
#include "newsitedialog.h"
#include "newfiledialog.h"
#include "newtemplatedialog.h"
#include "inserttagdialog.h"
#include "insertformdialog.h"
#include "inserttextfielddialog.h"
#include "inserttextareadialog.h"
#include "insertcheckboxdialog.h"
#include "insertradiobuttondialog.h"
#include "insertradiogroupdialog.h"
#include "insertselectboxdialog.h"
#include "insertuploadfielddialog.h"
#include "insertbuttondialog.h"
#include "inserthiddenfielddialog.h"
#include "getsourcedialog.h"
#include "settingsdialog.h"
#include "insertimagedialog.h"
#include "inserttabledialog.h"
#include "inserthyperlinkdialog.h"
#include "findandreplacedialog.h"
#include <vector>
#include <QFileSystemModel>

using namespace std;
class Error;

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

    vector<FileTemplate> *getTemplates();
    void readInTemplates();
    QString readFile(QString);

    // adding tab by opening file
    void addTab(QString, QString);

    // adding tab with shortcut or menu
    void addTab(QString, QString, File);
    void addAsteriskToTab();
    int getOpenTabCount();
    void createNewSite(QString, QString);
    void createNewFile(QString, QString, QString, bool loadFromTemplate = false, int templateIndex = -1);
    void findText(QString);
    void replaceText(QString, QString);
    int getCurrentOpenTabIndex();
    void setTextWrapping(bool);
    void setFontSize(int);
    void setEditorFont(QString fontName = "Courier New");
    void addNewTemplate(QString tName, QString tType, QString tDesc);
    void insertTag(QString tag);
    void insertImage(QString imgPath, QString altText);
    void insertForm(QString id, QString method, QString enctype, QString action);
    void insertTextField(QString name, QString value);
    void insertTextarea(QString name, QString value);
    void insertCheckbox(QString name, QString id, QString text);
    void insertRadioButton(QString name, QString id, QString text);
    void insertRadioGroup(QString name, QStringList radioText);
    void insertSelectBox(QString name, QStringList options);
    void insertUploadField(QString name);
    void insertButton(QString type, QString id, QString value);
    void insertHiddenField(QString name, QString value);
    void insertTable(int rows, int columns, int borderSize);
    void insertHyperlink(QString text, QString link, QString target, int accessKey, int tabIndex);

    QString getEditorFont();
    vector<CodeEditor *> getCodeEditors() const;

private:

    Ui::Editor *ui;
    QFileSystemModel *model;

    // the files that the user has open
    vector<File> openFiles;
    vector<FileTemplate> fileTemplates;

    // references to the editors in each tab
    vector<CodeEditor *> codeEditors;

    // initializing functions
    void init();
    void createDirs();
    void wireEvents();
    void createTemplates();
    void highlightErrors(vector<Error>);

protected:
    virtual void closeEvent(QCloseEvent *);

public slots:

    // file operations
    void saveAs();
    void save(int fileIndex = -1);
    void openFile(QString path = "");
    void preview();
    void print();

    // event handlers to open dialogs
    void openNewSiteDialog();
    void openNewFileDialog();
    void openNewTemplateDialog();
    void openFindAndReplaceDialog();
    void openSettingsDialog();
    void openInsertTagDialog();
    void openInsertImageDialog();
    void openInsertFormDialog();
    void openInsertTextFieldDialog();
    void openInsertTextareaDialog();
    void openInsertCheckboxDialog();
    void openInsertRadioButtonDialog();
    void openInsertRadioGroupDialog();
    void openInsertSelectBoxDialog();
    void openInsertUploadFieldDialog();
    void openInsertButtonDialog();
    void openInsertHiddenFieldDialog();
    void openInsertTableDialog();
    void openInsertHyperlinkDialog();
    void openGetSourceDialog();

    // tab stuff
    void closeTab(int);
    void showCodeFullScreen();

    void checkForErrors(QString action = "click");

private slots:

    // editor event handlers
    void cut();
    void copy();
    void paste();
    void selectAll();
    void undo();
    void redo();

    // tree model event handlers
    void openFileFromTree(QModelIndex);
    void createTreeModel();

    // window show/hide event handlers
    void hideTree();
    void hideEditor();
    void hideErrorBox();

};

#endif // EDITOR_H
