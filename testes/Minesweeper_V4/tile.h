#ifndef TILE_H
#define TILE_H

#include <QVector>
#include <QWidget>
#include <QPushButton>

enum Tile_State
{
    Unopened,
    Opened,
    Bomb,
    Flag
};

class Tile: public QPushButton
{
    Q_OBJECT

public:
    Tile(QWidget *parent = nullptr);

    void addAdjacente(Tile* t);

//private slots:
//    button_clicked();

signals:
    //void valueChanged(enum Tile_State newState);

private:
    bool bomb;
    Tile_State state;
    QVector<Tile*> adjacentes;
};

#endif // TILE_H
