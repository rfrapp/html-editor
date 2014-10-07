/********************************************************************************
** Form generated from reading UI file 'newfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILEDIALOG_H
#define UI_NEWFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewFileDialog
{
public:
    QLabel *errorField;
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *templateDescription;
    QComboBox *fileTypeList;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *siteList;
    QComboBox *templateNames;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_5;

    void setupUi(QDialog *NewFileDialog)
    {
        if (NewFileDialog->objectName().isEmpty())
            NewFileDialog->setObjectName(QStringLiteral("NewFileDialog"));
        NewFileDialog->resize(581, 477);
        errorField = new QLabel(NewFileDialog);
        errorField->setObjectName(QStringLiteral("errorField"));
        errorField->setGeometry(QRect(10, 10, 251, 19));
        buttonBox = new QDialogButtonBox(NewFileDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(330, 430, 233, 34));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        templateDescription = new QPlainTextEdit(NewFileDialog);
        templateDescription->setObjectName(QStringLiteral("templateDescription"));
        templateDescription->setGeometry(QRect(300, 130, 271, 281));
        fileTypeList = new QComboBox(NewFileDialog);
        fileTypeList->setObjectName(QStringLiteral("fileTypeList"));
        fileTypeList->setGeometry(QRect(10, 190, 271, 25));
        lineEdit = new QLineEdit(NewFileDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 128, 271, 25));
        label_3 = new QLabel(NewFileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 162, 108, 19));
        layoutWidget = new QWidget(NewFileDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 66, 561, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        siteList = new QComboBox(layoutWidget);
        siteList->setObjectName(QStringLiteral("siteList"));

        horizontalLayout->addWidget(siteList);

        templateNames = new QComboBox(layoutWidget);
        templateNames->setObjectName(QStringLiteral("templateNames"));

        horizontalLayout->addWidget(templateNames);

        layoutWidget1 = new QWidget(NewFileDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 38, 561, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        layoutWidget2 = new QWidget(NewFileDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 100, 561, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);


        retranslateUi(NewFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewFileDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFileDialog)
    {
        NewFileDialog->setWindowTitle(QApplication::translate("NewFileDialog", "Dialog", 0));
        errorField->setText(QString());
        fileTypeList->clear();
        fileTypeList->insertItems(0, QStringList()
         << QApplication::translate("NewFileDialog", "ASPX File", 0)
         << QApplication::translate("NewFileDialog", "Cascading Style-Sheet", 0)
         << QApplication::translate("NewFileDialog", "JavaScript File", 0)
         << QApplication::translate("NewFileDialog", "HTML File", 0)
         << QApplication::translate("NewFileDialog", "PHP Script", 0)
        );
        label_3->setText(QApplication::translate("NewFileDialog", "Select file type:", 0));
        templateNames->clear();
        templateNames->insertItems(0, QStringList()
         << QApplication::translate("NewFileDialog", "(none)", 0)
        );
        label->setText(QApplication::translate("NewFileDialog", "Select the site to add the file to: ", 0));
        label_4->setText(QApplication::translate("NewFileDialog", "Template:", 0));
        label_2->setText(QApplication::translate("NewFileDialog", "Enter file name: ", 0));
        label_5->setText(QApplication::translate("NewFileDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class NewFileDialog: public Ui_NewFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILEDIALOG_H
