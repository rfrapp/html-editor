#include <QtWidgets>
#include <QMessageBox>
#include <QCompleter>
#include <QDebug>
#include <QListWidget>
#include <QStringList>
#include <QTimer>
#include "codeeditor.h"
#include "editor.h"
#include "file.h"
#include "javascripthighlighter.h"

CodeEditor::CodeEditor(QWidget *parent, Editor *e) : QPlainTextEdit(parent)
{
    if (e)
        editor = e;

    // instantiate timer
    timer = new QTimer(this);

    // initialize the syntax highlighter
    highlighter = new HtmlSyntaxHighlighter(this, this->document());

    // initialize vars
    tabCount = 0;
    lastKeyPressed = -1;
    lastTag = "";

    // create the line number area
    lineNumberArea = new LineNumberArea(this);

    treeArea = new TreeArea(this);

    // wire events
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    updateLineNumberAreaWidth(0);
    updateTreeWidth();

    // highlight the current line in the editor
    highlightCurrentLine();

    // tell the editor not to use text-wrapping
    this->setWordWrapMode(QTextOption::NoWrap);
}

QStringList CodeEditor::fillCompleter()
{
    QStringList tagList;

    tagList << "<!-- -->" <<
    "<!doctype>" << "<a>" <<
    "<abbr>" << "<acronym>" <<
    "<address>" << "<applet>" <<
    "<area>" << "<b>" << "<base>" <<
    "<basefont>" << "<bdo>" <<
    "<big>" << "<blockquote>" <<
    "<body>" << "<br>" << "<button>" <<
    "<caption>" << "<center>" <<
    "<cite>" << "<code>" <<
    "<col>" << "<colgroup>" <<
    "<dd>" << "<del>" << "<dfn>" <<
    "<dir>" << "<div>" << "<dl>" <<
    "<dt>" << "<em>" << "<fieldset>" <<
    "<font>" << "<form>" << "<frame>" <<
    "<frameset>" << "<h1>" << "<h2>" <<
    "<h3>" << "<h4>" << "<h5>" << "<h6>" <<
    "<head>" << "<hr>" << "<html>" << "<i>" <<
    "<iframe>" << "<img>" << "<input>" << "<ins>" <<
    "<isindex>" << "<kbd>" << "<label>" <<
    "<legend>" << "<li>" << "<link>" <<
    "<map>" << "<menu>" <<
    "<meta>" << "<noframes>" <<
    "<noscript>" << "<object>" << "<ol>" <<
    "<optgroup>" << "<option>" << "<p>" <<
    "<param>" << "<pre>" << "<q>" << "<s>" <<
    "<samp>" << "<script>" << "<select>" <<
    "<small>" << "<span>" << "<strike>" <<
    "<strong>" << "<style>" << "<sub>" <<
    "<sup>" << "<table>" << "<tbody>" <<
    "<td>" << "<textarea>" << "<tfoot>" <<
    "<th>" << "<thead>" << "<title>" <<
    "<tr>" << "<tt>" << "<u>" << "<ul>" << "<var>";


    return tagList;
}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;

    // gets the number of text blocks in the document
    // if there are none, set it to 1
    int max = qMax(1, blockCount());

    // gets the number of digits in the line number area
    while (max >= 10)
    {
        max /= 10;
        ++digits;
    }

    // gets the width if '9' and multiplies that by the number of digits
    int space = fontMetrics().width(QLatin1Char('9')) * digits;

    // return the width for the line number area
    // add 15px to the width for aesthetics
    return space + 28;
}

void CodeEditor::treeAreaPaintEvent(QPaintEvent *event)
{
    // the object that paints the tree area
    // on the screen
    QPainter painter(treeArea);

    // fills the tree area with a light gray color
    painter.fillRect(event->rect(), QColor("#cccccc"));

}

int CodeEditor::treeAreaWidth()
{
    return 20;
}

void CodeEditor::setHighlighter(QSyntaxHighlighter *newHighlighter)
{
    highlighter = newHighlighter;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    // set the margins within the textarea for the line numbers
    setViewportMargins(lineNumberAreaWidth() + treeAreaWidth(), 0, 0, 0);
}


void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void CodeEditor::updateTreeWidth()
{
    // set the margins within the textarea for the line numbers
    setViewportMargins(lineNumberAreaWidth() + treeAreaWidth(), 0, 0, 0);
}

void CodeEditor::addTreeLevel(int startline, int endline)
{
    QPainter *painter = new QPainter(treeArea);
    QRect tcRect = QPlainTextEdit::cursorRect();
    QRectF target(2.5, tcRect.y(), 15, 16);
    QImage collapseIcon("://images/collapseicon.jpg");

    painter->drawImage(target, collapseIcon);

}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    // call the base resize method
    QPlainTextEdit::resizeEvent(e);

    // a rectangle of everything within the textarea's margins
    QRect cr = contentsRect();

    // resize the line number area with starting position at (0, 0)
    // with the line number area's width, and with the textarea's height
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
    treeArea->setGeometry(cr.left() + lineNumberAreaWidth(), cr.top(), treeAreaWidth(), cr.height());
}

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    // if the user is allowed to type in the textarea
    if (!isReadOnly())
    {
        QTextEdit::ExtraSelection selection;

        // sets the color to highlight the current line in
        QColor lineColor = QColor(Qt::yellow).lighter(160);

        // sets the color of the line
        selection.format.setBackground(lineColor);

        // changes the color accross the width of the textarea
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);

        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    // apply the changes
    setExtraSelections(extraSelections);
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    // the object that paints the line number area
    // on the screen
    QPainter painter(lineNumberArea);

    // fills the line number area with a light gray color
    painter.fillRect(event->rect(), QColor("#3399ff"));


    QTextBlock block = firstVisibleBlock();

    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom())
    {
        if (block.isVisible() && bottom >= event->rect().top())
        {
            QString number = QString::number(blockNumber + 1);

            // sets the color to draw the numbers
            painter.setPen(Qt::white);

            // draw the line number, center aligned
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignCenter, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

int CodeEditor::getTabCount()
{
    return tabCount;
}

void CodeEditor::highlightLine(int lineNumber)
{
    QStringList lines = toPlainText().split("\n");
    QString line = lines.at(lineNumber);
    int startIndex = toPlainText().indexOf(line, textCursor().anchor());

    QList<QTextEdit::ExtraSelection> extraSelections = this->extraSelections();
    QTextEdit::ExtraSelection selection;

    // sets the color to highlight the line in
    QColor lineColor = QColor(Qt::red).lighter(160);

    // sets the color of the line
    selection.format.setBackground(lineColor);

    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    selection.cursor.setPosition(startIndex);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    //selection.cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, (endIndex - startIndex) + 1);
    extraSelections.append(selection);

    setExtraSelections(extraSelections);
}

void CodeEditor::handleMultiKeyPresses(QKeyEvent *e)
{
    // save file
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_S && timer->remainingTime() > 0)
    {
        editor->save();
        timer->stop();
    }

    // open new tab
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_T && timer->remainingTime() > 0)
    {
        File newFile("", "untitled-" + QString::number(editor->getOpenTabCount() + 1) + "*", "");
        editor->addTab(newFile.getName(), "", newFile);
        timer->stop();
    }

    // open file
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_O && timer->remainingTime() > 0)
    {
        editor->openFile();
        timer->stop();
    }

    // preview file in default browser
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_B && timer->remainingTime() > 0)
    {
        editor->preview();
        timer->stop();
    }

    // print
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_P && timer->remainingTime() > 0)
    {
        editor->print();
        timer->stop();
    }

    // close current tab
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_F4 && timer->remainingTime() > 0)
    {
        editor->closeTab(editor->getCurrentOpenTabIndex());
        timer->stop();
    }

    // open find and replace dialog
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_F && timer->remainingTime() > 0)
    {
        editor->openFindAndReplaceDialog();
        timer->stop();
    }

    // open find and replace dialog
    if (lastKeyPressed == Qt::Key_Control && e->key() == Qt::Key_E && timer->remainingTime() > 0)
    {
        editor->showCodeFullScreen();
        timer->stop();
    }
}

void CodeEditor::autoCloseTag(QKeyEvent *e)
{
    QTextCursor newCursor = textCursor();
    QString tagWithAttributes = "";
    QString textBeforeCursor = "";
    int counter = 0;
    int cursorIndex = 0;
    int lastOpenTagIndex = 0;


    // add the pressed key to the editor
    QPlainTextEdit::keyPressEvent(e);


    // Last Entered Tag name retrieval:
    // get the cursor position in the textarea
    // get all chars from the last '<' before the cursor pos
    // if that string contains a space, get everything after the '<' to the space
    // otherwise, get everything until the '>'

    cursorIndex = textCursor().position();

    // add all text in the textarea before the cursor
    for (int i = 0; i < cursorIndex; i++)
    {
        textBeforeCursor.append(toPlainText().at(i));
    }

    // get the index of the start of the last opened tag
    for (int i = textBeforeCursor.length(); i > 0; i--)
    {
        if (textBeforeCursor[i] == '<')
        {
            lastOpenTagIndex = i;
            break;
        }
    }

    // get everything from opening '<' to closing '>'
    tagWithAttributes = QString::fromStdString(
                textBeforeCursor.toStdString().substr(
                lastOpenTagIndex, cursorIndex));


    // reset counter for use in while loop
    counter = 1;

    // loop through the tag's contents and get everything
    // before a space and add it to the last tag variable
    while (counter < tagWithAttributes.length() - 1)
    {
        if (tagWithAttributes.at(counter) == ' ')
        {
            break;
        }
        else
            lastTag.append(tagWithAttributes.at(counter));

        counter++;
    }

    if (!lastTag.contains("/") && !lastTag.contains("\n") &&
            !lastTag.contains("?") && !lastTag.contains("%") &&
            !lastTag.contains("!") && !lastTag.contains("-"))
    {
        if (lastTag == "body" || lastTag == "html")
        {
            // add closing tag to textarea
            insertPlainText("</" + lastTag + ">");

            // set the cursor position to be inbetween the last tag and it's closing tag
            newCursor.setPosition(textCursor().position() - (3 + lastTag.length()));

            // set the textarea's cursor to the new one
            this->setTextCursor(newCursor);

            insertPlainText("\n\n");

            if (tabCount > 0)
            {
                counter = 0;
                while (counter < tabCount)
                {
                    insertPlainText("\t");
                    counter++;

                    if (tabCount >= 1)
                        tabCount--;
                }
            }
        }

        // add closing tag only if it needs it
        else if (lastTag != "br" && lastTag != "img"
                && lastTag != "input" && lastTag != "hr"
                && (lastTag != "!doctype" && lastTag != "!DOCTYPE")
                && lastTag != "")
        {
            // add closing tag to textarea
            insertPlainText("</" + lastTag + ">");

            // set the cursor position to be inbetween the last tag and it's closing tag
            newCursor.setPosition(textCursor().position() - (3 + lastTag.length()));

            // set the textarea's cursor to the new one
            this->setTextCursor(newCursor);
        }
    }
}

void CodeEditor::keyPressEvent(QKeyEvent *e)
{
    if (e->key() != Qt::Key_Control)
    {
        // tell the user that saving is necessary
        editor->addAsteriskToTab();
    }

    lastTag.clear();

    QTextCursor newCursor = textCursor();
    int counter = 0;

    // if the editor was cleared, reset tab count
    if (toPlainText().trimmed().length() < 2)
        tabCount = 0;


    // if the tab key was pressed
    if (e->key() == Qt::Key_Tab)
    {
        tabCount++;

        if (textCursor().selectedText() != "")
        {
            newCursor = textCursor();
            QString selectedText = newCursor.selection().toPlainText();
            int selectionEnd = newCursor.selectionEnd();
            int selectionStart = newCursor.selectionStart();
            QStringList lines = selectedText.split("\n");
            QString indentedText = "";

            for (int i = 0; i < lines.count(); i++)
            {
                lines[i].insert(0, "\t");
            }

            newCursor.removeSelectedText();

            indentedText = lines.join("\n");

            newCursor.setPosition(newCursor.selectionStart());

            newCursor.insertText(indentedText);

            newCursor.setPosition(selectionEnd, QTextCursor::KeepAnchor);
            newCursor.setPosition(selectionStart, QTextCursor::KeepAnchor);

            this->setTextCursor(newCursor);
        }
        else
        {
            // perform the default action
            QPlainTextEdit::keyPressEvent(e);
        }
    }

    else if (e->key() == Qt::Key_Backspace)
    {
        if (textCursor().selectedText().contains("\t"))
        {
            // if the user deleted tabs characters, then decrease tabCount by 1
            for (int i = 0; i < textCursor().selectedText().length(); i++)
            {
                if (textCursor().selectedText().at(i) == '\t')
                    tabCount--;
            }
        }

        QPlainTextEdit::keyPressEvent(e);
    }

    else if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
    {
        QTextBlock block = textCursor().block();
        int tabsInLastBlock = 0;

        for (int i = 0; i < block.text().length(); i++)
        {
            if (block.text().at(i) == '\t')
                tabsInLastBlock++;
        }

        QPlainTextEdit::keyPressEvent(e);

        while (counter < tabsInLastBlock)
        {
            insertPlainText("\t");
            counter++;
        }

        tabCount = tabsInLastBlock;
    }
    else if (e->key() == Qt::Key_QuoteDbl)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "\"")
        {
            QPlainTextEdit::keyPressEvent(e);

            // add closing quotation when one is opened
            insertPlainText("\"");

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_ParenLeft)
    {
        if (toPlainText().mid(textCursor().position(), 1) != ")")
        {
            QPlainTextEdit::keyPressEvent(e);

            // add closing parenthesi when one is opened
            insertPlainText(")");

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_ParenRight)
    {
        if (toPlainText().mid(textCursor().position(), 1) != ")")
        {
            QPlainTextEdit::keyPressEvent(e);

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_Apostrophe)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "'")
        {
            QPlainTextEdit::keyPressEvent(e);

            // add closing single quote when one is opened
            insertPlainText("'");

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_BraceLeft)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "}")
        {
            QPlainTextEdit::keyPressEvent(e);

            // add closing brace when one is opened
            insertPlainText("}");

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_BraceRight)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "}")
        {
            QPlainTextEdit::keyPressEvent(e);

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_BracketLeft)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "]")
        {
            QPlainTextEdit::keyPressEvent(e);

            // add closing bracket when one is opened
            insertPlainText("]");

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_BracketRight)
    {
        if (toPlainText().mid(textCursor().position(), 1) != "]")
        {
            QPlainTextEdit::keyPressEvent(e);

            newCursor.setPosition(textCursor().position() - 1);

            this->setTextCursor(newCursor);
        }
        else
        {
            newCursor.setPosition(textCursor().position() + 1);

            this->setTextCursor(newCursor);
        }
    }
    else if (e->key() == Qt::Key_Equal)
    {
        QPlainTextEdit::keyPressEvent(e);

        // add quotes after equals sign
        insertPlainText("\"\"");

        newCursor.setPosition(textCursor().position() - 1);

        this->setTextCursor(newCursor);
    }
    else if (e->key() == Qt::Key_Less)
    {
        addTreeLevel(0, 0);
        QPlainTextEdit::keyPressEvent(e);
    }
    else if (e->key() == Qt::Key_Greater)
    {
        autoCloseTag(e);
    }
    else if (e->key() == Qt::Key_Control)
    {
        timer->start();
        timer->setInterval(500);
    }
    else
        QPlainTextEdit::keyPressEvent(e);

    handleMultiKeyPresses(e);

    lastKeyPressed = e->key();

    //moveCompleter(e);

    editor->checkForErrors("keyPress");
}

void CodeEditor::moveCompleter(QKeyEvent *e)
{
    QStringList lines = toPlainText().split("\n");

    completer->move(textCursor().positionInBlock() * fontMetrics().width(e->key()), lines.count() * fontMetrics().height() + 15);
}
