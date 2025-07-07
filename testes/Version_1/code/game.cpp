#include "game.h"
#include <QDebug>
#include <QKeyEvent>

Game::Game(QWidget *parent): QWidget{parent}
{
    this->setStyleSheet(
        "QWidget {" // Apply to QMainWindow or QWidget if it's your top-level widget
        "   background-color: #C0C0C0; /* Standard gray background */"
        "   border: 2px solid #808080; /* A darker gray for the main border */"
        "   border-top-color: #FFFFFF; /* White for the top edge */"
        "   border-left-color: #FFFFFF; /* White for the left edge */"
        "   border-right-color: #808080; /* Darker gray for the right edge */"
        "   border-bottom-color: #808080; /* Darker gray for the bottom edge */"
        "   border-radius: 0px; /* Ensure sharp corners */"
        "}"
    );

    setWindowTitle("Minesweeper");
    QPixmap smileyFace("C:/Users/albre/Desktop/Minesweeper_V4/icons/smiley_face.png"); // Load the image
    QIcon icon(smileyFace); // Create a QIcon from the QPixmap

    // RESTART BUTTON
    _restart = new QPushButton(); //QString::number(L)
    _restart->setMaximumSize(80,80);
    _restart->setMinimumSize(40,40);
    _restart->setIcon(icon);
    _restart->setStyleSheet(
        "QPushButton {"
        "   background-color: #D3D3D3; /* Light gray */"
        "   border: 5px solid #808080; /* Darker gray border */"
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
    connect(_restart, SIGNAL(clicked()), this, SLOT(keyPressed()));

    // LABEL BOMB COUNTER
    _counter = new QLCDNumber(); //_counter->setGeometry(0,0,100,100);
    _counter->setSegmentStyle(QLCDNumber::Flat);
    _counter->setDigitCount(4);
    _counter->display(999);
    _counter->setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;" // Optional border
        "   border-radius: 5px;"
        "}"
        );

    // LABEL TIME COUNTER
    _timer = new QLCDNumber();
    _timer->setSegmentStyle(QLCDNumber::Flat);
    _timer->setDigitCount(4);
    _timer->display(999);
    _timer->setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;" // Optional border
        "   border-radius: 5px;"
        "}"
    );

    // FIELD OF BUTTONS
    _field = new Field();
    connect(_field, SIGNAL(keyStroke(char)), this, SLOT(keyInput(char)));
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

    // SETTING LAYOUT
    // QWidget* topBarContainer = new QWidget(this);
    // _UI_layout = new QHBoxLayout(topBarContainer);
    _UI_layout = new QHBoxLayout();
    _UI_layout->addStretch(3000);
    _UI_layout->addWidget(_counter);
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_restart,0,Qt::AlignTop);
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_timer);
    _UI_layout->addStretch(3000);
    // topBarContainer->setMinimumSize(300, 400);
    // topBarContainer->setStyleSheet(
    //     "QWidget {"
    //     "   background-color: #A0A0A0;"
    //     "   border: 2px outset #C0C0C0;" // Raised border
    //     "   border-radius: 0px;"
    //     "   padding: 5px;"
    //     "}"
    // );

    //QFrame* gameBoardContainer = new QFrame(this);
    _Field_layout = new QGridLayout();
    _Field_layout->addWidget(_field);

    _Layout = new QVBoxLayout();
    _Layout->addLayout(_UI_layout);
    _Layout->addLayout(_Field_layout);
    setLayout(_Layout);

}

void Game::keyPressEvent(QKeyEvent *event)
{
    int k = event->key();
    //if(k == Qt::Key_Space)
        //_restart->animateClick(100);
}
void Game::keyPressed()
{

}




