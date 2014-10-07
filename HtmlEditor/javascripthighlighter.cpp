#include "javascripthighlighter.h"
#include <QDebug>

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *document) :
    QSyntaxHighlighter(document)
{
    fillKeywords();

    HighlightingRule rule;
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);

    foreach (const QString &word, keywords)
    {
        rule.pattern = QRegExp(word);
        rule.format = keywordFormat;
    }

    if (keywords.count() < 2)
        qDebug() << "error.";

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::green);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::green);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void JavaScriptHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;

    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);
    while (startIndex >= 0)
    {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex
                    + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}


void JavaScriptHighlighter::fillKeywords()
{
    keywords << "\\bif\\b" << "\\bvar\\b" << "\\belse\\b" <<
               "\\bdo\\b" << "\\bwhile\\b" << "\\bswitch\\b" <<
               "\\bfor\\b" << "\\bbreak\\b" << "\\bcontinue\\b" <<
               "\\bconst\\b" << "\\btrue\\b" << "\\bfalse\\b" <<
               "\\bclass\\b" << "\\bfunction\\b" << "\\bdelete\\b" <<
               "\\bnew\\b" << "\\bimport\\b" << "\\breturn\\b" <<
               "\\bthis\\b" << "\\bthrow\\b" << "\\blet\\b" <<
               "\\btry\\b" << "\\bcatch\\b" << "\\bvoid\\b" <<
               "\\bwith\\b" << "\\byield\\b";
}
