#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(const QString &sobre_game, QWidget *parent = nullptr);
};

#endif // ABOUTWINDOW_H
