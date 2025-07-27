#include "tile.h"

#include <QDebug>
#include <QMouseEvent>


//Tiles(const QString &text , QWidget *parent = nullptr);

Tile::Tile(QWidget * parent): QPushButton(parent)
{
    this->bomb = false;
    this->state = Unopened;
    this->flagged = false;
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        qDebug() << "Right button clicked!";
        flagged = !flagged;
        if(flagged){
            setText("F");
        } else {
            setText("");
        }
        emit rightClick(flagged);
    }
    QPushButton::mousePressEvent(event);
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
