/********************************************************************************
** Form generated from reading UI file 'inserthiddenfielddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTHIDDENFIELDDIALOG_H
#define UI_INSERTHIDDENFIELDDIALOG_H

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

class Ui_InsertHiddenFieldDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QLabel *label_2;
    QLineEdit *valueTextBox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertHiddenFieldDialog)
    {
        if (InsertHiddenFieldDialog->objectName().isEmpty())
            InsertHiddenFieldDialog->setObjectName(QStringLiteral("InsertHiddenFieldDialog"));
        InsertHiddenFieldDialog->resize(400, 221);
        label = new QLabel(InsertHiddenFieldDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 381, 19));
        nameTextBox = new QLineEdit(InsertHiddenFieldDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 40, 381, 25));
        label_2 = new QLabel(InsertHiddenFieldDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 381, 19));
        valueTextBox = new QLineEdit(InsertHiddenFieldDialog);
        valueTextBox->setObjectName(QStringLiteral("valueTextBox"));
        valueTextBox->setGeometry(QRect(10, 110, 381, 25));
        closeButton = new QPushButton(InsertHiddenFieldDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 170, 112, 34));
        insertButton = new QPushButton(InsertHiddenFieldDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(111, 170, 161, 34));

        retranslateUi(InsertHiddenFieldDialog);

        QMetaObject::connectSlotsByName(InsertHiddenFieldDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertHiddenFieldDialog)
    {
        InsertHiddenFieldDialog->setWindowTitle(QApplication::translate("InsertHiddenFieldDialog", "Dialog", 0));
        label->setText(QApplication::translate("InsertHiddenFieldDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertHiddenFieldDialog", "Value:", 0));
        closeButton->setText(QApplication::translate("InsertHiddenFieldDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertHiddenFieldDialog", "Insert Hidden Field", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertHiddenFieldDialog: public Ui_InsertHiddenFieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTHIDDENFIELDDIALOG_H
