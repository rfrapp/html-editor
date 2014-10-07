#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T11:22:41
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += printsupport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MAC_SDK = macosx10.9

TARGET = HtmlEditor
TEMPLATE = app


SOURCES += main.cpp\
        editor.cpp \
    file.cpp \
    filetemplate.cpp \
    codeeditor.cpp \
    newsitedialog.cpp \
    newfiledialog.cpp \
    findandreplacedialog.cpp \
    htmlsyntaxhighlighter.cpp \
    settingsdialog.cpp \
    newtemplatedialog.cpp \
    javascripthighlighter.cpp \
    inserttagdialog.cpp \
    insertimagedialog.cpp \
    insertformdialog.cpp \
    inserttextfielddialog.cpp \
    inserttextareadialog.cpp \
    insertcheckboxdialog.cpp \
    insertradiobuttondialog.cpp \
    insertradiogroupdialog.cpp \
    insertselectboxdialog.cpp \
    insertuploadfielddialog.cpp \
    insertbuttondialog.cpp \
    inserthiddenfielddialog.cpp \
    inserttabledialog.cpp \
    inserthyperlinkdialog.cpp \
    error.cpp \
    getsourcedialog.cpp

HEADERS  += editor.h \
    file.h \
    filetemplate.h \
    codeeditor.h \
    newsitedialog.h \
    newfiledialog.h \
    findandreplacedialog.h \
    htmlsyntaxhighlighter.h \
    settingsdialog.h \
    newtemplatedialog.h \
    javascripthighlighter.h \
    inserttagdialog.h \
    insertimagedialog.h \
    insertformdialog.h \
    inserttextfielddialog.h \
    inserttextareadialog.h \
    insertcheckboxdialog.h \
    insertradiobuttondialog.h \
    insertradiogroupdialog.h \
    insertselectboxdialog.h \
    insertuploadfielddialog.h \
    insertbuttondialog.h \
    inserthiddenfielddialog.h \
    inserttabledialog.h \
    inserthyperlinkdialog.h \
    error.h \
    getsourcedialog.h

FORMS    += editor.ui \
    newsitedialog.ui \
    newfiledialog.ui \
    findandreplacedialog.ui \
    settingsdialog.ui \
    newtemplatedialog.ui \
    inserttagdialog.ui \
    insertimagedialog.ui \
    insertformdialog.ui \
    inserttextfielddialog.ui \
    inserttextareadialog.ui \
    insertcheckboxdialog.ui \
    insertradiobuttondialog.ui \
    insertradiogroupdialog.ui \
    insertselectboxdialog.ui \
    insertuploadfielddialog.ui \
    insertbuttondialog.ui \
    inserthiddenfielddialog.ui \
    inserttabledialog.ui \
    inserthyperlinkdialog.ui \
    getsourcedialog.ui

RESOURCES += \
    images.qrc
