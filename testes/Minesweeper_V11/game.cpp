#include "game.h"
#include <QDebug>
#include <QKeyEvent>

Game::Game(QWidget *parent): QWidget{parent}
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
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //Disable window resizing during runtime

    //======================================================================================================================================
    // DIFFICULTY BUTTONS
    //_difficulty = new QPushButton[3];
    _Difficulty_UI = new QHBoxLayout;

    _begginer = new QPushButton;
    _begginer->setText("Begginer");
    _begginer->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 5px solid #808080; /* Darker gray border */"
        "   border-top-color: #EEEEEE; /* Lighter top border for 3D effect */"
        "   border-left-color: #EEEEEE; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #0000A0; /* Default text color */"
        "}"
        );
    //connect(_begginer, SIGNAL(clicked()), this, SLOT(LoadGame()));
    connect(_begginer, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 10;
        const int SIZE_COLUMx = 10;
        const int SIZE_BOMBSx = 10;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });

    _medium = new QPushButton;
    _medium->setText("Medium");
    _medium->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 5px solid #808080; /* Darker gray border */"
        "   border-top-color: #EEEEEE; /* Lighter top border for 3D effect */"
        "   border-left-color: #EEEEEE; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #008800; /* Default text color */"
        "}"
        );
    //connect(_medium, SIGNAL(clicked()), this, SLOT(LoadGame()));
    connect(_medium, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 15;
        const int SIZE_COLUMx = 15;
        const int SIZE_BOMBSx = 25;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });

    _advanced = new QPushButton;
    _advanced->setText("Advanced");
    _advanced->setEnabled(true);
    _advanced->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 5px solid #808080; /* Darker gray border */"
        "   border-top-color: #EEEEEE; /* Lighter top border for 3D effect */"
        "   border-left-color: #EEEEEE; /* Lighter left border for 3D effect */"
        "   border-right-color: #808080; /* Darker right border */"
        "   border-bottom-color: #808080; /* Darker bottom border */"
        "   border-radius: 0px; /* Ensure no rounded corners */"
        "   font: bold 12pt 'Segoe UI', 'Arial'; /* Example font */"
        "   color: #D00000; /* Default text color */"
        "}"
        );
    //connect(_advanced, SIGNAL(clicked()), this, SLOT(LoadGame()));
    connect(_advanced, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 20;
        const int SIZE_COLUMx = 20;
        const int SIZE_BOMBSx = 70;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });

    _Difficulty_UI->addWidget(_begginer);
    _Difficulty_UI->addWidget(_medium);
    _Difficulty_UI->addWidget(_advanced);

    //======================================================================================================================================
    // SETTING LAYOUT

    int LINE_SIZEx = 10;
    int COLUM_SIZEx = 10;
    int BOMB_SIZEx = 10;

    this->SIZE_LINE  = LINE_SIZEx;
    this->SIZE_COLUM = COLUM_SIZEx;
    this->SIZE_BOMBS = BOMB_SIZEx;

    _field = new Field(LINE_SIZEx, COLUM_SIZEx, SIZE_BOMBS);
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


void Game::LoadGame(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx)
{
    // qDebug() << "--- Game::LoadGame Called ---";
    // qDebug() << "Game current size:" << size(); // Before reload
    // qDebug() << "Field widget current size:" << _field->size(); // Before reload

    this->_field->reloadField(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);

    // qDebug() << "Field widget size after reloadField:" << _field->size(); // After reloadField
    // qDebug() << "Field widget sizeHint after reloadField:" << _field->sizeHint(); // After reloadField

    this->adjustSize();
    // qDebug() << "Game size after adjustSize():" << size();

    // QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    // qDebug() << "Game size after processEvents():" << size();

    // // this->update();
    // // this->repaint();
    // // this->updateGeometry();

    // if (parentWidget()) {
    //     qDebug() << "Parent widget size:" << parentWidget()->size();
    //     parentWidget()->adjustSize();
    //     qDebug() << "Parent widget size after adjustSize():" << parentWidget()->size();
    //     parentWidget()->updateGeometry(); // Inform the grand-parent
    // }
}



