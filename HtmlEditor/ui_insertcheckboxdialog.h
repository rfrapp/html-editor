/********************************************************************************
** Form generated from reading UI file 'insertcheckboxdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTCHECKBOXDIALOG_H
#define UI_INSERTCHECKBOXDIALOG_H

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

class Ui_InsertCheckboxDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QLabel *label_2;
    QLineEdit *idTextBox;
    QLabel *label_3;
    QLineEdit *labelTextBox;
    QLabel *errorLabel;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertCheckboxDialog)
    {
        if (InsertCheckboxDialog->objectName().isEmpty())
            InsertCheckboxDialog->setObjectName(QStringLiteral("InsertCheckboxDialog"));
        InsertCheckboxDialog->resize(400, 300);
        label = new QLabel(InsertCheckboxDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 371, 16));
        nameTextBox = new QLineEdit(InsertCheckboxDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 70, 381, 20));
        label_2 = new QLabel(InsertCheckboxDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 381, 16));
        idTextBox = new QLineEdit(InsertCheckboxDialog);
        idTextBox->setObjectName(QStringLiteral("idTextBox"));
        idTextBox->setGeometry(QRect(10, 130, 381, 20));
        label_3 = new QLabel(InsertCheckboxDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 180, 381, 16));
        labelTextBox = new QLineEdit(InsertCheckboxDialog);
        labelTextBox->setObjectName(QStringLiteral("labelTextBox"));
        labelTextBox->setGeometry(QRect(10, 200, 381, 20));
        errorLabel = new QLabel(InsertCheckboxDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(10, 20, 381, 16));
        closeButton = new QPushButton(InsertCheckboxDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(320, 270, 75, 23));
        insertButton = new QPushButton(InsertCheckboxDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(224, 270, 91, 23));

        retranslateUi(InsertCheckboxDialog);

        QMetaObject::connectSlotsByName(InsertCheckboxDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertCheckboxDialog)
    {
        InsertCheckboxDialog->setWindowTitle(QApplication::translate("InsertCheckboxDialog", "Dialog", 0));
        label->setText(QApplication::translate("InsertCheckboxDialog", "Name:", 0));
        label_2->setText(QApplication::translate("InsertCheckboxDialog", "ID (different from name):", 0));
        label_3->setText(QApplication::translate("InsertCheckboxDialog", "Label:", 0));
        errorLabel->setText(QString());
        closeButton->setText(QApplication::translate("InsertCheckboxDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertCheckboxDialog", "Insert Checkbox", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertCheckboxDialog: public Ui_InsertCheckboxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTCHECKBOXDIALOG_H
