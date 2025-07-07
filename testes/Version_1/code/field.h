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

    // public slots:
    //     void keyPressed();

    // signals:
    //    void keyStroke(char);

private:
    QGridLayout * _layout;

};


#endif // FIELD_H
