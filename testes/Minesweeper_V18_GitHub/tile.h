#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPushButton>
#include <QString>

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
