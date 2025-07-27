#include "resultwindow.h"

ResultWindow::ResultWindow(bool resultado, int click_right, int click_left, int tempo, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Resultado do Jogo");

    msg_result = new QLabel();

    if (resultado)
    {
        msg_result->setText("Você ganhou!!");
    }
    else
    {
        msg_result->setText("Você perdeu!!");
    }

    contclickdir = new QLabel(QString("Cliques esquerdos: %1").arg(click_left));
    contclickesq = new QLabel(QString("Cliques direitos: %1").arg(click_right));
    tempo_decorr = new QLabel(QString("Tempo de jogo: %1 segundos").arg(tempo));

    msg_result->setAlignment(Qt::AlignCenter);
    contclickdir->setAlignment(Qt::AlignCenter);
    contclickesq->setAlignment(Qt::AlignCenter);
    tempo_decorr->setAlignment(Qt::AlignCenter);

    fecharBtn = new QPushButton("Fechar");
    fecharBtn->setFixedSize(200, 20);
    connect(fecharBtn, &QPushButton::clicked, this, &QDialog::accept);

    layout = new QVBoxLayout;
    layout->addWidget(msg_result);
    layout->addWidget(tempo_decorr);
    layout->addWidget(contclickdir);
    layout->addWidget(contclickesq);

    layout->addWidget(fecharBtn);
    setLayout(layout);
}
