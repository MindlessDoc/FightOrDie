#include "mainwindow.h"

#include <QApplication>
#include "graphicfield.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field field(70, 70, 5, 5);
    Field field_2 = field;
    return a.exec();
}
