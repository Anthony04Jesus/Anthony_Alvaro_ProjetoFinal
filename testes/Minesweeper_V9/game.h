#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
//#include <QLabel>
#include <QGridLayout>
//#include "field.h"
#include <QLCDNumber>
#include <QTimer>
//#include <QDateTime>

#include <cstdlib>
#include <time.h>

#include "tile.h"
#include "minecounter.h"


class Game : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Game( int LINE_SIZEx, int COLUM_SIZEx, int BOMB_SIZEx, QWidget *parent = nullptr);

    // TIMER
    int GetTime(void);
    void updateTime(void);

    // COUNTER
    int GetBombs(void);
    void updateBombs(bool operation);
    void loadBombs();


protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void resetGame();
    //void openField();
    //void TimerSlot(); // NEW slot

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void keyStroke(char);
    void rightClick(bool);
    void leftClick();

private slots:
    //void TimerSlot(); // NEW slot //MAKE IT PUBLIC?

private:
    // OBJECTS
    QGridLayout * _field;
    Tile * _tile;

    QPushButton * _difficulty;
    QPushButton * _restart;
    MineCounter * _counter;
    QLCDNumber  * _timer  ;

    // LAYOUTS
    QVBoxLayout * _Layout    ;
    QHBoxLayout * _UI_layout ;
    QGridLayout * _Field     ;
    QHBoxLayout * _Difficulty_UI;

    // VARIABLES
    int _bomb_count;
    int _bombs;
    int _time_count;
    bool gameStarted;

    // PARAMETERS
    int SIZE_LINE ;
    int SIZE_COLUM;
    int SIZE_BOMBS;

};

#endif // GAME_H
