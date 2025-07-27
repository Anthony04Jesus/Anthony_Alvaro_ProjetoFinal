#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game Minesweeper;
    Minesweeper.show();
    return a.exec();
}
