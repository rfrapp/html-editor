/********************************************************************************
** Form generated from reading UI file 'newtemplatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTEMPLATEDIALOG_H
#define UI_NEWTEMPLATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewTemplateDialog
{
public:
    QLabel *label;
    QLineEdit *templateNameTextBox;
    QLabel *label_2;
    QComboBox *templateTypeComboBox;
    QLabel *errorLabel;
    QPlainTextEdit *templateDescriptionTextBox;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *closeButton;

    void setupUi(QDialog *NewTemplateDialog)
    {
        if (NewTemplateDialog->objectName().isEmpty())
            NewTemplateDialog->setObjectName(QStringLiteral("NewTemplateDialog"));
        NewTemplateDialog->resize(401, 403);
        label = new QLabel(NewTemplateDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 70, 161, 19));
        templateNameTextBox = new QLineEdit(NewTemplateDialog);
        templateNameTextBox->setObjectName(QStringLiteral("templateNameTextBox"));
        templateNameTextBox->setGeometry(QRect(10, 90, 371, 25));
        label_2 = new QLabel(NewTemplateDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 141, 19));
        templateTypeComboBox = new QComboBox(NewTemplateDialog);
        templateTypeComboBox->setObjectName(QStringLiteral("templateTypeComboBox"));
        templateTypeComboBox->setGeometry(QRect(10, 160, 371, 25));
        errorLabel = new QLabel(NewTemplateDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(10, 20, 371, 19));
        templateDescriptionTextBox = new QPlainTextEdit(NewTemplateDialog);
        templateDescriptionTextBox->setObjectName(QStringLiteral("templateDescriptionTextBox"));
        templateDescriptionTextBox->setGeometry(QRect(10, 230, 371, 107));
        label_3 = new QLabel(NewTemplateDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 210, 361, 19));
        widget = new QWidget(NewTemplateDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 360, 235, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(NewTemplateDialog);

        QMetaObject::connectSlotsByName(NewTemplateDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTemplateDialog)
    {
        NewTemplateDialog->setWindowTitle(QApplication::translate("NewTemplateDialog", "New Template", 0));
        label->setText(QApplication::translate("NewTemplateDialog", "Template Name:", 0));
        label_2->setText(QApplication::translate("NewTemplateDialog", "Template Type:", 0));
        templateTypeComboBox->clear();
        templateTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("NewTemplateDialog", "ASPX Template", 0)
         << QApplication::translate("NewTemplateDialog", "Cascading Style-Sheet Template", 0)
         << QApplication::translate("NewTemplateDialog", "JavaScript Template", 0)
         << QApplication::translate("NewTemplateDialog", "HTML Template", 0)
         << QApplication::translate("NewTemplateDialog", "PHP Template", 0)
        );
        errorLabel->setText(QString());
        label_3->setText(QApplication::translate("NewTemplateDialog", "Description:", 0));
        addButton->setText(QApplication::translate("NewTemplateDialog", "Add", 0));
        closeButton->setText(QApplication::translate("NewTemplateDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class NewTemplateDialog: public Ui_NewTemplateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTEMPLATEDIALOG_H
