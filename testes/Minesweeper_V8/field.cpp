#include "field.h"
#include "tile.h"
#include <QDebug>
#include <QKeyEvent>

Field::Field( int lineSize, int columSize, int bombNumber, MineCounter * cnt, QWidget *parent): QWidget{parent}
{
    _counter = cnt;
    _layout = new QGridLayout();
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);


    this->SIZE_LINE = lineSize;
    this->SIZE_COLUM = columSize;
    this->SIZE_BOMBS = bombNumber;

    //_tile = new Tile[SIZE_LINE*SIZE_COLUM](true);
    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            _tile = new  Tile();
            _tile->setFixedSize(30, 30);
            connect(_tile, SIGNAL(leftClicked()), this, SLOT(openField()));
            connect(_tile, SIGNAL(rightClick(bool)), this, SLOT(updateCounter(bool)));
            _layout->addWidget(_tile, L, C);
        }
    }
    setLayout(_layout);
}

void Field::resetField()
{
    for(int i = 0; i < 10; i++)
    {
       //_tile[i].setTile();
        //qDebug() << i;
    }
    _tile[0].setTile();
    _counter->resetBombs();
}
void Field::openField()
{
    // if(this->_tile[0].getState() == Bomb_Hidden )
    // {
    //     QIcon Bomb_icon(":images/bomb_icon.png");
    //     this->_tile[0].setIcon(Bomb_icon);
    // }
}

void Field::updateCounter(bool state)
{
    if(state){
        _counter->dec();
    } else {
        _counter->inc();
    }
}

void Field::loadBombs(int Line, int Colum)
{

}


// "QPushButton:pressed {"
//     "   background-color: #B0B0B0; /* Slightly darker when pressed */"
//     "   border: 1px solid #808080; /* Invert the 3D effect when pressed */"
//     "   border-top-color: #808080;"
//     "   border-left-color: #808080;"
//     "   border-right-color: #808080;"
//     "   border-bottom-color: #808080;"
//     "   color: #FF0000; /* Default text color */"
//     "}"
