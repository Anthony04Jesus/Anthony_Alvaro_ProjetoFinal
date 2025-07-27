#include "field.h"
#include "tile.h"
#include <QDebug>
#include <QKeyEvent>

Field::Field(QWidget *parent): QWidget{parent}
{
    _layout = new QGridLayout();
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);
    setStyleSheet("font-size: 32px;");

    int line = 10;
    int col = 10;
    Tile * tmp;
    for(int L = 0; L < line; L++)
    {
        for(int C = 0; C < col; C++)
        {
            tmp = new Tile;
            tmp->setStyleSheet("background: gray");
            tmp->setMaximumSize(30,30);
            tmp->setMinimumSize(30,30);
            //connect(tmp, SIGNAL(clicked()), this, SLOT(keyPressed()));
            _layout->addWidget(tmp, L, C);
        }
    }


    for(int L = 0; L < 10; L++) {
        for(int C = 0; C < 10; C++) {


        }
    }



    setLayout(_layout);


}

void Field::keyPressed()
{

}
