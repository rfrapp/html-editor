#include "file.h"
#include <string>
#include <iostream>

using namespace std;

File::File(void)
{

}

File::File(QString l, QString n, QString c)
{
    location = l;
    name = n;
    contents = c;
}

QString File::getName()
{
    return name;
}

QString File::getLocation()
{
    return location;
}

int File::getLineNumbers()
{
    return lineNumbers;
}

QString File::getContents()
{
    return contents;
}

void File::setContents(QString str)
{
    contents = str;
}

void File::setLocation(QString str)
{
    location = str;
}

void File::setFileName(QString str)
{
    name = str;
}
