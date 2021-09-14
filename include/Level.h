#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Snake.h"
#include <string>

using namespace std;

class Level{
private:
	Snake* cobra;//<! um objeto do tipo Snake
	int Altura;//<! um inteiro contendo o número de linhas(altura) do mapa.
	int Largura;//<! um inteiro contendo o número de colunas(largura) do mapa.
	int NumComidas;//<! um inteiro contendo o número de comidas do jogo.
	string modo;//<! uma string contendo o modo do jogo(Snaze ou pacman).
	pair<int,int> save_food;//<! um par de inteiros contendo as coordendas da comida que vão mudando ao longo do jogo(após a cobra pegar a comida).
	std::vector<std::string> Mapa;//<! um vetor de strings representando o mapa.

public:

	Level(string arquivo);
	/*! Construtor padrão que serve para inicializar objetos de seu tipo de classe.
				@param arquivo variavel do tipo string que contem o mapa e os dados dele
				@param cobra2 variavel do tipo Snake que armazena os atributos da cobra do jogo
		*/
	Level(string arquivo, Snake* cobra2 );
	
	/*! Gera a comida no mapa  
		*/
	void generate_food();

  /*! Gera o mapa do jogo  
		*/
	void gerar_mapa();

  /*! Recebe e armazena uma cordenada correspondente ao local onde a comida sera gerada
				@param um par correspondente a cordenada onde a comida sera gerada  
		*/
	pair<int,int> pfood();

	/*! Recebe uma cordenada é retorna um char correspondente a tal cordenada (de acordo com o mapa do jogo)  
				@param um par correspondente a cordenada a ser conferida
				@return um simbolo correspondente a cordenada
		*/
	char check_pos(pair<int,int> pos); 

  /*! Retorna o numero de comidas a ser gerado no mapa  
    @return numero de comidas a ser gerado 
		*/
	int get_nfood();

  /*! checa se a cobra morreu com base em sua posição atual no mapa
				@return true caso a cobra tenha morrido
				@return false caso contrario 
		*/
	bool cobra_morre();

  /*! Retorna uma string correspondente ao modo de jogo escolhido (pacman ou padrão)
				@return uma string correspondente ao modo de jogo escolhido  
		*/
	string get_modo(); 

  /*! checa o modo de jogo escolhido (pacman ou padrão)
				@return true caso o modo seja o padrão
        @return false caso o modo seja o pacman
		*/
	bool check_mode(string a);

  /*! imprime na tela os status correspondente as vidas restantes da cobra, o numero de comidas que a cobra ja "comeu" e a pontuação atual da cobra
		*/
	void imprimir_status();
};


#endif
