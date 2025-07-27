#ifndef FIELD_H
#define FIELD_H

// QTCREATOR LIB
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QTimer>

// CLASS HEADER
#include "tile.h"
#include "minecounter.h"

// C/C++ LIB
#include <cstdlib>
#include <time.h>

class Field : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Field( int SIZE_LINE, int SIZE_COLUM, int SIZE_BOMBS, QWidget *parent = nullptr);
    void loadBombs(int Line, int Colum);

    // TIMER
    int GetTime(void);
    void updateTime(void);

    // COUNTER
    int GetBombs(void);

 // QWidget interface
    //protected:
    //    //void keyPressEvent(QKeyEvent *event) override;

public slots:
    void resetField(void); // reset button
    //void openAdjacentFields(void); //
    void updateBombs(bool state);

 signals:
    void leftClick();
    void rightClick(bool);
    void exploded();

private:
    //OBJECTS
    QLCDNumber  * _counter  ;
    QLCDNumber  * _timer    ;
    Tile        * _tile     ;
    QPushButton * _restart  ;

    // LAYOUTS
    QVBoxLayout * _layout   ;
    QGridLayout * _field    ;
    QHBoxLayout * _UI_layout;

    // PARAMETERS
    int SIZE_LINE ;
    int SIZE_COLUM;
    int SIZE_BOMBS;

    // VARIABLES
    int _bomb_count;
    int _bombs;
    int _time_count;
};


#endif // FIELD_H
