#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QLabel>
#include <QDialog>
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>

class QLabel;

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(bool resultado, int click_right, int click_left, int tempo, QWidget *parent = nullptr);

private:
    QVBoxLayout *layout      ;
    QPushButton *fecharBtn   ;
    QLabel      *msg_result  ;
    QLabel      *contclickdir;
    QLabel      *contclickesq;
    QLabel      *tempo_decorr;
};


#endif // RESULTWINDOW_H
