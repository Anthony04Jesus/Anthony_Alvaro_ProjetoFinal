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

// C/C++ LIB
#include <cstdlib>
//#include <time.h>

class Field : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Field( int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx, QWidget *parent = nullptr);
    void loadBombs(int Line, int Colum);
    void plotBombs(void);
    void endGame(void);
    void openFlag(int line , int colum);
    void reloadField(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx);

public slots:
    void resetField(void);                  // RESTART BUTTOM
    void updateTime(void);                  // TIMER UPDATE
    void setFlag(bool state);               // RIGHT CLICK
    void openField(int line , int colum);   // LEFT CLICK

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
    int _time_count;
    bool gameStarted;
    int totalTiles;
};


#endif // FIELD_H
