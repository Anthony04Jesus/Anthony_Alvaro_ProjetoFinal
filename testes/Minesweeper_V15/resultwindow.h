#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>

class QLabel;

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(const QString &resultadoTexto, QWidget *parent = nullptr);
};


#endif // RESULTWINDOW_H
