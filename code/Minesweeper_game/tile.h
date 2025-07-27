#ifndef TILE_H
#define TILE_H

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

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
    void plotBomb();
    void plotFlag();
    void lockButton();
    void bombExploded();

    //GET METHODS
    bool        getBomb();
    int         getLine();
    int         getColum();
    Tile_State  getState();
    int         getAdjascentBombs();

    //SET METHODS
    void setBomb();
    void setTile(int line, int colum);
    void setAdjacentBombs(int adjacentBombs);

signals:
    void rightClick(bool situac);
    void leftClick(int line, int colum);

private:
    bool        Bomb;
    int         line;
    int         colum;
    int adjascentBombs;
    Tile_State  state;
    static const QString pushButtonStyle;
    static const QString pushDisableStyle;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TILE_H
