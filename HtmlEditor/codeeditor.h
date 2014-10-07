#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QObject>
#include "htmlsyntaxhighlighter.h"

class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
class Editor;
class LineNumberArea;
class QCompleter;
class QStringList;
class QListWidget;
class QTimer;
class QStringList;

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit CodeEditor(QWidget *parent = 0, Editor *e = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    void treeAreaPaintEvent(QPaintEvent *event);
    int treeAreaWidth();
    void setHighlighter(QSyntaxHighlighter *newHighlighter);
    int getTabCount();
    void highlightLine(int lineNumber);

protected:
    void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void updateTreeWidth();
    void addTreeLevel(int startline, int endline);

private:
    QWidget *lineNumberArea;
    QWidget *treeArea;
    QSyntaxHighlighter *highlighter;

    // used to handle multi-key presess
    QTimer *timer;
    Editor *editor;
    QListWidget *completer;

    int tabCount;
    int lastKeyPressed;

    // the last tag entered
    QString lastTag;

    QStringList enteredTagList;

    void handleMultiKeyPresses(QKeyEvent *e);
    void autoCloseTag(QKeyEvent *e);
    QStringList fillCompleter();
    void moveCompleter(QKeyEvent *e);
};

class TreeArea : public QWidget
{
  public:
    TreeArea(CodeEditor *editor) : QWidget(editor)
    {
        codeEditor = editor;
    }
    QSize sizeHint() const
    {
        return QSize(codeEditor->treeAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *e)
    {
        codeEditor->treeAreaPaintEvent(e);
    }

private:
    CodeEditor *codeEditor;
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor)
    {
        codeEditor = editor;
    }

    QSize sizeHint() const
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event)
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};


#endif
