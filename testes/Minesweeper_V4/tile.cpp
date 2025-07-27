#include "tile.h"




//Tiles(const QString &text , QWidget *parent = nullptr);

Tile::Tile(QWidget * parent): QPushButton(parent)
{
    this->bomb = false;
    this->state = Unopened;
}

void Tile::addAdjacente(Tile *t)
{
    adjacentes.push_back(t);
}


//MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)


//#include <QObject>

//class Counter : public QObject
//{
//    Q_OBJECT

//public:
//    Counter() { m_value = 0; }

//    int value() const { return m_value; }

//public slots:
//    void setValue(int value);

//signals:
//    void valueChanged(int newValue);

//private:
//    int m_value;
//};
