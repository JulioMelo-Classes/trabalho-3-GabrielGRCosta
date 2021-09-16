# Projeto Davi e Gabriel

## Compilando e executando o progama (exemplo com o teste maze1)

```bash
chmod +x compile
./compile
./main data/maze1.txt
```
## Como jogar e Modos

O arquivo de entrada deve ter 3 inteiros, representando respectivamente o numero de linhas e o numero de colunas do mapa e o numero de comidas a ser gerado no jogo. Alem disso, e possivel alterar do modo padrão para o modo pacman ao adicionar o nome pacman ao lado do numero de comidas.  

## Limitações e funcionalidades não implementadas

Não conseguimos implementar a transição de mapa, assim como o random start, validação do arquivo e a pergunta com o usuário. 

De resto está tudo funcional(eu espero).

## Mapas

Foram feitos 5 mapas (um deles sendo dado pelo professor) para testarmos a cobra(o codigo).

O primeiro mapa testa como a cobra funciona/ no caso um mapa padrão , nós utilizamos ele por boa parte do codigo.
O segundo mapa foi feito para testar como a cobra funcionaria sem obstaculos internos(obviamente desconsiderando as paredes).
o  terceiro mapa é o mapa dado pelo professor e usamos ele parar validar o codigo como funcional no checkpoint 1.
o quarto mapa utiliza da mesma ideia do segundo , porém é menor e foi utilizado quando o algoritmo do backtracking estava sendo implementado para testar sua eficiência, além disso está no modo pacman.
o quinto mapa é o mapa da morte e testa a real capacidade da cobra , mostrando como ela reage quando encontra muitos obstaculos , lugares sem saidas e etc.

# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

ok

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

não implementado

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

não implementado

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

Ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

Ok
