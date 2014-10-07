/********************************************************************************
** Form generated from reading UI file 'insertuploadfielddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTUPLOADFIELDDIALOG_H
#define UI_INSERTUPLOADFIELDDIALOG_H

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

class Ui_InsertUploadFieldDialog
{
public:
    QLabel *label;
    QLineEdit *nameTextBox;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertUploadFieldDialog)
    {
        if (InsertUploadFieldDialog->objectName().isEmpty())
            InsertUploadFieldDialog->setObjectName(QStringLiteral("InsertUploadFieldDialog"));
        InsertUploadFieldDialog->resize(400, 146);
        label = new QLabel(InsertUploadFieldDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 381, 19));
        nameTextBox = new QLineEdit(InsertUploadFieldDialog);
        nameTextBox->setObjectName(QStringLiteral("nameTextBox"));
        nameTextBox->setGeometry(QRect(10, 40, 381, 25));
        closeButton = new QPushButton(InsertUploadFieldDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 100, 112, 34));
        insertButton = new QPushButton(InsertUploadFieldDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(160, 100, 112, 34));

        retranslateUi(InsertUploadFieldDialog);

        QMetaObject::connectSlotsByName(InsertUploadFieldDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertUploadFieldDialog)
    {
        InsertUploadFieldDialog->setWindowTitle(QApplication::translate("InsertUploadFieldDialog", "Dialog", 0));
        label->setText(QApplication::translate("InsertUploadFieldDialog", "Name:", 0));
        closeButton->setText(QApplication::translate("InsertUploadFieldDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertUploadFieldDialog", "Insert Field", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertUploadFieldDialog: public Ui_InsertUploadFieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTUPLOADFIELDDIALOG_H
