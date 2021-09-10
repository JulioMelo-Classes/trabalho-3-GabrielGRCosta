# Projeto Davi e Gabriel

## Compilando e executando o exemplo

```bash
g++ src/*.cpp -o main -I./include
./main data/maze1.txt
```
##Modos

Para jogar no modo pacman deve-se incluir no arquivo data a palavra pacman ao lado do tamanho da tabela. 

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Esse era um tópico muito simples, vou colocar 0, mas sei que vocês podem entregar isso no CP2 sem problemas.

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok!

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok!

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok!

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1

- Acho que o trabalho está bem encaminhado, embora existam alguns problemas de desenho boa parte das funções do CP1 estão OK. Sugiro que vocês tentem o CP2 mas se virem que não dará tempo implementem o CP1 100% e as funções adicionais que eu pedi pro CP2