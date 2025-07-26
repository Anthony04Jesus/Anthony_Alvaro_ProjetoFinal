# Análise orientada a objeto

Análise orientada a objetos do jogo campo minado.

## Descrição Geral do domínio do problema

A aplicação a ser desenvolvida se trata de um jogo de Campo Minado. O conteúdo do jogo é, basicamente, um mapa de botões quadrados em que estão dispostas bombas escondidas aleatoriamente debaixo de alguns deles. O objetivo do jogador é clicar em todos os espaços que não possuem minas. Para saber onde deve clicar, cada botão livre de bomba indicará a quantidade de explosivos nos 8 quadrados adjascentes. Para marcar a localização de uma possível bomba, o jogador pode adicionar uma bandeira no botão correspondente, inibindo um clique acidental. A quantidade máxima dessas bandeiras é o número de bombas dispostas no mapa.
O jogador terá 3 dificuldades de mapa para jogar; o nível iniciante terá uma campo 10x10 com 10 bombas, o médio terá um 15x15 e 25 bombas e o avançado, 20x20 com 90 bombas.
Ao clicar em um botão com uma mina, o jogador recebe uma mensagem de game over e todas as bombas escondidas são reveladas. Ademais, um menu de resultados é apresentado com a quantidade de cliques realizados e o tempo do jogo. Ao vencer, o jogador também recebe uma mensagem e seus resultados.

## Requisitos funcionais do software: 


Caso escolher dificuldade:
- Permitir seleção de dificuldade sempre que o jogador quiser;
- Gerar campo com quantidade de botões e bombas equivalentes à dificuldade desejada;
  
Caso iniciar jogo:
- Inicialmente todos os botões devem esconder seu conteúdo, sejam bombas, números ou em branco;
- No início, antes do primeiro clique, nenhuma bomba estará posicionada;
- Após o primeiro clique as bombas são alocadas nos botões, aleatoriamente;
- Reiniciar jogo quando o jogador quiser;

Caso abrir campo:
- Abrir célula ao clicar com botão esquerdo;
- Se o botão clicado possuir uma mina, em seguida serão mostradas todas as bombas que estavam escondidas e uma janela com resultados será mostrada;
- Se o botão clicado não tiver bomba, será checado nos 8 quadrados adjascentes a quantidade de minas presentes e indicará o número neste espaço do botão;
- Se não houver minas nos 8 quadrados adjascentes, ficará em branco e fará a checagem nos outros quadrados próximos;
  
Caso colocar bandeira:
- Posicionar ou retirar bandeira com botão direito;
- Ao clicar com botão esquerdo sobre uma bandeira, nada acontece, a fim de inibir a explosão de bombas por cliques acidentais;
- A quantidade de bandeiras restantes para marcar o número máximo de bombas será mostrado em um contador no canto superior esquerdo da janela;
- O contador pode ficar negativo, porém o jogador deve entender que estará posicionando mais bandeiras que o necessário;

Caso mostrar resultado:
- O sistema deve mostrar a janela de resultados automaticamente após o jogador perder ou ganhar uma partida;
- Os seguintes resultados devem ser mostrados: número de cliques esquerdos e direitos do mouse, se o jogador perdeu ou ganhou e o tempo decorrido naquela partida;
- Após fechar a janela de resultados, o jogador poderá escolher uma nova dificuldade ou iniciar um novo jogo no grid já escolhido.

## Requisitos não-funcionais do software: 
Interface:
- Os botões terão animação ao ter o mouse passado sobre eles, bem como se forem clicados;
- As bombas mostradas em um caso de game over terão um funco avermelhado, para evidenciar suas posições e as destacar no grid;
- Botões de dificuldade e os números mostrados embaixo dos botões - depois de clicados - serão coloridos.

Usabilidade:
- O sistema é simples de utilizar, já iniciando com um mapa de botões na dificuldade iniciante, pronto para o primeiro clique;
- Para mudar a dificuldade basta selecionar a opção correspondente que o sistema gerará o mapa, dispensando a criação de outras janelas ou outros fatores que atrasem a interação sistema-usuário.

Desempenho:
- Em aspectos gerais, o jogo possui rápido desempenho e não possui travas perceptíveis ao jogador.

Manutenção do sistema:
- Possui fácil manejo do código e manutenções são fáceis de realizar, tendo em vista a caracte3rística orientada a objeto presente na maior parte do código;
- O jogo permite a criação de novas dificuldades - como uma personalizável - e outras funções no futuro, como o manejo do tamanho das janelas, número de bombas por mapa - independente da dificuldade -, entre outras.

<br><br>
<div align="center">
<img src="images/mine2.png"
     width="50%"
     style="padding: 10px">
</div>

<br><br>
## Diagrama de Casos de Uso
<div align="center">
  <img src="images/casos_uso.png"
     align="center"
     width="60%"
     style="padding: 10px">
</div>

<br><br>
Esta aplicação conta com somente um ator - que é o jogador - e o sistema.
Inicialmente, o jogador entra na tela principal do jogo, onde há 5 botões (além do campo com minas): novo jogo - simbolizado por um emoji sorridente -, sobre (about), e as 3 dificuldades disponíveis - iniciante, médio e avançado. Ao clicar no emoji sorridente - novo jogo, o sistema restaura os botões e os contadores;

<h1>Caso de uso - escolher dificuldade:</h1>

3 botões estarão alocados no topo da janela, dispondo das dificuldades disponíveis para o jogo.
Ao selecionar a dificuldade fácil, o mapa do campo minado gerará um grid 10x10; no médio, um grid 15x15 e no avançado, 20x20;

<h1>Caso de uso - Iniciar jogo:</h1>

No início do jogo, o usuário verá um layout de botões, um cronômetro zerado no canto superior direito e, no esquerdo, um contador fixo com o número máximo de flags que poderá utilizar;
Ao apertar o primeiro quadrado, o cronômetro é ativado, mostrando o tempo de jogo até que todos os botões sem bomba estejam descobertos ou se o jogador tenha clicado sobre uma bomba;
Ao ganhar, perder ou se estiver no meio de uma partida e o jogador quiser gerar um novo jogo, há 3 opções: clicar na tela espaço do teclado, apertar no botão com o emoji sorrindo (ou triste - se tiver perdido a partida) ou selecionar, na parte superior da janela, qual a dificuldade deseja para a próxima partida; as duas primeiras opções levam a um novo jogo na dificuldade antes selecionada.

<h1>Caso de uso - colocar bandeira:</h1>
 
Tendo a suspeita de alguma bomba, ele poderá marcar o quadrado com uma bandeira (flag); ao fazê-lo, o contador de flags irá subtrair da quantidade disponível. A quantidade inicial mostrada no contador se refere ao número de minas dispostas no grid; se o jogador clicar com o botão esquerdo em cima de uma bandeira já posicionada, nada acontece, já que ele presumiu que ali teria uma bomba; É possível retirar bandeiras posicionadas. Ademais, o jogador pode colocar quantas bandeiras quiser, porém o contador ficará negativo, sinalizando que há mais bandeiras posicionadas que o necessário;

<h1>Caso de uso - abrir campo:</h1>

Ao clicar em um botão, o sistema checará se há bombas nos 8 quadrados adjascentes a este e indicará a quantidade .
Se o botão clicado não tiver bombas em seus vizinhos, esse ponto não terá nenhum número e possíveis botões adjacentes a este que estiverem sem bombas serão descobertos automaticamente através desse clique, indicando o número de bombas se for o caso;
Clicando em um botão que tem bomba escondida, as demais bombas serão demonstradas no mapa com imagens de bombas e fundos vermelhos, e a bomba clicada terá um ícone especial, como se explodida de fato;
Ao mesmo tempo que o mapa mostrar todas as bombas descobertas, o menu de resultados aparecerá.

<h1>Caso de uso - mostra resultado:</h1>

Ao perder ou ganhar um jogo, o sistema mostrará uma janela com os resultados da partida. Uma mensagem evidenciará se o jogador perdeu ou ganhou, além dos segundos decorridos na partida e a quantidade de cliques no mouse, tanto do botão esquerdo quanto do direito. Haverá um botão próprio para fechar esta janela.


## Diagrama de Domínio do problema
<div align="center">
<img src="images/dominio_problema.png"
     width="70%"
     style="padding: 10px">
</div> 

## Diagrama de classes
<div align="center">
<img src="images/diagrama_classes.png"
     width="100%"
     style="padding: 10px">
</div>

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
