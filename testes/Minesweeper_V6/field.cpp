#include "field.h"
#include "tile.h"
#include <QDebug>
#include <QKeyEvent>

Field::Field(MineCounter * cnt, QWidget *parent): QWidget{parent}
{
    _counter = cnt;
    _layout = new QGridLayout();
    _layout->setHorizontalSpacing(0);
    _layout->setVerticalSpacing(0);
    setStyleSheet("font-size: 32px;");

    int line = 10;
    int col = 10;
    Tile * tmp;
    for(int L = 0; L < line; L++)
    {
        for(int C = 0; C < col; C++)
        {
            tmp = new Tile;
            tmp->setMaximumSize(30,30);
            tmp->setMinimumSize(30,30);
            connect(tmp, SIGNAL(clicked()), this, SLOT(keyPressed()));
            connect(tmp, SIGNAL(rightClick(bool)), this, SLOT(updateCounter(bool)));
            _layout->addWidget(tmp, L, C);
        }
    }
    setLayout(_layout);


}

void Field::keyPressed() {

//    QPushButton * button = qobject_cast<QPushButton *>(sender());
//    //qDebug() << "Key pressed !!!" << button->text() << Qt::endl;

//    char value = button->text().at(0).toLatin1();
//    int tmp = (int)value;
//    if (tmp == -9)
//        value = '/';
//    else if (value == 'x')
//        value = '*';

//    emit keyStroke(value);

}

void Field::updateCounter(bool state)
{
    if(state){
        _counter->dec();
    } else {
        _counter->inc();
    }
}

