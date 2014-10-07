/********************************************************************************
** Form generated from reading UI file 'insertradiogroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTRADIOGROUPDIALOG_H
#define UI_INSERTRADIOGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InsertRadioGroupDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QLabel *label_2;
    QPushButton *closeButton;
    QPushButton *insertButton;
    QTextEdit *optionsTextBox;

    void setupUi(QDialog *InsertRadioGroupDialog)
    {
        if (InsertRadioGroupDialog->objectName().isEmpty())
            InsertRadioGroupDialog->setObjectName(QStringLiteral("InsertRadioGroupDialog"));
        InsertRadioGroupDialog->resize(400, 338);
        label = new QLabel(InsertRadioGroupDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 16));
        nameTextBox = new QLineEdit(InsertRadioGroupDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 30, 381, 20));
        label_2 = new QLabel(InsertRadioGroupDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 381, 16));
        closeButton = new QPushButton(InsertRadioGroupDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(320, 310, 75, 23));
        insertButton = new QPushButton(InsertRadioGroupDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(240, 310, 75, 23));
        optionsTextBox = new QTextEdit(InsertRadioGroupDialog);
        optionsTextBox->setObjectName(QStringLiteral("optionsTextBox"));
        optionsTextBox->setGeometry(QRect(10, 100, 381, 191));

        retranslateUi(InsertRadioGroupDialog);

        QMetaObject::connectSlotsByName(InsertRadioGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertRadioGroupDialog)
    {
        InsertRadioGroupDialog->setWindowTitle(QApplication::translate("InsertRadioGroupDialog", "Dialog", 0));
        label->setText(QApplication::translate("InsertRadioGroupDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertRadioGroupDialog", "Options (one option per line):", 0));
        closeButton->setText(QApplication::translate("InsertRadioGroupDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertRadioGroupDialog", "Insert Group", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertRadioGroupDialog: public Ui_InsertRadioGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTRADIOGROUPDIALOG_H
