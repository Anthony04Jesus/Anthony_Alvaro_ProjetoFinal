#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>


class Field : public QWidget
{
    Q_OBJECT
public:
    explicit Field(QWidget *parent = nullptr);

// QWidget interface
//protected:
//    //void keyPressEvent(QKeyEvent *event) override;

//public slots:
//    //void keyPressed(); // Field

//signals:
//    //void keyStroke(char);

private:
    QPushButton * _field[10][10];
    QGridLayout * _layout;

};


#endif // FIELD_H
