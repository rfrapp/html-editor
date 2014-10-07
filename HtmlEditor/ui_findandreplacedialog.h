/********************************************************************************
** Form generated from reading UI file 'findandreplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDANDREPLACEDIALOG_H
#define UI_FINDANDREPLACEDIALOG_H

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

class Ui_FindAndReplaceDialog
{
public:
    QLineEdit *findTextbox;
    QLabel *label;
    QLineEdit *replaceTextBox;
    QLabel *label_2;
    QLabel *errorField;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *findButton;
    QPushButton *findAndReplaceButton;
    QPushButton *closeButton;

    void setupUi(QDialog *FindAndReplaceDialog)
    {
        if (FindAndReplaceDialog->objectName().isEmpty())
            FindAndReplaceDialog->setObjectName(QStringLiteral("FindAndReplaceDialog"));
        FindAndReplaceDialog->resize(400, 287);
        findTextbox = new QLineEdit(FindAndReplaceDialog);
        findTextbox->setObjectName(QStringLiteral("findTextbox"));
        findTextbox->setGeometry(QRect(10, 80, 381, 25));
        label = new QLabel(FindAndReplaceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 381, 19));
        replaceTextBox = new QLineEdit(FindAndReplaceDialog);
        replaceTextBox->setObjectName(QStringLiteral("replaceTextBox"));
        replaceTextBox->setGeometry(QRect(10, 170, 381, 25));
        label_2 = new QLabel(FindAndReplaceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 381, 19));
        errorField = new QLabel(FindAndReplaceDialog);
        errorField->setObjectName(QStringLiteral("errorField"));
        errorField->setGeometry(QRect(10, 10, 381, 19));
        layoutWidget = new QWidget(FindAndReplaceDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 240, 378, 36));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        findButton = new QPushButton(layoutWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout->addWidget(findButton);

        findAndReplaceButton = new QPushButton(layoutWidget);
        findAndReplaceButton->setObjectName(QStringLiteral("findAndReplaceButton"));

        horizontalLayout->addWidget(findAndReplaceButton);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        retranslateUi(FindAndReplaceDialog);

        QMetaObject::connectSlotsByName(FindAndReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *FindAndReplaceDialog)
    {
        FindAndReplaceDialog->setWindowTitle(QApplication::translate("FindAndReplaceDialog", "Find and Replace", 0));
        label->setText(QApplication::translate("FindAndReplaceDialog", "Find:", 0));
        label_2->setText(QApplication::translate("FindAndReplaceDialog", "Replace with: ", 0));
        errorField->setText(QString());
        findButton->setText(QApplication::translate("FindAndReplaceDialog", "Find", 0));
        findAndReplaceButton->setText(QApplication::translate("FindAndReplaceDialog", "Find And Replace", 0));
        closeButton->setText(QApplication::translate("FindAndReplaceDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class FindAndReplaceDialog: public Ui_FindAndReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDANDREPLACEDIALOG_H
