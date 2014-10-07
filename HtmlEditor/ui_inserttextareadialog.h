/********************************************************************************
** Form generated from reading UI file 'inserttextareadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTEXTAREADIALOG_H
#define UI_INSERTTEXTAREADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InsertTextareaDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextbox;
    QLabel *label_2;
    QLineEdit *valueTextbox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertTextareaDialog)
    {
        if (InsertTextareaDialog->objectName().isEmpty())
            InsertTextareaDialog->setObjectName(QStringLiteral("InsertTextareaDialog"));
        InsertTextareaDialog->resize(400, 244);
        label = new QLabel(InsertTextareaDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 371, 19));
        nameTextbox = new QLineEdit(InsertTextareaDialog);
        nameTextbox->setObjectName(QStringLiteral("nameTextbox"));
        nameTextbox->setGeometry(QRect(10, 40, 371, 25));
        label_2 = new QLabel(InsertTextareaDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 371, 19));
        valueTextbox = new QLineEdit(InsertTextareaDialog);
        valueTextbox->setObjectName(QStringLiteral("valueTextbox"));
        valueTextbox->setGeometry(QRect(10, 110, 371, 25));
        closeButton = new QPushButton(InsertTextareaDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(270, 200, 112, 34));
        insertButton = new QPushButton(InsertTextareaDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(131, 200, 131, 34));

        retranslateUi(InsertTextareaDialog);

        QMetaObject::connectSlotsByName(InsertTextareaDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertTextareaDialog)
    {
        InsertTextareaDialog->setWindowTitle(QApplication::translate("InsertTextareaDialog", "Insert Textarea", 0));
        label->setText(QApplication::translate("InsertTextareaDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertTextareaDialog", "Default Value:", 0));
        closeButton->setText(QApplication::translate("InsertTextareaDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertTextareaDialog", "Insert Textarea", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertTextareaDialog: public Ui_InsertTextareaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTEXTAREADIALOG_H
