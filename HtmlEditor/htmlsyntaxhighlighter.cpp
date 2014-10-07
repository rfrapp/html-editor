#include "htmlsyntaxhighlighter.h"
#include "codeeditor.h"
#include <QMessageBox>
#include <QDebug>

HtmlSyntaxHighlighter::HtmlSyntaxHighlighter(CodeEditor *parent, QTextDocument *document) : QSyntaxHighlighter(document)
{
    parentEditor = parent;
    doc = document;

    QTextCharFormat entityFormat;
    entityFormat.setForeground(Qt::red);
    entityFormat.setFontWeight(QFont::Bold);
    setFormatFor(Entity, entityFormat);

    QTextCharFormat tagFormat;
    tagFormat.setForeground(QColor("#002bcc"));
    tagFormat.setFontWeight(QFont::Bold);
    setFormatFor(Tag, tagFormat);

    QTextCharFormat commentFormat;
    commentFormat.setForeground(QColor(Qt::green).darker(200));
    commentFormat.setFontItalic(true);
    setFormatFor(Comment, commentFormat);

    QTextCharFormat attributeFormat;
    attributeFormat.setForeground(Qt::red);
    setFormatFor(Attribute, attributeFormat);

    QTextCharFormat valueFormat;
    valueFormat.setForeground(QColor(Qt::green).darker());
    valueFormat.setFontItalic(true);
    setFormatFor(Value, valueFormat);
}

void HtmlSyntaxHighlighter::setFormatFor(Construct construct, const QTextCharFormat &format)
{
    m_formats[construct] = format;
    rehighlight();
}

void HtmlSyntaxHighlighter::highlightBlock(const QString &text)
{
    // where the cursur is in the page
    int state = previousBlockState();

    // the length of the text in the textbox
    int len = text.length();

    // the point to start highlighting at
    int start = 0;

    // iterator for looping through the text
    int pos = 0;

    // counter for quotes
    int quoteCount = 0;

    // loop through all of the text
    while (pos < len)
    {
        switch (state)
        {
        case NormalState:
        default:
            while (pos < len)
            {
                QChar ch = text.at(pos);
                if (ch == '<')
                {
                    if (text.mid(pos, 4) == "<!--")
                    {
                        state = InComment;
                    }
//                    else if (text.mid(pos, 7) == "<style>")
//                    {
//                        //parentEditor->setHighlighter(new CssSyntaxHighlighter(parentEditor, doc));
//                    }
                    else
                    {
                        state = InTag;
                    }
                    break;
                }
                else if (ch == '&')
                {
                    start = pos;
                    while (pos < len && text.at(pos++) != ';')
                        setFormat(start, pos - start, m_formats[Entity]);
                }
                else
                {
                    ++pos;
                }
            }
            break;
        case InComment:
            start = pos;
            while (pos < len)
            {
                if (text.mid(pos, 3) == "-->")
                {
                    pos += 3;
                    state = NormalState;
                    break;
                }
                else
                {
                    ++pos;
                }
            }
            setFormat(start, pos - start, m_formats[Comment]);
            break;
        case Value:
            quoteCount = 0;
            start = pos;
            while (pos < len)
            {
                QChar ch = text.at(pos);

                if (ch == '"')
                {
                    quoteCount++;
                    if (quoteCount == 2)
                    {
                        ++pos;
                        state = InTag;
                        break;
                    }
                    ++pos;
                }
                else
                    ++pos;
            }
            setFormat(start, pos - start, m_formats[Value]);
            break;
        case Attribute:
            start = pos;
            while (pos < len)
            {
                QChar ch = text.at(pos);

                if (ch == '=')
                {
                    ++pos;
                    state = Value;
                    break;
                }
                else if (ch == 'h' && text.mid(pos, 4) == "html")
                {
                    state = InTag;
                    break;
                }
                else if (ch == '>')
                {
                    ++pos;
                    state = NormalState;
                    break;
                }
                else if (ch == '/')
                {
                    state = InTag;
                    break;
                }
                else
                    ++pos;
            }
            setFormat(start, pos - start, m_formats[Attribute]);
            break;
        case InTag:
            QChar quote = QChar::Null;
            start = pos;
            while (pos < len)
            {
                QChar ch = text.at(pos);
                if (quote.isNull())
                {
                    if (ch == '\"' || ch == '"')
                    {
                        quote = ch;
                    }
                    else if (ch == '>')
                    {
                        ++pos;
                        state = NormalState;
                        break;
                    }
                    if (ch == ' ')
                    {
                        state = Attribute;
                        break;
                    }
                }
                else if (ch == quote)
                {
                    quote = QChar::Null;
                }
                ++pos;
            }
            setFormat(start, pos - start, m_formats[Tag]);
            break;
        } // end switch

        setCurrentBlockState(state);
    } // end while
}
