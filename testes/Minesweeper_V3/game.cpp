#include "game.h"
#include <QDebug>
#include <QKeyEvent>

Game::Game(QWidget *parent): QWidget{parent}
{
    setWindowTitle("Minesweeper");
    QPixmap smileyFace("C:/Users/albre/Documents/Minesweeper/icons/smiley_face.png"); // Load the image
    QIcon icon(smileyFace); // Create a QIcon from the QPixmap

    // RESTART BUTTON
    _restart = new QPushButton(); //QString::number(L)
    _restart->setMaximumSize(40,40);
    _restart->setMinimumSize(40,40);
    _restart->setStyleSheet("background-color: gray; color: white; border-radius: 5px;");
    _restart->setIcon(icon); // Set the icon on the button
    //_restart->setAlignment(Qt::AlignRight);
    //QPushButton:hover { background-color: lightblue; }
    connect(_restart, SIGNAL(clicked()), this, SLOT(keyPressed()));

    // LABEL BOMB COUNTER
    _counter = new QLabel("Counter");
    _counter->setStyleSheet("font-size: 32px");
    _counter->setAlignment(Qt::AlignLeft);
    _counter->setGeometry(0,0,100,100);

    // LABEL TIME COUNTER
    _timer = new QLabel("00:00");
    _timer->setStyleSheet("font-size: 32px");
    _timer->setAlignment(Qt::AlignRight);
    _timer->setGeometry(0,0,100,100);

    // FIELD OF BUTTONS
    _field = new Field;
    connect(_field, SIGNAL(keyStroke(char)), this, SLOT(keyInput(char)));

    // SETTING LAYOUT
    _UI_layout = new QVBoxLayout();
    _UI_layout->addWidget(_counter);
    _UI_layout->addWidget(_timer);
    _UI_layout->addWidget(_field);
    _UI_layout->addWidget(_restart,0,Qt::AlignTop);
    setLayout(_UI_layout);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int k = event->key();
    if(k == Qt::Key_Space)
    {
        _timer->setStyleSheet("background: yellow");
        //_restart->animateClick(100);
    }

}
void Game::keyPressed()
{

}


