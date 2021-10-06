#include "mainwindow.h"

#include <QApplication>
#include"field.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field field(5, 7);
    return a.exec();
}
