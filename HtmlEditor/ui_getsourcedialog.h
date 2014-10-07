/********************************************************************************
** Form generated from reading UI file 'getsourcedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSOURCEDIALOG_H
#define UI_GETSOURCEDIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetSourceDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *getSourceButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *GetSourceDialog)
    {
        if (GetSourceDialog->objectName().isEmpty())
            GetSourceDialog->setObjectName(QStringLiteral("GetSourceDialog"));
        GetSourceDialog->resize(400, 154);
        lineEdit = new QLineEdit(GetSourceDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 381, 20));
        label = new QLabel(GetSourceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 16));
        label_2 = new QLabel(GetSourceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 381, 21));
        widget = new QWidget(GetSourceDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(230, 120, 162, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        getSourceButton = new QPushButton(widget);
        getSourceButton->setObjectName(QStringLiteral("getSourceButton"));

        horizontalLayout->addWidget(getSourceButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(GetSourceDialog);

        QMetaObject::connectSlotsByName(GetSourceDialog);
    } // setupUi

    void retranslateUi(QDialog *GetSourceDialog)
    {
        GetSourceDialog->setWindowTitle(QApplication::translate("GetSourceDialog", "Dialog", 0));
        label->setText(QApplication::translate("GetSourceDialog", "Type URL Here:", 0));
        label_2->setText(QApplication::translate("GetSourceDialog", "Use of another websites code may be subject to copyright violations.", 0));
        getSourceButton->setText(QApplication::translate("GetSourceDialog", "Get Source", 0));
        cancelButton->setText(QApplication::translate("GetSourceDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class GetSourceDialog: public Ui_GetSourceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSOURCEDIALOG_H
