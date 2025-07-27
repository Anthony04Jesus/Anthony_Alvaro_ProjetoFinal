#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);

private:

    QLabel *label;
    QPushButton *fecharBtn1;
    QVBoxLayout *layout_sobre;
};

#endif // ABOUTWINDOW_H
