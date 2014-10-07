#ifndef FILE_H
#define FILE_H
#include <QString>

class File
{
private:
      QString location;
      QString name;
      QString contents;
      int lineNumbers;

public:
      File(void);
      File(QString, QString, QString);
      QString getLocation();
      QString getName();
      QString getContents();
      void setContents(QString);
      void setLocation(QString);
      void setFileName(QString);
      int getLineNumbers();
};

#endif // FILE_H
