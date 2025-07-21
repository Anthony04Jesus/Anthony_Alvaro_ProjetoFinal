# Análise orientada a objeto

Análise orientada a objetos do jogo campo minado.

## Descrição Geral do domínio do problema

A aplicação a ser desenvolvida se trata de um jogo de Campo Minado. O conteúdo do jogo é, basicamente, um mapa de botões quadrados em que estão dispostas bombas escondidas aleatoriamente debaixo de alguns deles. O objetivo do jogador é clicar em todos os espaços que não possuem minas. Para saber onde deve clicar, cada botão livre de bomba indicará a quantidade de explosivos nos 8 quadrados adjascentes. Para marcar a localização de uma possível bomba, o jogador pode adicionar uma bandeira no botão correspondente, inibindo um clique acidental. A quantidade máxima dessas bandeiras é o número de bombas dispostas no mapa.
O jogador terá 3 opções de mapa para jogar; o modo iniciante terá uma campo 10x10 com 10 bombas, o intermediário terá um 15x15 e 25 bombas e o avançado, 20x20 com 70 bombas.
Ao clicar em um botão com uma mina, o jogador recebe uma mensagem de game over e todas as bombas escondidas são reveladas. Ademais, um menu de resultados são apresentados, como a quantidade de cliques realizados, tempo do jogo, vitórias consecutivas, etc.

<img src="images/mine2.png"
     width="70%"
     style="padding: 10px">

## Diagrama de Casos de Uso

<img src="images/casos_uso.png"
     width="60%"
     style="padding: 10px">

O jogador entra na tela inicial do jogo, onde há 3 botões: novo jogo, opções e sobre (about). Ao clicar em “Novo jogo”, se abre uma janela menor com com título “Dificuldade” e 3 botões “Fácil”, “Intermediário” e “Difícil”;

<h1>Caso de uso - escolher dificuldade:</h1>

Ao selecionar a dificuldade fácil, o mapa do campo minado apresentará um grid 9x9; no intermediário, um grid 16x16 e no difícil, 30x16;

<h1>Caso de uso - Iniciar jogo:</h1>

No início do jogo, o usuário verá um layout de botões, um cronômetro zerado no canto superior direito e, no esquerdo, um contador fixo com o número máximo de flags que poderá utilizar;
Ao apertar o primeiro quadrado, o cronômetro é ativado, mostrando o tempo até que todos os botões sem bomba estarem descobertos;

<h1>Caso de uso - colocar bandeira:</h1>
 
Tendo a suspeita de alguma bomba, ele poderá marcar o quadrado com uma bandeira (flag); ao fazê-lo, o contador de flags irá subtrair da quantidade disponível, sendo ela o máximo de minas dispostas no grid; se o jogador clicar com o botão esquerdo em cima de uma bandeira já posicionada, nada acontece, já que ele presumiu que ali teria uma bomba;

<h1>Caso de uso - abrir campo:</h1>

Se algum botão clicado não tiver bombas em seus vizinhos, esse ponto não terá nenhum número e possíveis botões adjacentes a esse que estiverem sem bombas serão descobertos automaticamente através desse clique;
Ao clicar em um botão que tem bomba escondida, as demais bombas serão demonstradas no mapa, e a bomba clicada terá um fundo vermelho/destaque;
Ao mesmo tempo que o mapa mostrar todas as bombas descobertas, um menu de resultados aparecerá à direita, exibindo o tempo total decorrido, quantos cliques foram dados entre botão esquerdo e direito, estatísticas de vitoria e derrota, etc..


 
## Diagrama de Domínio do problema

<img src="images/dominio_problema.png"
     width="70%"
     style="padding: 10px">

<img src="images/diagrama_classes.png"
     width="80%"
     style="padding: 10px">

## Diagramas de sequência

<img src="images/escolhe_dif.png"
     width="70%"
     style="padding: 10px">

<img src="images/inicia_jogo.png"
     width="80%"
     style="padding: 10px">

<img src="images/abrir_campo.png"
     width="80%"
     style="padding: 10px">

<img src="images/bandeira.png"
     width="80%"
     style="padding: 10px">



<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
