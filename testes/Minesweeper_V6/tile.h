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
    //void keyPressEvent(QKeyEvent *event) override;

public slots:
    //void keyPressed();

signals:
    void keyStroke(char);
    void rightClick(bool);
    //void valueChanged(enum Tile_State newState);


private:
    bool        bomb;
    Tile_State  state;
    //QVector<Tile*> adjacentes;
    int         line;
    int         colum;
    bool        flagged;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // TILE_H
