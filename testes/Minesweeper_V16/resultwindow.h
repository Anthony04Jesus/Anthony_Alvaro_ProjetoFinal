#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include <QString>

class QLabel;

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(bool resultado, int click_right, int click_left, QWidget *parent = nullptr);
    void perdeu_Ganhou();
};


#endif // RESULTWINDOW_H
