/********************************************************************************
** Form generated from reading UI file 'inserttextfielddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTEXTFIELDDIALOG_H
#define UI_INSERTTEXTFIELDDIALOG_H

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

class Ui_InsertTextFieldDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nameBox;
    QLineEdit *valueBox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertTextFieldDialog)
    {
        if (InsertTextFieldDialog->objectName().isEmpty())
            InsertTextFieldDialog->setObjectName(QStringLiteral("InsertTextFieldDialog"));
        InsertTextFieldDialog->resize(400, 213);
        label = new QLabel(InsertTextFieldDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 371, 19));
        label_2 = new QLabel(InsertTextFieldDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 371, 19));
        nameBox = new QLineEdit(InsertTextFieldDialog);
        nameBox->setObjectName(QStringLiteral("nameBox"));
        nameBox->setGeometry(QRect(10, 40, 371, 25));
        valueBox = new QLineEdit(InsertTextFieldDialog);
        valueBox->setObjectName(QStringLiteral("valueBox"));
        valueBox->setGeometry(QRect(10, 110, 371, 25));
        closeButton = new QPushButton(InsertTextFieldDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 170, 112, 34));
        insertButton = new QPushButton(InsertTextFieldDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(151, 170, 121, 34));

        retranslateUi(InsertTextFieldDialog);

        QMetaObject::connectSlotsByName(InsertTextFieldDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertTextFieldDialog)
    {
        InsertTextFieldDialog->setWindowTitle(QApplication::translate("InsertTextFieldDialog", "Insert Text Field", 0));
        label->setText(QApplication::translate("InsertTextFieldDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertTextFieldDialog", "Default Text:", 0));
        closeButton->setText(QApplication::translate("InsertTextFieldDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertTextFieldDialog", "Insert text field", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertTextFieldDialog: public Ui_InsertTextFieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTEXTFIELDDIALOG_H
