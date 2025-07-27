#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QTimer>

#include <cstdlib>

#include "field.h"

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
    QPushButton * _begginer;
    QPushButton * _medium;
    QPushButton * _advanced;
    QPushButton * _sobre;
    Field * _field;

    // LAYOUTS
    QVBoxLayout * _Layout    ;
    QGridLayout * _Field_layout;
    QHBoxLayout * _Difficulty_UI;
    QHBoxLayout * _About;

    // PARAMETERS
    int SIZE_LINE ;
    int SIZE_COLUM;
    int SIZE_BOMBS;

    static const QString pushButtonStyle;
    static const QString pushFieldStyle;
};

#endif // GAME_H
