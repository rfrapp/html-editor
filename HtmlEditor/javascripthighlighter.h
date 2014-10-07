#ifndef JAVASCRIPTHIGHLIGHTER_H
#define JAVASCRIPTHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class JavaScriptHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit JavaScriptHighlighter(QTextDocument *document = 0);

    enum Construct
    {
        Comment,
        LastConstruct = Comment
    };

signals:
    
protected:
    void highlightBlock(const QString &text);

    enum State {
        NormalState = -1,
        InComment
    };

    struct HighlightingRule
         {
             QRegExp pattern;
             QTextCharFormat format;
         };

    QVector<HighlightingRule> highlightingRules;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

public slots:

private:
    QStringList keywords;
    void fillKeywords();
};

#endif // JAVASCRIPTHIGHLIGHTER_H
