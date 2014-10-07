#include "error.h"

Error::Error(QString type, QString description, int line)
{
    _type = type;
    _description = description;
    _lineNumber = line;
}

QString Error::getType()
{
    return _type;
}

QString Error::getDescription()
{
    return _description;
}

int Error::getLineNumber()
{
    return _lineNumber;
}
