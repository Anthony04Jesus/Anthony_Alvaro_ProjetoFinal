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

private:
    QGridLayout * _layout;
};

#endif // FIELD_H
