#include "prva.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Prva w;
    w.show();

    return a.exec();
}
