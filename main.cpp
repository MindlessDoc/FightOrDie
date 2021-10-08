#include "mainwindow.h"

#include <QApplication>
#include "graphicfield.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicField field(50, 50, 5, 5);
    return a.exec();
}
