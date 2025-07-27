#include "field.h"
#include <QDebug>
#include <QKeyEvent>

Field::Field(QWidget *parent): QWidget{parent}
{
    _layout = new QGridLayout();
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);
    setStyleSheet("font-size: 32px;");

    int line = 10;
    int colum = 10;
    for(int L = 0; L < line; L++)
    {
        for(int C = 0; C < colum; C++)
        {
            _field[L][C] = new QPushButton(" "); //QString::number(L)
            _field[L][C]->setStyleSheet("background: yellow");
            _field[L][C]->setMaximumSize(30,30);
            _field[L][C]->setMinimumSize(30,30);
            connect(_field[L][C], SIGNAL(clicked()), this, SLOT(keyPressed()));
            _layout->addWidget(_field[L][C], L, C);
        }
    }
    setLayout(_layout);
}
