#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "tile.h"
#include "minecounter.h"

#include <cstdlib>
#include <time.h>

class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field( int lineSize, int columSize, int bombNumber, MineCounter * cnt, QWidget *parent = nullptr);
    void resetField();
    void loadBombs(int Line, int Colum);

 // QWidget interface
    //protected:
    //    //void keyPressEvent(QKeyEvent *event) override;

public slots:
    void updateCounter(bool state);
    void openField();

// signals:
    // void keyStroke(char);

private:
    QGridLayout * _layout   ;
    MineCounter * _counter  ;
    Tile        * _tile     ;
    QPushButton * _restart  ;

    // QVBoxLayout * _Layout       ;
    // QHBoxLayout * _UI_layout    ;
    // QGridLayout * _Field_layout ;


    int SIZE_LINE;
    int SIZE_COLUM;
    int SIZE_BOMBS;


};


#endif // FIELD_H
