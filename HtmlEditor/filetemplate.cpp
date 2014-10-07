#include "file.h"
#include "filetemplate.h"

FileTemplate::FileTemplate(QString l, QString n, QString c, QString desc) : File(l, n, c)
{
    description = desc;
}

QString FileTemplate::getDescription()
{
    return description;
}
