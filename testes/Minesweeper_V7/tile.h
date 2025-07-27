#ifndef TILE_H
#define TILE_H

#include <QVector>
#include <QWidget>
#include <QPushButton>

#include <cstdlib>
#include <time.h>

enum Tile_State
{
    Hidden,
    Revealed,
    Flagged,
    Exploded
};

class Tile: public QPushButton
{
    Q_OBJECT

public:
    Tile(QWidget *parent = nullptr);
    void setTile();
    Tile_State getState();
    void setState(Tile_State state);

protected:
    //void keyPressEvent(QKeyEvent *event) override;

public slots:
    //void keyPressed();

signals:
    void keyStroke(char);
    void rightClick(bool);
    void leftClick();
    //void valueChanged(enum Tile_State newState);


private:
    bool        Bomb;
    Tile_State  state;
    int         adjacentMines;
    //QVector<Tile*> adjacentes;

// QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // TILE_H
