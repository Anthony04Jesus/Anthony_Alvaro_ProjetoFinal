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
