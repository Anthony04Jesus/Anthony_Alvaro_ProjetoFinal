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
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //Disable window resizing during runtime

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
    _Difficulty_UI->addWidget(_difficulty);
    _difficulty = new QPushButton;

    _difficulty->setText("Advanced");
    _difficulty->setStyleSheet("color: #FF0000;");
    _Difficulty_UI->addWidget(_difficulty);

    //======================================================================================================================================
    // SETTING LAYOUT
    _field = new Field(10,10,10);
    _field->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 2px solid #808080; /* Darker gray border */"
        "   border-top-color: #FFFFFF; /* Lighter top border for 3D effect */"
        "   border-left-color: #FFFFFF; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #000000; /* Default text color */"
        "}"
        "QPushButton:pressed {"
        "   background-color: #C0C0C0; /* Slightly darker when pressed */"
        "   border: 1px solid #808080; /* Invert the 3D effect when pressed */"
        "   border-top-color: #808080;"
        "   border-left-color: #808080;"
        "   border-right-color: #FFFFFF;"
        "   border-bottom-color: #FFFFFF;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E0E0E0; /* Slightly lighter on hover */"
        "}"
        );

    _Field_layout = new QGridLayout();
    _Field_layout->addWidget(_field);

    _Layout = new QVBoxLayout();
    _Layout->addLayout(_Difficulty_UI);
    _Layout->addLayout(_UI_layout);
    _Layout->addLayout(_Field_layout);
    setLayout(_Layout);
}

//void Game::keyPressEvent(QKeyEvent *event)
//{
//    // int k = event->key();
//    // if(k == Qt::Key_Space)
//    //     _restart->animateClick(100);

//    //this->resetGame();
//}

//======================================================================================================================================
// SIGNALS
void Game::mousePressEvent(QMouseEvent *event)
{

}




