#ifndef HTMLSYNTAXHIGHLIGHTER_H
#define HTMLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
class CodeEditor;

class HtmlSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:

    enum Construct
    {
        Entity,
        Tag,
        Attribute,
        Value,
        Comment,
        LastConstruct = Comment
    };

    HtmlSyntaxHighlighter(CodeEditor *parent, QTextDocument *document);

    void setFormatFor(Construct construct, const QTextCharFormat &format);

    QTextCharFormat formatFor(Construct construct) const
    {
        return m_formats[construct];
    }

protected:

    enum State {
        NormalState = -1,
        InComment,
        InTag
    };

    void highlightBlock(const QString &text);

private:
    CodeEditor *parentEditor;
    QTextDocument *doc;
    QTextCharFormat m_formats[LastConstruct + 1];
    
};

#endif // HTMLSYNTAXHIGHLIGHTER_H
