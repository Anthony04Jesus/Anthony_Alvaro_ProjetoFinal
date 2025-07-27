#include "game.h"
#include "aboutwindow.h"

const QString Game::pushButtonStyle =
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
    "QPushButton:pressed {"
    "   background-color: #B3B3B4; /* Slightly darker when pressed */"
    "   border: 5px solid #808080; /* Invert the 3D effect when pressed */"
    "   border-top-color: #808080;"
    "   border-left-color: #808080;"
    "   border-right-color: #A0A0A0;"
    "   border-bottom-color: #A0A0A0;"
    "}"
    "QPushButton:hover {"
    "   background-color: #C0D7FF; /* Slightly lighter on hover */"
    "}"
    ;

const QString Game::pushFieldStyle =
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
    "}";

Game::Game(QWidget *parent): QWidget{parent}
{
    //======================================================================================================================================
    // WINDOW
    setWindowTitle("Minesweeper");
    this->setStyleSheet(
        "QWidget {"
        "   background-color: #C0C0C0; /* Standard gray background */"
        "   border: 2px solid #808080; /* A darker gray for the main border */"
        "   border-top-color: #D0D0D0; /* White for the top edge */"
        "   border-left-color: #D0D0D0; /* White for the left edge */""   border-right-color: #808080; /* Darker gray for the right edge */"
        "   border-bottom-color: #808080; /* Darker gray for the bottom edge */"
        "   border-radius: 0px; /* Ensure sharp corners */"
            "}"
        );
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //======================================================================================================================================
    // DIFFICULTY BUTTONS
    _Difficulty_UI = new QHBoxLayout;

    _begginer = new QPushButton;
    _begginer->setText("Begginer");
    _begginer->setStyleSheet(pushButtonStyle + "QPushButton {color: #0000A0;}");
    connect(_begginer, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 10;
        const int SIZE_COLUMx = 10;
        const int SIZE_BOMBSx = 10;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });

    _medium = new QPushButton;
    _medium->setText("Medium");
    _medium->setStyleSheet(pushButtonStyle + "QPushButton {color: #008800;}");
    connect(_medium, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 15;
        const int SIZE_COLUMx = 15;
        const int SIZE_BOMBSx = 35;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });
    _advanced = new QPushButton;
    _advanced->setText("Advanced");
    _advanced->setStyleSheet(pushButtonStyle + "QPushButton {color: #D00000;}");

    connect(_advanced, &QPushButton::clicked, this, [this]() {
        const int SIZE_LINEx  = 20;
        const int SIZE_COLUMx = 20;
        const int SIZE_BOMBSx = 90;
        this->LoadGame(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    });

    _Difficulty_UI->addWidget(_begginer);
    _Difficulty_UI->addWidget(_medium);
    _Difficulty_UI->addWidget(_advanced);

    //======================================================================================================================================
    // SETTING LAYOUT

    this->SIZE_LINE  = 10;
    this->SIZE_COLUM = 10;
    this->SIZE_BOMBS = 10;

    _field = new Field(SIZE_LINE, SIZE_COLUM, SIZE_BOMBS);
    _field->setStyleSheet(pushFieldStyle);

    _Field_layout = new QGridLayout();
    _Field_layout->addWidget(_field);

    _sobre = new QPushButton;
    _sobre->setText("About");
    _sobre->setStyleSheet(pushButtonStyle + "QPushButton {color:#000000};");

    connect(_sobre, SIGNAL(clicked()), this, SLOT(About()));

    _About = new QHBoxLayout();
    _About->addWidget(_sobre);

    _Layout = new QVBoxLayout();
    _Layout->addLayout(_Difficulty_UI);
    _Layout->addLayout(_Field_layout);
    _Layout->addLayout(_About);
    setLayout(_Layout);
}
//======================================================================================================================================

void Game::LoadGame(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx)
{
    this->_field->reloadField(SIZE_LINEx, SIZE_COLUMx, SIZE_BOMBSx);
    this->adjustSize();
}

void Game::About()
{
    AboutWindow *caixa = new AboutWindow();
    caixa->exec();
    delete caixa;
}
