#include "mainwindow.h"
#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w(10,10,40);
    w.show();
    return a.exec();
}
