A implementação do jogo Campo Minado se deu inteiramente no software QTCreator, visto que a implementação gráfica é direta e aberta à orientação a objetos. Abaixo os passos de implementação e as bibliotecas utilizadas:
<br>
# Configuração inicial do projeto:
- Incluímos um projeto Qt Widgets Application no Qt Creator.
O porjeto contém o .pro file com arquivos de cabeçalho (.h) e implementação (.cpp) das classes (aboutwindow.h/cpp, game.h/cpp, field.h/cpp, tile.h/cpp, resultwindow.h/cpp).
Na pasta utilizamos recursos externos (ex.: imagens como :images/Flag_icon.png) no arquivo de recursos (.qrc) para ícones e estilos. Usando o arquivo .qrc não é necessário realocar os diretórios das imagens.

# Definição das Classes:
O jogo contém cada classe com seus respectivos cabeçalhos e arquivos de implementação, definindo atributos, métodos, e sinais/slots.
Utiliza heranças de classes Qt (ex.: QDialog, QWidget, QPushButton, QLabel, etc) para criar a interface gráfica vinculada aos processos do jogo.

# Conexão de Sinais e Slots:
Conecta sinais (ex.: rightClick, leftClick) de Tile a slots em Field usando connect.
Configura ações de botões (ex.: _restart) com slots como resetField.

# Estilização e Layout:
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






