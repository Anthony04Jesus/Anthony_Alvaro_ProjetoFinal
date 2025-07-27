#ifndef FIELD_H
#define FIELD_H

// QTCREATOR LIB
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QTimer>
#include <QDialog>

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
    void loadTiles();
    void loadBombs(int Line, int Colum);
    void plotBombs();
    void endGame();
    void reloadField(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx);
    void openField(int line , int colum);
    void mostraResult();

public slots:
    void resetField();                      // RESTART BUTTON
    void updateTime();                      // TIMER UPDATE
    void setFlag(bool count_action);               // RIGHT CLICK
    void openTile(int line , int colum);    // LEFT CLICK
    void count_Right();
    void count_Left();

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
    int clique_direito = 0;
    int clique_esquerdo = 0;
    bool result;
    int _flag_count;
    int _time_count;
    bool gameStarted;
    int totalTiles;
    static const QString pushButtonStyle;
    static const QString QLCDNumberStyle;
};


#endif // FIELD_H
