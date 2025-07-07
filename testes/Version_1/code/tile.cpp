#include "tile.h"

Tile::Tile(QWidget * parent): QPushButton(parent)
{
    this->bomb = false;
    this->state = Unopened;
}
