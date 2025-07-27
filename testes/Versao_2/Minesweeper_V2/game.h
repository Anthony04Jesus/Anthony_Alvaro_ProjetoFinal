#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "field.h"

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
    Field       * _field;
    QPushButton * _restart;
    QLabel      * _counter;  // QTime * _timer
    QLabel      * _timer;
    QVBoxLayout * _UI_layout;

};

#endif // GAME_H
