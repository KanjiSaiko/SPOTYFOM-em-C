# SPOTYFOM-em-C
"Execução de músicas"
• O programa inicia com um arquivo de entrada de dados, o qual é o banco de dados
de músicas do acervo;
• Este arquivo conterá em sua primeira linha a quantidade de músicas no acervo;
• Na sequência, em cada linha, serão descritas as informações sobre cada título
(separados por ponto e virgula “;”);
• Cada título será transformado em um registro no programa (struct música).

O programa carregará no seu início o banco de
dados de musicas.txt (ou outro arquivo de musicas
no mesmo formato);
• Esse banco conterá uma música em cada linha, a
qual se tornará um elemento de uma lista
encadeada de structs musica ACERVO;
• Após carregar o acervo para o programa, o
programa apresentará um menu de opções;
• As funcionalidades do menu serão as
seguintes:
• Execução;
• Playlist;
• Busca;
• Impressão;
• Relatório;
• Back-up
• Sair

Busca
– Funcionalidade que permite a busca
de uma determinada música e exibe
suas informações, a busca será
efetuada por meio dos critérios:
– Código;
– Titulo;
– Artista;

Playslist
Funcionalidade que permite criar listas de
execuções das músicas conforme alguns
critérios, são eles:
• ALEATORIO [FILA]: cria uma fila de músicas de tamanho n
(definida pelo usuário) de forma randômica;
• PLAYLIST PESSOAL [PILHA]: cria uma pilha com as músicas
selecionadas do usuário;

Execução
– Funcionalidade que basicamente incrementa o atributo
execuções em uma struct música no Acervo (lista
encadeada de structs musicas do programa);
– Esta função será chamada pela Playlist, para com
base no campo código da música na TAD da Playlist
(fila ou pilha), incrementar a música original no acervo
(lista encadeada de structs), pois as músicas criadas
na Playlist serão removidas da TAD(Pilha/Fila) após a
execução da Playlist;
– Esta funcionalidade pode ser executada com o auxílio
de uma busca por seu código;

Impressão
Impressão:
– Funcionalidade que associada a busca de um título, apresenta as informações de
uma música específica ou de todas as músicas do acervo;

• Relatórios:
– funcionalidade que gera um arquivo de saída de músicas de cada Playlist
– Funcionalidade que gera um arquivo com o acervo completo, com o número de
execuções;

• Back-up:
– funcionalidade que imprime um backup do acervo atual com nomes e quantidades
de execuções atualizadas no mesmo padrão do arquivo de entrada inicial.
• Obs: O programa deverá iniciar e apresentar um menu de
opções, o qual informa ao usuário as operações permitidas
no programa. O programa ficará rodando até que a opção
do menu de SAIR seja selecionada.

MENU:
O menu se apresenta da seguinte maneira:
![Menu](https://github.com/user-attachments/assets/7c4d5917-f4ab-467a-8a4d-9a21532ced65)

O programa atualmente esta com um bug (no NCurses) em que o usuario deve teclar 3 vezes 'F1' para voltar uma tela.

Mais telas serão commitadas mais para frente

