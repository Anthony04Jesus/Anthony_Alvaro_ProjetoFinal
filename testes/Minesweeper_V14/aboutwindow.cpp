#include "aboutwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

AboutWindow::AboutWindow(const QString &sobre_game, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Sobre o Jogo");

    QLabel *label = new QLabel(sobre_game);
    label->setAlignment(Qt::AlignCenter);

    QPushButton *fecharBtn1 = new QPushButton("Fechar");
    fecharBtn1->setFixedSize(200, 20);
    connect(fecharBtn1, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *layout_sobre = new QVBoxLayout;
    layout_sobre->addWidget(label);
    layout_sobre->addWidget(fecharBtn1);
    setLayout(layout_sobre);
}
