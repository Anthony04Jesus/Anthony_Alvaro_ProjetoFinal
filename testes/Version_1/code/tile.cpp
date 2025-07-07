#include "tile.h"




//Tiles(const QString &text , QWidget *parent = nullptr);

Tile::Tile(QWidget * parent): QPushButton(parent)
{
    this->bomb = false;
    this->state = Unopened;
}

// void Tile::addAdjacente(Tile *t)
// {
//     adjacentes.push_back(t);
// }


// void Tile::keyPressEvent(QKeyEvent *event)
// {
//     int k = event->key();
//     //if(k == Qt::Key_Space)
//     //_restart->animateClick(100);
// }
// void Tile::keyPressed()
// {

// }
