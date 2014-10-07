/********************************************************************************
** Form generated from reading UI file 'inserttagdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTAGDIALOG_H
#define UI_INSERTTAGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InsertTagDialog
{
public:
    QListWidget *listWidget;
    QPushButton *closeButton;
    QPushButton *insertButton;

    void setupUi(QDialog *InsertTagDialog)
    {
        if (InsertTagDialog->objectName().isEmpty())
            InsertTagDialog->setObjectName(QStringLiteral("InsertTagDialog"));
        InsertTagDialog->resize(400, 300);
        listWidget = new QListWidget(InsertTagDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 381, 241));
        closeButton = new QPushButton(InsertTagDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 260, 112, 34));
        insertButton = new QPushButton(InsertTagDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(160, 260, 112, 34));

        retranslateUi(InsertTagDialog);

        QMetaObject::connectSlotsByName(InsertTagDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertTagDialog)
    {
        InsertTagDialog->setWindowTitle(QApplication::translate("InsertTagDialog", "Insert Tag", 0));
        closeButton->setText(QApplication::translate("InsertTagDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertTagDialog", "Insert", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertTagDialog: public Ui_InsertTagDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTAGDIALOG_H
