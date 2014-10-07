/********************************************************************************
** Form generated from reading UI file 'newsitedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSITEDIALOG_H
#define UI_NEWSITEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NewSiteDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *errorField;

    void setupUi(QDialog *NewSiteDialog)
    {
        if (NewSiteDialog->objectName().isEmpty())
            NewSiteDialog->setObjectName(QStringLiteral("NewSiteDialog"));
        NewSiteDialog->resize(400, 200);
        buttonBox = new QDialogButtonBox(NewSiteDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 160, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(NewSiteDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 60, 381, 21));
        label = new QLabel(NewSiteDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 381, 16));
        comboBox = new QComboBox(NewSiteDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 120, 381, 22));
        label_2 = new QLabel(NewSiteDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 381, 16));
        errorField = new QLabel(NewSiteDialog);
        errorField->setObjectName(QStringLiteral("errorField"));
        errorField->setGeometry(QRect(10, 10, 381, 19));

        retranslateUi(NewSiteDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewSiteDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewSiteDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewSiteDialog);
    } // setupUi

    void retranslateUi(QDialog *NewSiteDialog)
    {
        NewSiteDialog->setWindowTitle(QApplication::translate("NewSiteDialog", "New Site", 0));
        label->setText(QApplication::translate("NewSiteDialog", "Enter new site name:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("NewSiteDialog", "HTML", 0)
         << QApplication::translate("NewSiteDialog", "PHP", 0)
         << QApplication::translate("NewSiteDialog", "ASPX", 0)
        );
        label_2->setText(QApplication::translate("NewSiteDialog", "Site Type:", 0));
        errorField->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewSiteDialog: public Ui_NewSiteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSITEDIALOG_H
