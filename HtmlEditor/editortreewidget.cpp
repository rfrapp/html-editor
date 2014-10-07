#include "editortreewidget.h"

EditorTreeWidget::EditorTreeWidget(QObject *parent) :
    QTreeWidget(parent)
{
    this->setColumnCount(2);
}

