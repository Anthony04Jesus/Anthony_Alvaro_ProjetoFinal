A implementação do jogo Campo Minado se deu inteiramente no software QTCreator, visto que a implementação gráfica é direta e aberta à orientação a objetos. Abaixo os passos de implementação e as bibliotecas utilizadas:
<br>
## Configuração inicial do projeto:
- Incluímos um projeto Qt Widgets Application no Qt Creator.
O porjeto contém o .pro file com arquivos de cabeçalho (.h) e implementação (.cpp) das classes (aboutwindow.h/cpp, game.h/cpp, field.h/cpp, tile.h/cpp, resultwindow.h/cpp).
Na pasta utilizamos recursos externos (ex.: imagens como :images/Flag_icon.png) no arquivo de recursos (.qrc) para ícones e estilos. Usando o arquivo .qrc não é necessário realocar os diretórios das imagens.

## Definição das Classes:
O jogo contém cada classe com seus respectivos cabeçalhos e arquivos de implementação, definindo atributos, métodos, e sinais/slots.
Utiliza heranças de classes Qt (ex.: QDialog, QWidget, QPushButton, QLabel, etc) para criar a interface gráfica vinculada aos processos do jogo.

## Conexão de Sinais e Slots:
Conecta sinais (ex.: rightClick, leftClick) de Tile a slots em Field usando connect.
Configura ações de botões (ex.: _restart) com slots como resetField.

## Estilização e Layout:
Aplica estilos aos recursos gráficos via setStyleSheet - entre outros - para personalizar a aparência de widgets (ex.: pushButtonStyle, QLCDNumberStyle).
Usa layouts (QVBoxLayout, QHBoxLayout, QGridLayout) para organizar os widgets na interface.

## Bibliotecas Qt Utilizadas por Classe

- **AboutWindow:**<br>
Bibliotecas: QDialog, QLabel, QPushButton, QVBoxLayout. <br>
Uso: Usa QDialog como base para a janela de "About", QLabel para exibir texto centralizado, QPushButton para o botão "Close", e QVBoxLayout para organizar os widgets verticalmente.

- **Game:**<br>
Bibliotecas: QWidget, QPushButton, QHBoxLayout, QGridLayout, QVBoxLayout.<br>
Uso: Usa QWidget como base da janela principal, QPushButton para botões de dificuldade e "About", e layouts para organizar a interface (dificuldade, campo, botão "About").

- **Field:**<br>
Bibliotecas: QWidget, QPushButton, QGridLayout, QHBoxLayout, QVBoxLayout, QLCDNumber, QTimer.<br>
Uso: Usa QWidget como contêiner do campo - através da matriz de QGridLayout de botões do tipo Tile -, QPushButton para tiles via Tile, QLCDNumber para contadores de bombas e tempo, e QTimer para atualizar o tempo decorrido.

- **Tile:**<br>
Bibliotecas: QPushButton.<br>
Uso: Usa QPushButton como base para representar cada célula interativa do campo, com sinais personalizados (rightClick, leftClick) e estilos definidos por uma constante.

- **ResultWindow:** <br>
Bibliotecas: QDialog, QLabel, QPushButton, QVBoxLayout.<br>
Uso: Usa QDialog como base para a janela de resultado, QLabel para mensagens e contadores centralizados, QPushButton para o botão "Fechar", e QVBoxLayout para o layout vertical.

- **main.cpp:**<br>
Bibliotecas: QApplication.<br>
Uso: Usa QApplication para inicializar a aplicação Qt e gerenciar o loop de eventos.

## Heranças utilizadas

- **AboutWindow:**<br>
Herança: Herda de QDialog.<br>
Descrição: Usa QDialog como base para criar uma janela com informações sobre a criação do jogo, versão corrente, data e nossos nomes - desenvolvedores do jogo, permitindo interação limitada até o fechamento.

- **Game:**<br>
Herança: Herda de QWidget.<br>
Descrição: Usa QWidget como contêiner principal, configurado como uma janela fixa para exibir botões de dificuldade, o campo (Field), e o botão "About". Usando o recurso (Qt::MSWindowsFixedSizeDialogHint) não é possível alterar as dimensões na janela para evitar erros de layout.

- **Field:**<br>
Herança: Herda de QWidget.<br>
Descrição: Usa QWidget como contêiner para o campo de jogo, incluindo tiles, contadores, e o botão de reinício.

- **Tile:**<br>
Herança: Herda de QPushButton.<br>
Descrição: Usa QPushButton para criar cada célula interativa do campo, com estados (Tile_State) e sinais personalizados.

- **ResultWindow:**<br>
Herança: Herda de QDialog.<br>
Descrição: Usa QDialog para exibir o resultado do jogo em uma janela própria. Vitória ou derrota e estatísticas já comentadas são exibidas.

## Associação entre classes

- **Field e Tile:**<br>
Tipo: Composição (linha sólida com losango preenchido).<br>
Descrição: Field contém um array de Tile , representando o grid de casas. Os tiles são criados e destruídos junto com Field.







