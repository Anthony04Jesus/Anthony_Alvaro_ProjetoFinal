#include "game.h"
#include <QDebug>
#include <QKeyEvent>
#include "minecounter.h"
#include "tile.h"

Game::Game(int LINE_SIZEx, int COLUM_SIZEx, int BOMB_SIZEx, QWidget *parent): QWidget{parent}
{
    //======================================================================================================================================
    // WINDOW
    setWindowTitle("Minesweeper");
    this->setStyleSheet(
        "QWidget {" // Apply to QMainWindow or QWidget if it's your top-level widget
        "   background-color: #C0C0C0; /* Standard gray background */"
        "   border: 5px solid #808080; /* A darker gray for the main border */"
        "   border-top-color: #FFFFFF; /* White for the top edge */"
        "   border-left-color: #FFFFFF; /* White for the left edge */"
        "   border-right-color: #808080; /* Darker gray for the right edge */"
        "   border-bottom-color: #808080; /* Darker gray for the bottom edge */"
        "   border-radius: 0px; /* Ensure sharp corners */"
        "}"
    );

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
    connect(_restart, SIGNAL(clicked()), this, SLOT(resetGame()));
    //======================================================================================================================================
    // LABEL BOMB COUNTER
    _counter = new MineCounter(10);

    // _counter = new QLCDNumber();
    // _counter->setSegmentStyle(QLCDNumber::Flat);
    // _counter->setDigitCount(4);
    // _counter->display(BOMB_SIZE);

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
    connect(timer, &QTimer::timeout, this, &Game::updateTime);

    //======================================================================================================================================
    // TILE
    _field = new QGridLayout();
    _field->setHorizontalSpacing(0);
    _field->setVerticalSpacing(0);

    this->SIZE_LINE  = LINE_SIZEx;
    this->SIZE_COLUM = COLUM_SIZEx;
    this->SIZE_BOMBS = BOMB_SIZEx;


    // for(int L = 0; L < SIZE_LINE; L++)
    // {
    //     for(int C = 0; C < SIZE_COLUM; C++)
    //     {
    //         _tile = new Tile();
    //         _tile->setFixedSize(30, 30);
    //         _field->addWidget(_tile, L, C);
    //     }
    // }

    // _tile = new Tile*[SIZE_LINE];


    // connect(_field, SIGNAL(keyStroke(char)), this, SLOT(keyInput(char)));

    //_tile = new Tile[SIZE_LINE*SIZE_COLUM];

    // for(int L = 0; L < SIZE_LINE; L++)
    // {
    //     for(int C = 0; C < SIZE_COLUM; C++)
    //     {
    //         _tile->setFixedSize(30, 30);
    //         _field->addWidget(_tile, L, C);
    //     }
    // }

    _tile = new Tile[SIZE_LINE*SIZE_COLUM];


    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].setFixedSize(30, 30);
            _tile[i].setTile();
            _field->addWidget(&(_tile[i]), L, C);
        }
    }
    //======================================================================================================================================
    // SETTING LAYOUT
    _UI_layout = new QHBoxLayout();
    _UI_layout->addStretch(3000);
    _UI_layout->addWidget(_counter);
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_restart); //,0,Qt::AlignTop
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_timer);


    _Layout = new QVBoxLayout();
    _Layout->addLayout(_UI_layout);
    _Layout->addLayout(_field);
    setLayout(_Layout);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    // int k = event->key();
    // if(k == Qt::Key_Space)
    //     _restart->animateClick(100);

    this->resetGame();
}

//======================================================================================================================================
// TIMER
int Game::GetTime()     { return this->_time_count++; }
void Game::updateTime() { _timer->display(GetTime()); }
//======================================================================================================================================
// COUNTER
void Game::updateBombs( bool operation )
{
    if( operation == true)
        this->_bomb_count++;
    else
        this->_bomb_count--;

    _counter->display(_bomb_count);
}
int Game::GetBombs() { return this->_bomb_count; }

//======================================================================================================================================
void Game::resetGame()
{
    this->_time_count = 0;
    this->updateTime();

    //this->_counter->dec();
    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].setTile();
        }
    }
}

