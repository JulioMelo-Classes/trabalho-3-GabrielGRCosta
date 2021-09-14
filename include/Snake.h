#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Snake{
private:
 	pair<int,int> cabeca;//<! um par de inteiros representando as coordenadas da cabeça da cobra.
	pair<int,int> save_point;//<! um par de inteiros representando as coordenadas que a cobra spawna no mapa.
	int vida;//<! um inteiro representando a vida da cobra.
	vector <pair<int,int>> cauda;//<! um vetor de pares de inteiros representando as coordenadas de cada uma das  caudas(rabos).
	char direcao;//<! um char contendo a direção atual da cobra.
	int Comida;//<! um inteiro contendo o número de comidas pegas pela cobra.
	int score;//<! um inteiro contendo a pontuação da cobra.

public:
	/*! Construtor padrão que serve para inicializar objetos de seu tipo de classe.
				@param arquivo variavel do tipo string que contem o mapa e os dados dele
		*/
	Snake(string arquivo);
		/*! Construtor para a cobra token , a qual vai simular os movimentos da cobra.
				@param parametro variavel referenciada do tipo Snake.
		*/
	Snake(Snake* parametro);

	/*! retorna o numero de comidas pegas pela cobra.
				@return um inteiro com o numero de comidas pega pela cobra.
		*/
	int get_comida();
	/*! movimenta a cobra de acordo com a direção dada pelo argumento passado.
				@param m um char que representa direção que a cobra deve se mover.
		*/
	void move(char m);
	/*! constroi/aumenta o corpo da cobra(caso esteja no modo snaze). 
		*/
	void increase();
	/*! checa/confere se as coordenadas passadas são iguais a localização da cabeça da cobra.
				@param l um inteiro representando uma linha(x). 
				@param c um inteiro representando uma coluna(y).
				@return true se as coordenadas passadas forem iguais as da cobra, false se não.
		*/
	bool check_phead(int l, int c);
	/*! retorna as coordenadas(um par de inteiros) da cabeça da cobra.
				@return um par que representa a localização da cobra no mapa.
		*/
	pair<int,int> phead();
	/*! simula os movimentos da cobra como um token e retorna as coordenadas do token baseado na posição da cobra após o movimento.
				@param oden um char que representa a direção que pretende-se mover o token.
				@return um par que representa as coordenadas do token.
		*/
	pair<int,int> token(char oden);
	/*! retorna a direção atual da cobra em forma de um char.
				@return retorna um char que representa a direção atual da cobra.
		*/
	char get_direcao();
	/*! retorna um par que representa as coordenadas do spaw da cobra no começo da fase.
				@return um par com as coordenadas do spaw da cobra.
		*/
	pair<int,int> get_save();
	/*! retorna o número de vidas da cobra.
				@return um inteiro com o número de vidas da cobra.
		*/
	int get_vida();
	/*! checa/confere se as coordenadas passadas como parametro batem com as coordendas de alguma cauda/corpo da cobra.
				@param pos um par de inteiros que representa uma coordenada.
				@return true se a coordenada passada for igual a coordenada de alguma das caudas da cobra, false se nao.
		*/
	bool check_pbody(pair<int,int> pos);
	/*! copia o vetor de pares do corpo da cobra para ser utilizado no token.
				@param pos um vetor de pares de inteiros representando as coordenadas das caudas da cobra.
		*/
	void copiar_body(vector<pair<int,int>>* body);
	/*! restaura a cobra a sua posição original após ela morrer, diminuindo sua vida e limpando sua cauda. 
		*/
	void respawn();
	/*! seta/aumenta a quantidade de comidas pegas pela cobra dentro de seu atributo.
		*/
	void more_food();
	/*! seta/aumenta a pontuação da cobra no jogo.
		*/
	void add_score(int a);
	/*! retorna a pontuação feita pela cobra.
		@return um inteiro com a pontuação da cobra.
		*/
	int get_score();
};

#endif
