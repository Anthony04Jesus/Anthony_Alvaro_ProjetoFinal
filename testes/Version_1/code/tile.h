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

protected:

public slots:

signals:
    void keyStroke(char);


private:
    bool        bomb;
    Tile_State  state;
    int         line;
    int         colum;
};

#endif // TILE_H
