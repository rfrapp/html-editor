/********************************************************************************
** Form generated from reading UI file 'inserttabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTABLEDIALOG_H
#define UI_INSERTTABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertTableDialog
{
public:
    QGroupBox *groupBox;
    QSpinBox *borderSpinBox;
    QLabel *pxLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *closeButton;
    QPushButton *insertButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *rowsSpinBox;
    QSpinBox *colsSpinBox;
    QButtonGroup *borderOptions;

    void setupUi(QDialog *InsertTableDialog)
    {
        if (InsertTableDialog->objectName().isEmpty())
            InsertTableDialog->setObjectName(QStringLiteral("InsertTableDialog"));
        InsertTableDialog->resize(252, 300);
        groupBox = new QGroupBox(InsertTableDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 111));
        borderSpinBox = new QSpinBox(groupBox);
        borderSpinBox->setObjectName(QStringLiteral("borderSpinBox"));
        borderSpinBox->setGeometry(QRect(100, 30, 71, 25));
        pxLabel = new QLabel(groupBox);
        pxLabel->setObjectName(QStringLiteral("pxLabel"));
        pxLabel->setGeometry(QRect(180, 30, 31, 20));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 58, 57));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        borderOptions = new QButtonGroup(InsertTableDialog);
        borderOptions->setObjectName(QStringLiteral("borderOptions"));
        borderOptions->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        borderOptions->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        closeButton = new QPushButton(InsertTableDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(130, 260, 112, 34));
        insertButton = new QPushButton(InsertTableDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(10, 260, 112, 34));
        widget1 = new QWidget(InsertTableDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 170, 231, 21));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        widget2 = new QWidget(InsertTableDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 200, 231, 29));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        rowsSpinBox = new QSpinBox(widget2);
        rowsSpinBox->setObjectName(QStringLiteral("rowsSpinBox"));

        horizontalLayout_2->addWidget(rowsSpinBox);

        colsSpinBox = new QSpinBox(widget2);
        colsSpinBox->setObjectName(QStringLiteral("colsSpinBox"));

        horizontalLayout_2->addWidget(colsSpinBox);

        label->raise();
        rowsSpinBox->raise();
        label_2->raise();
        colsSpinBox->raise();
        rowsSpinBox->raise();
        groupBox->raise();
        closeButton->raise();
        insertButton->raise();

        retranslateUi(InsertTableDialog);

        QMetaObject::connectSlotsByName(InsertTableDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertTableDialog)
    {
        InsertTableDialog->setWindowTitle(QApplication::translate("InsertTableDialog", "Insert Table", 0));
        groupBox->setTitle(QApplication::translate("InsertTableDialog", "Border", 0));
        pxLabel->setText(QApplication::translate("InsertTableDialog", "px", 0));
        radioButton->setText(QApplication::translate("InsertTableDialog", "Yes", 0));
        radioButton_2->setText(QApplication::translate("InsertTableDialog", "No", 0));
        closeButton->setText(QApplication::translate("InsertTableDialog", "Close", 0));
        insertButton->setText(QApplication::translate("InsertTableDialog", "Insert Table", 0));
        label->setText(QApplication::translate("InsertTableDialog", "Rows:", 0));
        label_2->setText(QApplication::translate("InsertTableDialog", "Columns:", 0));
    } // retranslateUi

};

namespace Ui {
    class InsertTableDialog: public Ui_InsertTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTABLEDIALOG_H
