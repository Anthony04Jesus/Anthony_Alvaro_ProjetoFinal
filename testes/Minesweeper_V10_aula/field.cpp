#include "field.h"
#include "tile.h"
#include <QDebug>
#include <QKeyEvent>

Field::Field( int SIZE_LINE, int SIZE_COLUM, int SIZE_BOMBS, QWidget *parent): QWidget{parent}
{
    this->SIZE_LINE  = SIZE_LINE ;
    this->SIZE_COLUM = SIZE_COLUM;
    this->SIZE_BOMBS = SIZE_BOMBS;

    //======================================================================================================================================
    // TILE
    _field = new QGridLayout();
    _field->setHorizontalSpacing(0);
    _field->setVerticalSpacing(0);

    _tile = new Tile[SIZE_LINE*SIZE_COLUM];

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].setFixedSize(30, 30);
            _tile[i].setTile();
            //connect(&_tile[i], SIGNAL(noBombsAround()), this, SLOT(openAdjacentFields()));
            //connect(&_tile[i], SIGNAL(exploded()), this, SIGNAL(exploded()));
            //connect(_tile[i], SIGNAL(rightClick(bool)), this, SLOT(updateBombs(bool)));
            _field->addWidget(&(_tile[i]), L, C);
        }
    }
    this->loadBombs(0,0); //Goes on openField()

    //======================================================================================================================================
    // RESTART BUTTON
    QIcon Smiley_Face(":images/smiley_face.png");
    _restart = new QPushButton();
    _restart->setFixedSize(40, 40);
    _restart->setIcon(Smiley_Face);
    _restart->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 5px solid #808080; /* Darker gray border */"
        "   border-top-color: #EEEEEE; /* Lighter top border for 3D effect */"
        "   border-left-color: #EEEEEE; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #000000; /* Default text color */"
        "}"
        "QPushButton:pressed {"
        "   background-color: #B3B3B3; /* Slightly darker when pressed */"
        "   border: 5px solid #808080; /* Invert the 3D effect when pressed */"
        "   border-top-color: #808080;"
        "   border-left-color: #808080;"
        "   border-right-color: #A0A0A0;"
        "   border-bottom-color: #A0A0A0;"
        "}"
        "QPushButton:hover {"
        "   background-color: #C0D7FF; /* Slightly lighter on hover */"
        "}"
        );
    connect(_restart, SIGNAL(clicked()), this, SLOT(resetField()));

    //======================================================================================================================================
    // LABEL BOMB COUNTER
    _counter = new QLCDNumber();
    _counter->setSegmentStyle(QLCDNumber::Flat);
    _counter->setDigitCount(4);
    _counter->display(SIZE_BOMBS);
    _counter->setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;"
        "   border-radius: 5px;"
        "}"
        );

    //======================================================================================================================================
    // LABEL TIME COUNTER
    _timer = new QLCDNumber();
    _timer->setSegmentStyle(QLCDNumber::Flat);
    _timer->setDigitCount(4);
    _timer->display(0);
    timer = new QTimer(this);
    timer->start(1000);
    _timer->setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;"
        "   border-radius: 5px;"
        "}"
        );
    this->_time_count = 0;
    connect(timer, &QTimer::timeout, this, &Field::updateTime);

    //======================================================================================================================================
    // LABEL TIME COUNTER
    _UI_layout = new QHBoxLayout();
    _UI_layout->addWidget(_counter);
    _UI_layout->addStretch(1000);
    _UI_layout->addWidget(_restart);
    _UI_layout->addStretch(1000);
    _UI_layout->addWidget(_timer);

    _layout = new QVBoxLayout();
    _layout->addLayout(_UI_layout);
    _layout->addLayout(_field);
    setLayout(_layout);
}
//==========================================================================================================================================
//void Field::openField()
//{
//    qDebug() << "fafa";
//}


void Field::loadBombs( int line , int colum)
{
    int totalBombs = 0;
    srand(time(0));
    while(totalBombs != SIZE_BOMBS)
    {
        int L = rand() % SIZE_LINE;
        int C = rand() % SIZE_COLUM;

        int i = L*SIZE_LINE + C;

        if(_tile[i].getBomb() == false and L != line and C != colum)
        {
            _tile[i].setBomb();
            totalBombs++;
        }
    }
}

//======================================================================================================================================
void Field::resetField()
{
    this->_time_count = 0;
    this->_bomb_count = SIZE_BOMBS;

    _timer->display(_time_count);
    _counter->display(_bomb_count);

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].setTile();
        }
    }
    this->loadBombs(0 , 0);

    // for(int L = 0; L < SIZE_LINE; L++)
    // {
    //     for(int C = 0; C < SIZE_COLUM; C++)
    //     {
    //         int i = L*SIZE_LINE + C;
    //         if(_tile[i].getBomb() == true)
    //             _tile[i].plotBombs();
    //     }
    // }
}


//======================================================================================================================================
// TIMER  "aparently no need for them"
int Field::GetTime()     { return this->_time_count++; }
void Field::updateTime(void) { _timer->display(GetTime()); }

//======================================================================================================================================
// COUNTER
void Field::updateBombs( bool state )
{
    if( state == true)
        this->_bomb_count++;
    else
        this->_bomb_count--;

    _counter->display(_bomb_count);
}
int Field::GetBombs() { return this->_bomb_count; }


//void Field::updateBombs(bool state)
//{
//    //    if(state){
//    //        _counter->dec();
//    //    } else {
//    //        _counter->inc();
//    //    }
//}
