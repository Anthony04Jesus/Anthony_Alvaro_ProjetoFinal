#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "field.h"
#include <QLCDNumber>

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void keyPressed();

signals:
    void keyStroke(char);

private:
    Field       * _field       ;
    QPushButton * _restart     ;
    QLCDNumber  * _counter     ;  // QTime * _timer
    QLCDNumber  * _timer       ;
    QVBoxLayout * _Layout      ;
    QHBoxLayout * _UI_layout   ;
    QGridLayout * _Field_layout;

};

#endif // GAME_H
