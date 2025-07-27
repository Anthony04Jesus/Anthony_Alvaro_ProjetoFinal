#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "field.h"
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include "minecounter.h"

class Game : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Game(QWidget *parent = nullptr);
    void GameLoop(void);
    void updateTime();
    void updateBombs(bool operation);
    int GetTime();
    int GetBombs();
    //explicit QRightClickButton(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void keyPressed();
    //void TimerSlot(); // NEW slot

signals:
    void keyStroke(char);

private slots:
    //void TimerSlot(); // NEW slot //MAKE IT PUBLIC?

private:
    Field       * _field        ;
    QPushButton * _restart      ;
    MineCounter  * _counter      ;
    QLCDNumber  * _timer        ;
    QVBoxLayout * _Layout       ;
    QHBoxLayout * _UI_layout    ;
    QGridLayout * _Field_layout ;

    int _bomb_count;
    int _time_count;

};

#endif // GAME_H
