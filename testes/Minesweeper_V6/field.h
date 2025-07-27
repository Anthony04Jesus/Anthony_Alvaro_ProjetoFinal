#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "tile.h"
#include "minecounter.h"


class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(MineCounter * cnt, QWidget *parent = nullptr);

    // QWidget interface
    //protected:
    //    //void keyPressEvent(QKeyEvent *event) override;

    public slots:
       void keyPressed();
       void updateCounter(bool state);

    // signals:
    //    void keyStroke(char);

private:
    QGridLayout * _layout;
    MineCounter  * _counter;

};


#endif // FIELD_H
