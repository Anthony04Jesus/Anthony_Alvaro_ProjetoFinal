#include "resultwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

ResultWindow::ResultWindow(bool resultado, int click_right, int click_left, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Resultado do Jogo");

    QLabel *msg_result = new QLabel();

    if (resultado)
    {
        msg_result->setText("Você ganhou!!");
    }
    else
    {
        msg_result->setText("Você perdeu!!");
    }

    QLabel *contclickdir = new QLabel(QString("Cliques esquerdos: %1").arg(click_left));
    QLabel *contclickesq = new QLabel(QString("Cliques direitos: %1").arg(click_right));

    msg_result->setAlignment(Qt::AlignCenter);
    contclickdir->setAlignment(Qt::AlignCenter);
    contclickesq->setAlignment(Qt::AlignCenter);

    QPushButton *fecharBtn = new QPushButton("Fechar");
    fecharBtn->setFixedSize(200, 20);
    connect(fecharBtn, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(msg_result);
    layout->addWidget(contclickdir);
    layout->addWidget(contclickesq);
    layout->addWidget(fecharBtn);
    setLayout(layout);
}
