#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "tile.h"


class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(QWidget *parent = nullptr);

    // QWidget interface
    //protected:
    //    //void keyPressEvent(QKeyEvent *event) override;

    public slots:
    void keyPressed(); // Field

    //signals:
    //    //void keyStroke(char);

   // void LoadField( int colum , int line );

private:
    //QPushButton * _field[10][10];
    //Tile * _field[10][10];
    QGridLayout * _layout;

};


#endif // FIELD_H
