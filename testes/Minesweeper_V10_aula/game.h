#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
//#include <QLabel>
#include <QGridLayout>
#include <QLCDNumber>
#include <QTimer>
//#include <QDateTime>

#include <cstdlib>
#include <time.h>

//#include "tile.h"
#include "minecounter.h"
#include "field.h"


class Game : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Game( int LINE_SIZEx, int COLUM_SIZEx, int BOMB_SIZEx, QWidget *parent = nullptr);

protected:
    //void keyPressEvent(QKeyEvent *event) override;

public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void keyStroke(char);
    void rightClick(bool);
    void leftClick();
    void clicked();

private slots:
    //void TimerSlot(); // NEW slot //MAKE IT PUBLIC?
    //void gameOver();

private:
    // OBJECTS
    //QGridLayout * _field;
    QPushButton * _difficulty;
    Field * _field;

    // LAYOUTS
    QVBoxLayout * _Layout    ;
    QHBoxLayout * _UI_layout ;
    QGridLayout * _Field_layout     ;
    QHBoxLayout * _Difficulty_UI;

    bool gameStarted;

    // PARAMETERS
    int SIZE_LINE ;
    int SIZE_COLUM;
    int SIZE_BOMBS;

};

#endif // GAME_H
