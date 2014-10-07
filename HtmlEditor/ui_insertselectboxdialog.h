/********************************************************************************
** Form generated from reading UI file 'insertselectboxdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTSELECTBOXDIALOG_H
#define UI_INSERTSELECTBOXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertSelectBoxDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QLabel *label_2;
    QTextEdit *optionsTextBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QPushButton *closeButton;

    void setupUi(QDialog *InsertSelectBoxDialog)
    {
        if (InsertSelectBoxDialog->objectName().isEmpty())
            InsertSelectBoxDialog->setObjectName(QStringLiteral("InsertSelectBoxDialog"));
        InsertSelectBoxDialog->resize(400, 300);
        label = new QLabel(InsertSelectBoxDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 381, 19));
        nameTextBox = new QLineEdit(InsertSelectBoxDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 50, 381, 25));
        label_2 = new QLabel(InsertSelectBoxDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 381, 19));
        optionsTextBox = new QTextEdit(InsertSelectBoxDialog);
        optionsTextBox->setObjectName(QStringLiteral("optionsTextBox"));
        optionsTextBox->setGeometry(QRect(10, 130, 371, 107));
        widget = new QWidget(InsertSelectBoxDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(140, 260, 252, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        insertButton = new QPushButton(widget);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout->addWidget(insertButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(InsertSelectBoxDialog);

        QMetaObject::connectSlotsByName(InsertSelectBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertSelectBoxDialog)
    {
        InsertSelectBoxDialog->setWindowTitle(QApplication::translate("InsertSelectBoxDialog", "Insert Select Box", 0));
        label->setText(QApplication::translate("InsertSelectBoxDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertSelectBoxDialog", "Options (one per line):", 0));
        insertButton->setText(QApplication::translate("InsertSelectBoxDialog", "Insert Select Box", 0));
        closeButton->setText(QApplication::translate("InsertSelectBoxDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertSelectBoxDialog: public Ui_InsertSelectBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTSELECTBOXDIALOG_H
