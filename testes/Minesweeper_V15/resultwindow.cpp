#include "resultwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

ResultWindow::ResultWindow(const QString &resultadoTexto, QWidget *parent)
    : QDialog(parent)
{

    setWindowTitle("Resultado do Jogo");

    QLabel *label = new QLabel(resultadoTexto);
    label->setAlignment(Qt::AlignCenter);

    QPushButton *fecharBtn = new QPushButton("Fechar");
    fecharBtn->setFixedSize(200, 20);
    connect(fecharBtn, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(fecharBtn);
    setLayout(layout);
}
