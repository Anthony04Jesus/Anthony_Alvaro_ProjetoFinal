#ifndef TILES_H
#define TILES_H

#include <QWidget>
#include <QPushButton>

enum Tile_State
{
    Unopened,
    Opened,
    Bomb,
    Flag
};

class Tiles
{
public:
    Tiles();
private:
    bool bomb;
    Tile_State state;
    QPushButton * _tile;
};

#endif // TILES_H
