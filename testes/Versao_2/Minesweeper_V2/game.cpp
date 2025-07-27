#include "game.h"
#include <QDebug>
#include <QKeyEvent>

Game::Game(QWidget *parent): QWidget{parent}
{
    setWindowTitle("Minesweeper");

    _restart = new QPushButton("R"); //QString::number(L)
    connect(_restart, SIGNAL(clicked()), this, SLOT(keyPressed()));

    _counter = new QLabel("Counter");
    _counter->setStyleSheet("font-size: 32px");
    _counter->setAlignment(Qt::AlignLeft);

    _timer = new QLabel("00:00");
    _timer->setStyleSheet("font-size: 32px");
    _timer->setAlignment(Qt::AlignRight);

    _field = new Field;
    connect(_field, SIGNAL(keyStroke(char)), this, SLOT(keyInput(char)));

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
        _restart->animateClick(100);

}
void Game::keyPressed()
{

}
