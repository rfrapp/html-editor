/********************************************************************************
** Form generated from reading UI file 'insertformdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTFORMDIALOG_H
#define UI_INSERTFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertFormDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *closeButton;
    QPushButton *addButton;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *method_get;
    QRadioButton *method_post;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *actionPathTextBox;
    QPushButton *browseButton;
    QButtonGroup *enctypeGroup;
    QButtonGroup *methodGroup;

    void setupUi(QDialog *InsertFormDialog)
    {
        if (InsertFormDialog->objectName().isEmpty())
            InsertFormDialog->setObjectName(QStringLiteral("InsertFormDialog"));
        InsertFormDialog->resize(400, 415);
        label = new QLabel(InsertFormDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 181, 19));
        lineEdit = new QLineEdit(InsertFormDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 371, 25));
        label_4 = new QLabel(InsertFormDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 270, 201, 19));
        closeButton = new QPushButton(InsertFormDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(270, 370, 112, 34));
        addButton = new QPushButton(InsertFormDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(150, 370, 112, 34));
        groupBox = new QGroupBox(InsertFormDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 180, 371, 71));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 34, 351, 19));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        method_get = new QRadioButton(widget);
        enctypeGroup = new QButtonGroup(InsertFormDialog);
        enctypeGroup->setObjectName(QStringLiteral("enctypeGroup"));
        enctypeGroup->addButton(method_get);
        method_get->setObjectName(QStringLiteral("method_get"));
        method_get->setChecked(true);

        horizontalLayout_2->addWidget(method_get);

        method_post = new QRadioButton(widget);
        enctypeGroup->addButton(method_post);
        method_post->setObjectName(QStringLiteral("method_post"));

        horizontalLayout_2->addWidget(method_post);

        groupBox_2 = new QGroupBox(InsertFormDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 90, 371, 71));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 341, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        methodGroup = new QButtonGroup(InsertFormDialog);
        methodGroup->setObjectName(QStringLiteral("methodGroup"));
        methodGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        methodGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        layoutWidget1 = new QWidget(InsertFormDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 290, 371, 36));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        actionPathTextBox = new QLineEdit(layoutWidget1);
        actionPathTextBox->setObjectName(QStringLiteral("actionPathTextBox"));

        horizontalLayout_3->addWidget(actionPathTextBox);

        browseButton = new QPushButton(layoutWidget1);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout_3->addWidget(browseButton);


        retranslateUi(InsertFormDialog);

        QMetaObject::connectSlotsByName(InsertFormDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertFormDialog)
    {
        InsertFormDialog->setWindowTitle(QApplication::translate("InsertFormDialog", "Insert a Form", 0));
        label->setText(QApplication::translate("InsertFormDialog", "ID:", 0));
        label_4->setText(QApplication::translate("InsertFormDialog", "Action:", 0));
        closeButton->setText(QApplication::translate("InsertFormDialog", "Close", 0));
        addButton->setText(QApplication::translate("InsertFormDialog", "Add Form", 0));
        groupBox->setTitle(QApplication::translate("InsertFormDialog", "Encryption type: ", 0));
        method_get->setText(QApplication::translate("InsertFormDialog", "None", 0));
        method_post->setText(QApplication::translate("InsertFormDialog", "Multipart/form-data", 0));
        groupBox_2->setTitle(QApplication::translate("InsertFormDialog", "Method:", 0));
        radioButton->setText(QApplication::translate("InsertFormDialog", "GET", 0));
        radioButton_2->setText(QApplication::translate("InsertFormDialog", "POST", 0));
        browseButton->setText(QApplication::translate("InsertFormDialog", "Browse...", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertFormDialog: public Ui_InsertFormDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTFORMDIALOG_H
