/*
 * Name: Ryan Frappier
 * Date: May 3, 2013
 * Program: An HTML Editor
 *
 * I hereby certify that this program represents my
 * work and that the design.
 *
 * Signature:______________
 */

#include "editor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Editor editorWindow;

    editorWindow.show();
    
    return app.exec();
}
