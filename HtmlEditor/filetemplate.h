#ifndef FILETEMPLATE_H
#define FILETEMPLATE_H

#include "file.h"
#include <QString>

class FileTemplate : public File
{
private:
    QString description;
public:
    FileTemplate(QString, QString, QString, QString desc);
    QString getDescription();
};

#endif // FILETEMPLATE_H
