/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QAction *actionOpen;
    QAction *actionOpen_From_Template;
    QAction *actionSave;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionTest_in_browser;
    QAction *actionCheck_for_errors;
    QAction *actionHTML_Page;
    QAction *actionTemplate;
    QAction *actionPaste;
    QAction *actionSelect_All;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionNew_Site;
    QAction *actionNew_File;
    QAction *actionPrint;
    QAction *actionFind_and_Replace;
    QAction *actionSettings;
    QAction *actionFile_Tree_View;
    QAction *actionCode_Editor;
    QAction *actionError_List;
    QAction *actionShow_Full_Screen;
    QAction *actionTag;
    QAction *actionImage;
    QAction *actionForm;
    QAction *actionText_Field;
    QAction *actionTextarea;
    QAction *actionCheckbox;
    QAction *actionRadio_Button;
    QAction *actionRadio_Group;
    QAction *actionSelect_Box;
    QAction *actionFile_Upload_field;
    QAction *actionButton;
    QAction *actionHidden_field;
    QAction *actionTable;
    QAction *actionHyperlink;
    QAction *actionGet_Source;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QWidget *tab_2;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSave_As;
    QMenu *menuEdit;
    QMenu *menuCode;
    QMenu *menuWindow;
    QMenu *menuInsert;
    QMenu *menuForm_Element;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->resize(1313, 629);
        actionGet_Source = new QAction(Editor);
        actionGet_Source->setObjectName(QStringLiteral("actionGet_Source"));
        actionGet_Source->setText("Get Source");

        actionOpen = new QAction(Editor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/openicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionOpen_From_Template = new QAction(Editor);
        actionOpen_From_Template->setObjectName(QStringLiteral("actionOpen_From_Template"));
        actionSave = new QAction(Editor);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/saveicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionCut = new QAction(Editor);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/cuticon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon2);
        actionCopy = new QAction(Editor);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/copyicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon3);
        actionTest_in_browser = new QAction(Editor);
        actionTest_in_browser->setObjectName(QStringLiteral("actionTest_in_browser"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/previewicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTest_in_browser->setIcon(icon4);
        actionCheck_for_errors = new QAction(Editor);
        actionCheck_for_errors->setObjectName(QStringLiteral("actionCheck_for_errors"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/checkforerrorsicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheck_for_errors->setIcon(icon5);
        actionHTML_Page = new QAction(Editor);
        actionHTML_Page->setObjectName(QStringLiteral("actionHTML_Page"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/saveasicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHTML_Page->setIcon(icon6);
        actionTemplate = new QAction(Editor);
        actionTemplate->setObjectName(QStringLiteral("actionTemplate"));
        actionPaste = new QAction(Editor);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/pasteicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon7);
        actionSelect_All = new QAction(Editor);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        actionUndo = new QAction(Editor);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/undoicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(Editor);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/redoicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionNew_Site = new QAction(Editor);
        actionNew_Site->setObjectName(QStringLiteral("actionNew_Site"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/newsiteicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Site->setIcon(icon10);
        actionNew_File = new QAction(Editor);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/newfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon11);
        actionPrint = new QAction(Editor);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/printicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon12);
        actionFind_and_Replace = new QAction(Editor);
        actionFind_and_Replace->setObjectName(QStringLiteral("actionFind_and_Replace"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/findandreplaceicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_and_Replace->setIcon(icon13);
        actionSettings = new QAction(Editor);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/settingsicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon14);
        actionFile_Tree_View = new QAction(Editor);
        actionFile_Tree_View->setObjectName(QStringLiteral("actionFile_Tree_View"));
        actionFile_Tree_View->setCheckable(true);
        actionFile_Tree_View->setChecked(true);
        actionCode_Editor = new QAction(Editor);
        actionCode_Editor->setObjectName(QStringLiteral("actionCode_Editor"));
        actionCode_Editor->setCheckable(true);
        actionCode_Editor->setChecked(true);
        actionError_List = new QAction(Editor);
        actionError_List->setObjectName(QStringLiteral("actionError_List"));
        actionError_List->setCheckable(true);
        actionError_List->setChecked(true);
        actionShow_Full_Screen = new QAction(Editor);
        actionShow_Full_Screen->setObjectName(QStringLiteral("actionShow_Full_Screen"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/expandicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_Full_Screen->setIcon(icon15);
        actionTag = new QAction(Editor);
        actionTag->setObjectName(QStringLiteral("actionTag"));
        actionImage = new QAction(Editor);
        actionImage->setObjectName(QStringLiteral("actionImage"));
        actionForm = new QAction(Editor);
        actionForm->setObjectName(QStringLiteral("actionForm"));
        actionText_Field = new QAction(Editor);
        actionText_Field->setObjectName(QStringLiteral("actionText_Field"));
        actionTextarea = new QAction(Editor);
        actionTextarea->setObjectName(QStringLiteral("actionTextarea"));
        actionCheckbox = new QAction(Editor);
        actionCheckbox->setObjectName(QStringLiteral("actionCheckbox"));
        actionRadio_Button = new QAction(Editor);
        actionRadio_Button->setObjectName(QStringLiteral("actionRadio_Button"));
        actionRadio_Group = new QAction(Editor);
        actionRadio_Group->setObjectName(QStringLiteral("actionRadio_Group"));
        actionSelect_Box = new QAction(Editor);
        actionSelect_Box->setObjectName(QStringLiteral("actionSelect_Box"));
        actionFile_Upload_field = new QAction(Editor);
        actionFile_Upload_field->setObjectName(QStringLiteral("actionFile_Upload_field"));
        actionButton = new QAction(Editor);
        actionButton->setObjectName(QStringLiteral("actionButton"));
        actionHidden_field = new QAction(Editor);
        actionHidden_field->setObjectName(QStringLiteral("actionHidden_field"));
        actionTable = new QAction(Editor);
        actionTable->setObjectName(QStringLiteral("actionTable"));
        actionHyperlink = new QAction(Editor);
        actionHyperlink->setObjectName(QStringLiteral("actionHyperlink"));
        centralWidget = new QWidget(Editor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        splitter->addWidget(treeView);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        splitter->addWidget(listWidget);

        horizontalLayout->addWidget(splitter);

        Editor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Editor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1313, 31));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSave_As = new QMenu(menuFile);
        menuSave_As->setObjectName(QStringLiteral("menuSave_As"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuCode = new QMenu(menuBar);
        menuCode->setObjectName(QStringLiteral("menuCode"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        menuForm_Element = new QMenu(menuInsert);
        menuForm_Element->setObjectName(QStringLiteral("menuForm_Element"));
        Editor->setMenuBar(menuBar);
        statusBar = new QStatusBar(Editor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Editor->setStatusBar(statusBar);
        toolBar = new QToolBar(Editor);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Editor->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuCode->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionNew_Site);
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuSave_As->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionPrint);
        menuSave_As->addAction(actionHTML_Page);
        menuSave_As->addAction(actionTemplate);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSettings);
        menuCode->addAction(actionTest_in_browser);
        menuCode->addAction(actionCheck_for_errors);
        menuCode->addAction(actionFind_and_Replace);
        menuCode->addAction(actionShow_Full_Screen);
        menuCode->addAction(actionGet_Source);
        menuWindow->addAction(actionFile_Tree_View);
        menuWindow->addAction(actionCode_Editor);
        menuWindow->addAction(actionError_List);
        menuInsert->addAction(actionTag);
        menuInsert->addAction(actionImage);
        menuInsert->addAction(menuForm_Element->menuAction());
        menuInsert->addAction(actionHyperlink);
        menuForm_Element->addAction(actionForm);
        menuForm_Element->addSeparator();
        menuForm_Element->addAction(actionText_Field);
        menuForm_Element->addAction(actionTextarea);
        menuForm_Element->addAction(actionCheckbox);
        menuForm_Element->addAction(actionRadio_Button);
        menuForm_Element->addAction(actionRadio_Group);
        menuForm_Element->addAction(actionSelect_Box);
        menuForm_Element->addAction(actionFile_Upload_field);
        menuForm_Element->addAction(actionButton);
        menuForm_Element->addAction(actionHidden_field);
        menuForm_Element->addAction(actionTable);
        toolBar->addAction(actionNew_Site);
        toolBar->addAction(actionNew_File);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionHTML_Page);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_Full_Screen);
        toolBar->addAction(actionTest_in_browser);
        toolBar->addAction(actionCheck_for_errors);
        toolBar->addAction(actionFind_and_Replace);
        toolBar->addAction(actionSettings);

        retranslateUi(Editor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Editor", 0));
        actionOpen->setText(QApplication::translate("Editor", "Open...", 0));
        actionOpen_From_Template->setText(QApplication::translate("Editor", "Open From Template", 0));
        actionSave->setText(QApplication::translate("Editor", "Save", 0));
        actionCut->setText(QApplication::translate("Editor", "Cut", 0));
        actionCopy->setText(QApplication::translate("Editor", "Copy", 0));
        actionTest_in_browser->setText(QApplication::translate("Editor", "Test in browser", 0));
        actionCheck_for_errors->setText(QApplication::translate("Editor", "Check for errors", 0));
        actionHTML_Page->setText(QApplication::translate("Editor", "Web Page/Script...", 0));
        actionTemplate->setText(QApplication::translate("Editor", "Template...", 0));
        actionPaste->setText(QApplication::translate("Editor", "Paste", 0));
        actionSelect_All->setText(QApplication::translate("Editor", "Select All", 0));
        actionUndo->setText(QApplication::translate("Editor", "Undo", 0));
        actionRedo->setText(QApplication::translate("Editor", "Redo", 0));
        actionNew_Site->setText(QApplication::translate("Editor", "New Site...", 0));
        actionNew_File->setText(QApplication::translate("Editor", "New File...", 0));
        actionPrint->setText(QApplication::translate("Editor", "Print...", 0));
        actionFind_and_Replace->setText(QApplication::translate("Editor", "Find and Replace...", 0));
        actionSettings->setText(QApplication::translate("Editor", "Settings...", 0));
        actionFile_Tree_View->setText(QApplication::translate("Editor", "File View", 0));
        actionCode_Editor->setText(QApplication::translate("Editor", "Code Editor", 0));
        actionError_List->setText(QApplication::translate("Editor", "Error List", 0));
        actionShow_Full_Screen->setText(QApplication::translate("Editor", "Show Full Screen", 0));
        actionTag->setText(QApplication::translate("Editor", "Tag...", 0));
        actionImage->setText(QApplication::translate("Editor", "Image...", 0));
        actionForm->setText(QApplication::translate("Editor", "Form...", 0));
        actionText_Field->setText(QApplication::translate("Editor", "Text Field...", 0));
        actionTextarea->setText(QApplication::translate("Editor", "Textarea...", 0));
        actionCheckbox->setText(QApplication::translate("Editor", "Checkbox...", 0));
        actionRadio_Button->setText(QApplication::translate("Editor", "Radio Button...", 0));
        actionRadio_Group->setText(QApplication::translate("Editor", "Radio Group...", 0));
        actionSelect_Box->setText(QApplication::translate("Editor", "Select Box...", 0));
        actionFile_Upload_field->setText(QApplication::translate("Editor", "File Upload field...", 0));
        actionButton->setText(QApplication::translate("Editor", "Button...", 0));
        actionHidden_field->setText(QApplication::translate("Editor", "Hidden field...", 0));
        actionTable->setText(QApplication::translate("Editor", "Table...", 0));
        actionHyperlink->setText(QApplication::translate("Editor", "Hyperlink...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Editor", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Editor", "Tab 2", 0));
        menuFile->setTitle(QApplication::translate("Editor", "File", 0));
        menuSave_As->setTitle(QApplication::translate("Editor", "Save As", 0));
        menuEdit->setTitle(QApplication::translate("Editor", "Edit", 0));
        menuCode->setTitle(QApplication::translate("Editor", "Code", 0));
        menuWindow->setTitle(QApplication::translate("Editor", "Window", 0));
        menuInsert->setTitle(QApplication::translate("Editor", "Insert", 0));
        menuForm_Element->setTitle(QApplication::translate("Editor", "Form Element", 0));
        toolBar->setWindowTitle(QApplication::translate("Editor", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
