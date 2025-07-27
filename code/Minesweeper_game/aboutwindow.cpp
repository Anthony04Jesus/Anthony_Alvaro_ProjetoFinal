#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About this game");

    label = new QLabel("Created by:\nÁlvaro L. H. Bremm\nAnthony Gabriel de Jesus\n18th version\n27/07/2025");
    label->setAlignment(Qt::AlignCenter);

    fecharBtn1 = new QPushButton("Close");
    fecharBtn1->setFixedSize(200, 20);
    connect(fecharBtn1, &QPushButton::clicked, this, &QDialog::accept);

    layout_sobre = new QVBoxLayout;
    layout_sobre->addWidget(label);
    layout_sobre->addWidget(fecharBtn1);
    setLayout(layout_sobre);
}
