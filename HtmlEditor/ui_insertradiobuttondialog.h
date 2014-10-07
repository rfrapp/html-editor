/********************************************************************************
** Form generated from reading UI file 'insertradiobuttondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTRADIOBUTTONDIALOG_H
#define UI_INSERTRADIOBUTTONDIALOG_H

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

class Ui_InsertRadioButtonDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QLabel *label_2;
    QLineEdit *idTextBox;
    QLabel *label_3;
    QLineEdit *labelTextBox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertRadioButtonDialog)
    {
        if (InsertRadioButtonDialog->objectName().isEmpty())
            InsertRadioButtonDialog->setObjectName(QStringLiteral("InsertRadioButtonDialog"));
        InsertRadioButtonDialog->resize(400, 300);
        label = new QLabel(InsertRadioButtonDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 381, 16));
        nameTextBox = new QLineEdit(InsertRadioButtonDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 50, 381, 20));
        label_2 = new QLabel(InsertRadioButtonDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 381, 16));
        idTextBox = new QLineEdit(InsertRadioButtonDialog);
        idTextBox->setObjectName(QStringLiteral("idTextBox"));
        idTextBox->setGeometry(QRect(10, 120, 381, 20));
        label_3 = new QLabel(InsertRadioButtonDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 381, 16));
        labelTextBox = new QLineEdit(InsertRadioButtonDialog);
        labelTextBox->setObjectName(QStringLiteral("labelTextBox"));
        labelTextBox->setGeometry(QRect(10, 190, 381, 20));
        closeButton = new QPushButton(InsertRadioButtonDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(310, 270, 75, 23));
        insertButton = new QPushButton(InsertRadioButtonDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(184, 270, 121, 23));

        retranslateUi(InsertRadioButtonDialog);

        QMetaObject::connectSlotsByName(InsertRadioButtonDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertRadioButtonDialog)
    {
        InsertRadioButtonDialog->setWindowTitle(QApplication::translate("InsertRadioButtonDialog", "Dialog", 0));
        label->setText(QApplication::translate("InsertRadioButtonDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertRadioButtonDialog", "ID (different from name):", 0));
        label_3->setText(QApplication::translate("InsertRadioButtonDialog", "Label:", 0));
        closeButton->setText(QApplication::translate("InsertRadioButtonDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertRadioButtonDialog", "Insert Radio Button", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertRadioButtonDialog: public Ui_InsertRadioButtonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTRADIOBUTTONDIALOG_H
