#ifndef GAME_H
#define GAME_H

#include "field.h"
#include <QWidget>
#include <cstdlib>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);


public slots:
    void LoadGame(int SIZE_LINEx, int SIZE_COLUMx, int SIZE_BOMBSx);
    void About();

signals:
    void clicked();

private:
    // OBJECTS
    Field * _field;
    QPushButton * _sobre;
    QPushButton * _medium;
    QPushButton * _advanced;
    QPushButton * _begginer;

    // LAYOUTS
    QHBoxLayout * _About;
    QVBoxLayout * _Layout    ;
    QGridLayout * _Field_layout;
    QHBoxLayout * _Difficulty_UI;

    // PARAMETERS
    int SIZE_LINE ;
    int SIZE_COLUM;
    int SIZE_BOMBS;

    static const QString pushFieldStyle;
    static const QString pushButtonStyle;
};

#endif // GAME_H
