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