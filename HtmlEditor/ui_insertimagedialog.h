/********************************************************************************
** Form generated from reading UI file 'insertimagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTIMAGEDIALOG_H
#define UI_INSERTIMAGEDIALOG_H

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

class Ui_InsertImageDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *browseButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *insertButton;
    QPushButton *closeButton;
    QLineEdit *altText;
    QLabel *label_2;
    QLabel *errorLabel;

    void setupUi(QDialog *InsertImageDialog)
    {
        if (InsertImageDialog->objectName().isEmpty())
            InsertImageDialog->setObjectName(QStringLiteral("InsertImageDialog"));
        InsertImageDialog->resize(475, 262);
        label = new QLabel(InsertImageDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 271, 16));
        layoutWidget = new QWidget(InsertImageDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 451, 36));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        browseButton = new QPushButton(layoutWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout->addWidget(browseButton);

        layoutWidget1 = new QWidget(InsertImageDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(230, 220, 235, 36));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        insertButton = new QPushButton(layoutWidget1);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout_2->addWidget(insertButton);

        closeButton = new QPushButton(layoutWidget1);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_2->addWidget(closeButton);

        altText = new QLineEdit(InsertImageDialog);
        altText->setObjectName(QStringLiteral("altText"));
        altText->setGeometry(QRect(10, 170, 451, 25));
        label_2 = new QLabel(InsertImageDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 150, 301, 19));
        errorLabel = new QLabel(InsertImageDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(10, 10, 451, 19));

        retranslateUi(InsertImageDialog);

        QMetaObject::connectSlotsByName(InsertImageDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertImageDialog)
    {
        InsertImageDialog->setWindowTitle(QApplication::translate("InsertImageDialog", "Insert Image", 0));
        label->setText(QApplication::translate("InsertImageDialog", "Select an image: ", 0));
        browseButton->setText(QApplication::translate("InsertImageDialog", "Browse", 0));
        insertButton->setText(QApplication::translate("InsertImageDialog", "Insert", 0));
        closeButton->setText(QApplication::translate("InsertImageDialog", "Close", 0));
        label_2->setText(QApplication::translate("InsertImageDialog", "Alt text (for screen readers):", 0));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InsertImageDialog: public Ui_InsertImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTIMAGEDIALOG_H
