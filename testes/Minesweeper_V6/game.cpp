#include "game.h"
#include <QDebug>
#include <QKeyEvent>
#include "minecounter.h"

Game::Game(QWidget *parent): QWidget{parent}
{
    timer = new QTimer(this); // create it
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &Game::updateTime);

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

    // RESTART BUTTON
    QPixmap smileyFace("C:/Users/Aluno.FL-ELN-LSC-19/Desktop/Minesweeper_V5/icons/smiley_face.png"); // The Qt Resource System
    QIcon icon(smileyFace); // Create a QIcon from the QPixmap
    _restart = new QPushButton(); //QString::number(L)
    _restart->setMaximumSize(40,40);
    _restart->setMinimumSize(40,40);
    //_restart->setStyleSheet("border-image:url(:/icons/smiley_face.png);");
    _restart->setIcon(icon);
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
        "   background-color: #C3C3C    3; /* Slightly darker when pressed */"
        "   border: 5px solid #808080; /* Invert the 3D effect when pressed */"
        "   border-top-color: #808080;"
        "   border-left-color: #808080;"
        "   border-right-color: #A0A0A0;"
        "   border-bottom-color: #A0A0A0;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E0E0E0; /* Slightly lighter on hover */"
        "}"
    );
    connect(_restart, SIGNAL(clicked()), this, SLOT(keyPressed()));

    // LABEL BOMB COUNTER
    _counter = new MineCounter(10); //_counter->setGeometry(0,0,100,100);


    // LABEL TIME COUNTER
    _timer = new QLCDNumber();
    _timer->setSegmentStyle(QLCDNumber::Flat);
    _timer->setDigitCount(4);
    _timer->display(0);
    this->_time_count = 0;
    _timer->setStyleSheet(
        "QLCDNumber {"
        "   background-color: black;"
        "   color: red; /* Color of the segments */"
        "   border: 2px inset gray;" // Optional border
        "   border-radius: 5px;"
        "}"
    );

    // FIELD OF BUTTONS
    _field = new Field(_counter);
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
//     QWidget* topBarContainer = new QWidget(this);
//     _UI_layout = new QHBoxLayout(topBarContainer);
    _UI_layout = new QHBoxLayout();
    _UI_layout->addStretch(3000);
    _UI_layout->addWidget(_counter);
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_restart,0,Qt::AlignTop);
    _UI_layout->addStretch(10000);
    _UI_layout->addWidget(_timer);
    _UI_layout->addStretch(3000);
    //topBarContainer->setMinimumSize(300, 400);
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
    if(k == Qt::Key_Space)
        _restart->animateClick(100);
}
void Game::keyPressed()
{
    //QPushButton * button = qobject_cast<QPushButton *>(sender());
    this->updateBombs( true );
    //char value = button->text().at(0).toLatin1();
    //emit keyStroke(value);
}

void Game::GameLoop(void)
{
    while(true)
    {

    }
}
int Game::GetTime(){
    return this->_time_count++;
}
int Game::GetBombs(){
    return this->_bomb_count;
}
void Game::updateTime()
{
//    QDateTime currentTime = QDateTime::currentDateTime();
//    QString formattedTime = currentTime.toString("ss");
    //Game->_timer->setText(formattedTime); // Assuming you have a QLabel named 'label'
    _timer->display(GetTime());
}
void Game::updateBombs( bool operation )
{
    int bomb = GetBombs();
    if( operation == true)
        this->_bomb_count++;
    else
        this->_bomb_count--;

    _counter->display(_bomb_count);
}
