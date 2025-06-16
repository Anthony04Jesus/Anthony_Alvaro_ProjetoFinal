# Análise orientada a objeto

Análise orientada a objetos do jogo campo minado.

## Descrição Geral do domínio do problema

A aplicação a ser desenvolvida se trata de um jogo de Campo Minado. O conteúdo do jogo é, basicamente, um mapa de botões quadrados em que estão dispostas bombas escondidas aleatoriamente debaixo de alguns deles. O objetivo do jogador é clicar em todos os espaços que não possuem minas. Para saber onde deve clicar, cada botão livre de bombas indicará a quantidade de explosivos nos 8 quadrados adjascentes. Para marcar a localização de uma possível bomba, o jogador pode adicionar uma bandeira no botão correspondente. A quantidade máxima dessas bandeiras é o número de bombas dispostas no mapa.
Ao clicar em um botão com uma mina, o jogador recebe uma mensagem de game over e todas as bombas escondidas são reveladas. Ademais, um menu de resultados são apresentados, como a quantidade de cliques realizados, tempo do jogo, melhor resultado, vitórias consecutivas, etc.

## Diagrama de Casos de Uso

<img src="images/casos_uso.png"
     width="45%"
     style="padding: 10px">

1 - O jogador entra na tela inicial do jogo, onde há 3 botões: novo jogo, opções e sobre (about). Ao clicar em “Novo jogo”, se abre uma janela menor com com título “Dificuldade” e 3 botões “Fácil”, “Intermediário” e “Difícil”;

Caso de uso - escolher dificuldade:

Ao selecionar a dificuldade fácil, o mapa do campo minado apresentará um grid 9x9; no intermediário, um grid 16x16 e no difícil, 30x16;

Caso de uso - Iniciar jogo:

No início do jogo, o usuário verá um layout de botões, um cronômetro zerado no canto superior direito e, no esquerdo, um contador fixo com o número máximo de flags que poderá utilizar;
Ao apertar o primeiro quadrado, o cronômetro é ativado, mostrando o tempo até que todos os botões sem bomba estarem descobertos;

Caso de uso - colocar bandeira:
 
Tendo a suspeita de alguma bomba, ele poderá marcar o quadrado com uma bandeira (flag); ao fazê-lo, o contador de flags irá subtrair da quantidade disponível, sendo ela o máximo de minas dispostas no grid; se o jogador clicar com o botão esquerdo em cima de uma bandeira já posicionada, nada acontece, já que ele presumiu que ali teria uma bomba;

Caso de uso - abrir campo:

Se algum botão clicado não tiver bombas em seus vizinhos, esse ponto não terá nenhum número e possíveis botões adjacentes a esse que estiverem sem bombas serão descobertos automaticamente através desse clique;
Ao clicar em um botão que tem bomba escondida, as demais bombas serão demonstradas no mapa, e a bomba clicada terá um fundo vermelho/destaque;
Ao mesmo tempo que o mapa mostrar todas as bombas descobertas, um menu de resultados aparecerá à direita, exibindo o tempo total decorrido, quantos cliques foram dados entre botão esquerdo e direito, estatísticas de vitoria e derrota, etc..


 
## Diagrama de Domínio do problema

<img src="images/dominio_problema.png"
     width="70%"
     style="padding: 10px">


<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
