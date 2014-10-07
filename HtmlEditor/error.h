#ifndef ERROR_H
#define ERROR_H

#include <QString>

class Error
{
public:
    Error(QString type, QString description, int line);
    QString getType();
    QString getDescription();
    int getLineNumber();

private:
    QString _type;
    QString _description;
    int _lineNumber;
};

#endif // ERROR_H
