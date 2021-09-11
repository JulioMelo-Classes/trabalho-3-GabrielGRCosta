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
	Snake* cobra;
	int Altura;
	int Largura;
	int NumComidas;
	string modo;
	pair<int,int> save_food;
	std::vector<std::string> Mapa;

public:
	Level(string arquivo);
	Level(string arquivo, Snake* cobra2 );
	
	void generate_food();
	void gerar_mapa();
	pair<int,int> pfood();
	char check_pos(pair<int,int> pos);
	int get_nfood();
	bool cobra_morre();
	string get_modo();
	bool check_mode(string a);
	void imprimir_status();
};


#endif
