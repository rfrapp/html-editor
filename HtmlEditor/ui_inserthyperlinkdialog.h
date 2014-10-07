/********************************************************************************
** Form generated from reading UI file 'inserthyperlinkdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTHYPERLINKDIALOG_H
#define UI_INSERTHYPERLINKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertHyperlinkDialog
{
public:
    QLabel *label;
    QLineEdit *textTextBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *targetComboBox;
    QPushButton *closeButton;
    QPushButton *insertButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *linkTextBox;
    QPushButton *browseButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *accessKeySpinBox;
    QSpinBox *tabIndexSpinBox;

    void setupUi(QDialog *InsertHyperlinkDialog)
    {
        if (InsertHyperlinkDialog->objectName().isEmpty())
            InsertHyperlinkDialog->setObjectName(QStringLiteral("InsertHyperlinkDialog"));
        InsertHyperlinkDialog->resize(400, 361);
        label = new QLabel(InsertHyperlinkDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 19));
        textTextBox = new QLineEdit(InsertHyperlinkDialog);
        textTextBox->setObjectName(QStringLiteral("textTextBox"));
        textTextBox->setGeometry(QRect(10, 30, 381, 25));
        label_2 = new QLabel(InsertHyperlinkDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 381, 19));
        label_3 = new QLabel(InsertHyperlinkDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 150, 381, 19));
        targetComboBox = new QComboBox(InsertHyperlinkDialog);
        targetComboBox->setObjectName(QStringLiteral("targetComboBox"));
        targetComboBox->setGeometry(QRect(10, 170, 381, 25));
        closeButton = new QPushButton(InsertHyperlinkDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 320, 112, 34));
        insertButton = new QPushButton(InsertHyperlinkDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(141, 320, 131, 34));
        widget = new QWidget(InsertHyperlinkDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 90, 381, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        linkTextBox = new QLineEdit(widget);
        linkTextBox->setObjectName(QStringLiteral("linkTextBox"));

        horizontalLayout->addWidget(linkTextBox);

        browseButton = new QPushButton(widget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout->addWidget(browseButton);

        widget1 = new QWidget(InsertHyperlinkDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 220, 271, 21));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        widget2 = new QWidget(InsertHyperlinkDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 250, 271, 29));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        accessKeySpinBox = new QSpinBox(widget2);
        accessKeySpinBox->setObjectName(QStringLiteral("accessKeySpinBox"));

        horizontalLayout_3->addWidget(accessKeySpinBox);

        tabIndexSpinBox = new QSpinBox(widget2);
        tabIndexSpinBox->setObjectName(QStringLiteral("tabIndexSpinBox"));

        horizontalLayout_3->addWidget(tabIndexSpinBox);


        retranslateUi(InsertHyperlinkDialog);

        QMetaObject::connectSlotsByName(InsertHyperlinkDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertHyperlinkDialog)
    {
        InsertHyperlinkDialog->setWindowTitle(QApplication::translate("InsertHyperlinkDialog", "Insert Hyperlink", 0));
        label->setText(QApplication::translate("InsertHyperlinkDialog", "Text:", 0));
        label_2->setText(QApplication::translate("InsertHyperlinkDialog", "Linked to (web page/file): ", 0));
        label_3->setText(QApplication::translate("InsertHyperlinkDialog", "Target:", 0));
        targetComboBox->clear();
        targetComboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("InsertHyperlinkDialog", "_blank", 0)
         << QApplication::translate("InsertHyperlinkDialog", "new", 0)
         << QApplication::translate("InsertHyperlinkDialog", "_parent", 0)
         << QApplication::translate("InsertHyperlinkDialog", "_self", 0)
         << QApplication::translate("InsertHyperlinkDialog", "_top", 0)
        );
        closeButton->setText(QApplication::translate("InsertHyperlinkDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertHyperlinkDialog", "Insert Hyperlink", 0));
        browseButton->setText(QApplication::translate("InsertHyperlinkDialog", "Browse...", 0));
        label_4->setText(QApplication::translate("InsertHyperlinkDialog", "Access Key:", 0));
        label_5->setText(QApplication::translate("InsertHyperlinkDialog", "Tab Index:", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertHyperlinkDialog: public Ui_InsertHyperlinkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTHYPERLINKDIALOG_H
