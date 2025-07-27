#ifndef TILE_H
#define TILE_H

#include <QVector>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <cstdlib>

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
    void plotBomb(void);
    void plotFlag(void);
    void lockButton();
    void bombExploded();

    //GET METHODS
    bool        getBomb(void);
    int         getLine(void);
    int         getColum(void);
    Tile_State  getState(void);
    int         getAdjascentBombs(void);

    //SET METHODS
    void setBomb(void);
    void setState(Tile_State state);
    void setTile(int line, int colum);
    void setAdjacentBombs(int adjacentBombs);

signals:
    void rightClick(bool);
    void leftClick(int line, int colum);

private:
    static const QString pushButtonStyle;
    static const QString pushDisableStyle;
    int adjascentBombs;
    bool        Bomb;
    Tile_State  state;
    int         line;
    int         colum;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TILE_H
