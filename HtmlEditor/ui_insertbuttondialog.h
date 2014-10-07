/********************************************************************************
** Form generated from reading UI file 'insertbuttondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTBUTTONDIALOG_H
#define UI_INSERTBUTTONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InsertButtonDialog
{
public:
    QLabel *label;
    QComboBox *typeBox;
    QLabel *label_2;
    QLineEdit *idTextBox;
    QLabel *label_3;
    QLineEdit *valueTextBox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertButtonDialog)
    {
        if (InsertButtonDialog->objectName().isEmpty())
            InsertButtonDialog->setObjectName(QStringLiteral("InsertButtonDialog"));
        InsertButtonDialog->resize(400, 300);
        label = new QLabel(InsertButtonDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 381, 19));
        typeBox = new QComboBox(InsertButtonDialog);
        typeBox->setObjectName(QStringLiteral("typeBox"));
        typeBox->setGeometry(QRect(10, 40, 381, 25));
        label_2 = new QLabel(InsertButtonDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 381, 19));
        idTextBox = new QLineEdit(InsertButtonDialog);
        idTextBox->setObjectName(QStringLiteral("idTextBox"));
        idTextBox->setGeometry(QRect(10, 110, 381, 25));
        label_3 = new QLabel(InsertButtonDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 381, 19));
        valueTextBox = new QLineEdit(InsertButtonDialog);
        valueTextBox->setObjectName(QStringLiteral("valueTextBox"));
        valueTextBox->setGeometry(QRect(10, 190, 381, 25));
        closeButton = new QPushButton(InsertButtonDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 260, 112, 34));
        insertButton = new QPushButton(InsertButtonDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(160, 260, 112, 34));

        retranslateUi(InsertButtonDialog);

        QMetaObject::connectSlotsByName(InsertButtonDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertButtonDialog)
    {
        InsertButtonDialog->setWindowTitle(QApplication::translate("InsertButtonDialog", "Insert Button", 0));
        label->setText(QApplication::translate("InsertButtonDialog", "Type:", 0));
        typeBox->clear();
        typeBox->insertItems(0, QStringList()
         << QApplication::translate("InsertButtonDialog", "Submit", 0)
         << QApplication::translate("InsertButtonDialog", "Other", 0)
        );
        label_2->setText(QApplication::translate("InsertButtonDialog", "ID:", 0));
        label_3->setText(QApplication::translate("InsertButtonDialog", "Value:", 0));
        closeButton->setText(QApplication::translate("InsertButtonDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertButtonDialog", "Insert Button", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertButtonDialog: public Ui_InsertButtonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTBUTTONDIALOG_H
