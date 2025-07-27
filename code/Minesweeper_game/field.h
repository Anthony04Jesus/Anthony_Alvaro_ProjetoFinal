#ifndef FIELD_H
#define FIELD_H

// QTCREATOR LIB
#include <QTimer>
#include <QDialog>
#include <QWidget>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

// CLASS HEADER
#include "tile.h"

// C/C++ LIB
#include <cstdlib>

class Field : public QWidget
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit Field( int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx, QWidget *parent = nullptr);
    void endGame();
    void loadTiles();
    void plotBombs();
    void mostraResult();
    void loadBombs(int Line, int Colum);
    void openField(int line , int colum);
    void reloadField(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx);

public slots:
    void resetField();                      // RESTART BUTTON
    void updateTime();                      // TIMER UPDATE
    void setFlag(bool count_action);        // RIGHT CLICK
    void openTile(int line , int colum);    // LEFT CLICK
    void count_Right();
    void count_Left();

private:

    //OBJECTS

    Tile        * _tile     ;
    QLCDNumber  * _timer    ;
    QLCDNumber  * _counter  ;
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
    bool result;
    int totalTiles;
    int _flag_count;
    int _time_count;
    bool gameStarted;
    int clique_direito = 0;
    int clique_esquerdo = 0;
    static const QString pushButtonStyle;
    static const QString QLCDNumberStyle;
};


#endif // FIELD_H
