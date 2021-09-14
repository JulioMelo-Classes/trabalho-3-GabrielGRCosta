#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Level.h"
#include "Snake.h"

using namespace std;

class Player{
private:
	Snake* cobra;//<! um objeto do tipo Snake
	Level* nivel;//<! um objeto do tipo Level
	vector<char> direcoes;//<! um vetor de char contendo as direções
	int score;//<! um inteiro contendo a pontuação da cobra
public:
/*! Construtor padrão que serve para inicializar objetos de seu tipo de classe.
				@param cobra um objeto da classe Snake. 
				@param nivel um objeto da classe Level.
		*/
	Player(Snake* cobra, Level* nivel);
	/*! solução criada no chp1 e serve como solução aleatoria caso o backtracking determine que não há solução.
				@return true se a posição da cobra é igual a posição da comida (ou seja se a cobra comeu a comida), false se não.
		*/
	bool find_solution();
	/*! cria o vetor paths(que é parte do algoritmo de backtracking) limpa o vetor direções, inicializa alguns atributos e cria uma variavel booleana referente a outra função.
		@return true caso o backtracking tenha achado a solução, false se não tem solução.
		*/
	bool find_solution2();
	/*! algoritmo de backtracking, realizando chamadas recursivas e dando direcões.
				@param cobrinha uma variavel do tipo Snake que assim como token ira simular os movimentos da cobra.
				@param paths um vetor de pares de inteiros passado por referência e serve para guardar os caminhos pelos quais a cobra já passou.
				@return true se acha um caminho até a comida , false se não ha solução.
		*/
	bool find_solution3(Snake cobrinha, vector <pair<int,int>>&paths);
	/*! Testa se o movimento que será executado pela cobra é valido(deve cumprir algumas condições para tal).
				@param d um char contendo a direção para onde se deseja mover.
				@param paths um vetor de pares de inteiros contendo os caminhos por onde a cobra já passou.
				@param cobra uma variavel do tipo Snake .
				@return true se o movimento pretendido é valido e false se não for.
		*/
	bool test_move(char d, vector <pair<int,int>> &paths,Snake &cobra);
	/*! Retorna o primeiro elemento do vetor de direcões.
				@return o primeiro elemento do vetor direções.
		*/
	char next_move();
	/*! confere se o vetor direções está vazio.
				@return true se estiver vazio , false se não estiver.
		*/
	bool direcoes_empty();
	/*! cria um sistema de pontuações baseado na quantidade de passos que a cobra precisou dar para alcançar a comida.
				@return um inteiro que representa a pontuação da cobra.
		*/
	int get_score();
};

#endif
