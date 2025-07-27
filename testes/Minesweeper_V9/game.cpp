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
        "   border: 2px solid #808080; /* A darker gray for the main border */"
        "   border-top-color: #D0D0D0; /* White for the top edge */"
        "   border-left-color: #D0D0D0; /* White for the left edge */"
        "   border-right-color: #808080; /* Darker gray for the right edge */"
        "   border-bottom-color: #808080; /* Darker gray for the bottom edge */"
        "   border-radius: 0px; /* Ensure sharp corners */"
        "}"
    );
    this->SIZE_LINE  = LINE_SIZEx;
    this->SIZE_COLUM = COLUM_SIZEx;
    this->SIZE_BOMBS = BOMB_SIZEx;

    //======================================================================================================================================
    // DIFFICULTY BUTTONS
    //_difficulty = new QPushButton[3];
    _Difficulty_UI = new QHBoxLayout;

    _difficulty = new QPushButton;
    _difficulty->setText("Begginer");
    _difficulty->setStyleSheet("color: #00B000;");
    _Difficulty_UI->addWidget(_difficulty);

    _difficulty = new QPushButton;
    _difficulty->setText("Medium");
    _difficulty->setStyleSheet("color: #0000FF;");
    _Difficulty_UI->addWidget(_difficulty);
    _difficulty = new QPushButton;

    _difficulty->setText("Advanced");
    _difficulty->setStyleSheet("color: #FF0000;");
    _Difficulty_UI->addWidget(_difficulty);

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
    _counter = new MineCounter(SIZE_BOMBS);

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

    _tile = new Tile[SIZE_LINE*SIZE_COLUM];

    for(int L = 0; L < SIZE_LINE; L++)
    {
        for(int C = 0; C < SIZE_COLUM; C++)
        {
            int i = L*SIZE_LINE + C;
            _tile[i].setFixedSize(30, 30);
            _tile[i].setTile();
            //connect(_tile[i], SIGNAL(clicked()), this, SLOT(openField()));
            _field->addWidget(&(_tile[i]), L, C);
        }
    }
    this->loadBombs();

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
    _Layout->addLayout(_Difficulty_UI);
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
// TIMER  "aparently no need for them"
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
void Game::loadBombs()
{
    int totalBombs = 0;
    srand(time(0));
    //for(int bomb = 0; bomb < SIZE_BOMBS; bomb++)
    while(totalBombs != SIZE_BOMBS)
    {
        int L = rand() % SIZE_LINE;
        int C = rand() % SIZE_COLUM;

        int i = L*SIZE_LINE + C;

        if(_tile[i].getBomb() == false)
        {
            _tile[i].setBomb();
            totalBombs++;
        }
    }
}
//======================================================================================================================================
void Game::resetGame()
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
    this->loadBombs();

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
// SIGNALS
void Game::mousePressEvent(QMouseEvent *event)
{
    // if(event->button() == Qt::RightButton)
    // {
    //     switch(state)
    //     {
    //     case Hidden: {QIcon Flag_icon(":images/Flag_icon.png"); setIcon(Flag_icon); this->state = Flagged; break;}
    //     case Flagged: setIcon(QIcon()); state = Hidden; break;
    //     case Revealed:
    //     case Exploded:   //qDebug() << "Exploded";
    //     default:
    //         break;
    //     }
    //     if(state != Exploded)
    //         emit rightClick(state);
    // }

    // if(event->button() == Qt::LeftButton)
    // {
    //     switch(this->state)
    //     {
    //     case Hidden:
    //         if(this->Bomb == false)
    //         {
    //             switch(this->adjacentMines)
    //             {
    //             case 0: {setIcon(QIcon()); break;}
    //             case 1: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/one_icon.png"  ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 2: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/two_icon.png"  ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 3: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/three_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 4: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/four_icon.png" ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 5: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/five_icon.png" ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 6: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/six_icon.png"  ), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 7: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/seven_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             case 8: {QIcon Number_icon; Number_icon.addPixmap(QPixmap(":images/eight_icon.png"), QIcon::Disabled, QIcon::Off); setIcon(Number_icon); break;}
    //             default:
    //                 break;
    //             }
    //             this->setEnabled(false);
    //             //this->setCheckable(false);
    //             this->state = Revealed;
    //             // call open field algorithm
    //         }
    //         else
    //         {
    //             QIcon Bomb_icon;
    //             Bomb_icon.addPixmap(QPixmap(":images/bomb_icon.png"), QIcon::Disabled, QIcon::Off);
    //             setIcon(Bomb_icon);
    //             this->state = Exploded;
    //             this->setEnabled(false);
    //             this->setStyleSheet(
    //                 "QPushButton:disabled {"
    //                 "   background-color: #DDB0B0; /* Slightly darker when pressed */"
    //                 "   border: 1px solid #808080; /* Invert the 3D effect when pressed */"
    //                 "   border-top-color: #808080;"
    //                 "   border-left-color: #808080;"
    //                 "   border-right-color: #808080;"
    //                 "   border-bottom-color: #808080;"
    //                 "   color: #FF0000; /* Default text color */"
    //                 "}"
    //                 );
    //             // call end game function
    //         }
    //         break;
    //     case Flagged:
    //     case Revealed:
    //     case Exploded:
    //     default:
    //         break;
    //     }
    // }
    // QPushButton::mousePressEvent(event);
}



